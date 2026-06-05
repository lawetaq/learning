# VPS Self-Hosting Lab

## Goal

Use a rented Debian VPS as a small learning server for Docker, monitoring, backups, basic security, and future self-hosted services.

This project is part of my DevOps / Infrastructure / Cloud learning path.

## Environment

### Server

* VPS
* Debian 12
* 2 vCPU
* 2 GB RAM
* 20 GB NVMe

### Existing service

* AmneziaWG VPN running in Docker
* Existing VPN container must be preserved and not modified unless specifically working on VPN maintenance

## Initial Server State

The VPS was already running a working AmneziaWG VPN service.

Initial checks showed:

* current user: `root`;
* OS: Debian GNU/Linux 12;
* Docker was already installed;
* Docker was being used by AmneziaWG;
* disk usage was low;
* RAM usage was acceptable for a small VPS.

Running Docker container:

```text
amnezia-awg2
```

Purpose:

* AmneziaWG VPN
* public UDP port for VPN access

Important rule:

* do not touch the existing VPN container, image, or Docker network unless doing planned VPN maintenance.

## Docker Basics Practice

A simple nginx test container was created to understand Docker basics.

Created directory:

```bash
/opt/selfhost/test-nginx/html
```

Started nginx container:

```bash
docker run -d \
  --name test-nginx \
  -p 8080:80 \
  -v /opt/selfhost/test-nginx/html:/usr/share/nginx/html:ro \
  nginx:alpine
```

Concepts practiced:

* Docker image vs container;
* port mapping;
* bind mounts / volumes;
* read-only mount mode with `:ro`;
* difference between data stored on the VPS and data inside a container;
* `docker ps`;
* `docker stop`;
* `docker start`;
* `docker rm`;
* external port vs internal container port.

The test container was later stopped:

```bash
docker stop test-nginx
```

This closed public port `8080/tcp`.

## Ports and Networking Notes

Important networking concepts learned:

* IP address identifies the server.
* Port identifies a specific service on the server.
* `127.0.0.1` means localhost / only accessible from the same machine or network namespace.
* `0.0.0.0` means listen on all interfaces and can often be reachable externally.
* TCP is used for reliable ordered communication such as SSH, HTTP, and HTTPS.
* UDP is used for lower-latency traffic such as VPNs, games, DNS, and calls.
* One external port cannot be used by two services at the same time for the same protocol.

Docker port mapping example:

```text
0.0.0.0:8080->80/tcp
```

Meaning:

```text
VPS port 8080 -> container port 80
```

Also learned:

* DNS maps domain names to IP addresses.
* A reverse proxy routes requests from one public entry point to internal services.
* DNS and reverse proxy are different concepts.

## Uptime Kuma Setup

Uptime Kuma was installed as the first real self-hosted monitoring service.

Created data directory:

```bash
mkdir -p /opt/selfhost/uptime-kuma/data
```

Started Uptime Kuma:

```bash
docker run -d \
  --name uptime-kuma \
  --restart unless-stopped \
  -p 3001:3001 \
  -v /opt/selfhost/uptime-kuma/data:/app/data \
  louislam/uptime-kuma:1
```

Created the admin account.

A password issue was later fixed from inside the container:

```bash
docker exec -it uptime-kuma bash
npm run reset-password
exit
docker restart uptime-kuma
```

Important lesson:

* self-hosted services often have CLI or container-level recovery options.

## Uptime Kuma Security Improvement

Initially, Uptime Kuma was publicly available on:

```text
0.0.0.0:3001
```

This was changed to local-only access for better security.

Steps:

1. Backed up Uptime Kuma data.
2. Stopped and removed the container.
3. Recreated it with local-only binding:

```bash
docker run -d \
  --name uptime-kuma \
  --restart unless-stopped \
  -p 127.0.0.1:3001:3001 \
  -v /opt/selfhost/uptime-kuma/data:/app/data \
  louislam/uptime-kuma:1
```

Confirmed with:

```bash
docker ps
ss -tulpn | grep 3001
```

Expected result:

```text
127.0.0.1:3001->3001/tcp
```

Uptime Kuma is no longer directly exposed to the public internet.

Access is done through an SSH tunnel from the local PC:

```bash
ssh -L 3001:127.0.0.1:3001 root@<VPS_PUBLIC_IP>
```

Then open locally:

```text
http://127.0.0.1:3001
```

## Uptime Kuma Monitors

Basic monitors were added:

* Uptime Kuma self-check;
* SSH check;
* external HTTP check.

Important Docker lesson:

* `127.0.0.1` inside a container refers to the container itself, not always the VPS host.
* Docker gateway can be used when a container needs to check a service on the host.

## Backups

Created backups for Uptime Kuma data.

Backup command:

```bash
mkdir -p /opt/selfhost/backups

tar -czf /opt/selfhost/backups/uptime-kuma-data-$(date +%F-%H%M).tar.gz \
  -C /opt/selfhost/uptime-kuma data
```

Restore logic learned:

1. Stop the container.
2. Move broken/current data folder aside.
3. Extract backup into `/opt/selfhost/uptime-kuma`.
4. Start the container again.
5. Verify container status.

Restore example:

```bash
docker stop uptime-kuma

mv /opt/selfhost/uptime-kuma/data /opt/selfhost/uptime-kuma/data.broken.$(date +%F-%H%M)

tar -xzf /opt/selfhost/backups/NAME_OF_BACKUP.tar.gz \
  -C /opt/selfhost/uptime-kuma

docker start uptime-kuma
docker ps
```

Important lesson:

* backups are useful only if restore logic is understood.

## `/opt/selfhost` Structure

Created a basic self-hosting project structure:

```text
/opt/selfhost/
├── backups/
├── docs/
├── personal-site/
│   └── html/
├── test-nginx/
│   └── html/
└── uptime-kuma/
    └── data/
```

Created documentation notes on the VPS:

```text
/opt/selfhost/docs/server-state.txt
/opt/selfhost/docs/restore-uptime-kuma.txt
```

These notes describe:

* current services;
* ports;
* Uptime Kuma access method;
* backup location;
* restore steps;
* current security state.

## Docker Compose

Installed Docker Compose v1 from Debian packages.

Checked version:

```bash
docker-compose version
```

Result:

```text
docker-compose version 1.29.2
```

Important notes:

* this is older Compose v1 using the `docker-compose` command;
* it is different from the newer plugin command `docker compose`;
* for current learning tasks, this is acceptable;
* existing Docker containers continued working after installation.

No containers were migrated to Compose yet.

Future plan:

* first use Compose on a safe test project;
* later migrate Uptime Kuma to Compose carefully, with backup first.

## SSH and Security

Installed and configured `fail2ban` for SSH protection.

Initial fail2ban failed because it could not find the default SSH log file:

```text
Failed during configuration: Have not found any log file for sshd jail
```

Fixed by creating systemd backend config:

```bash
cat > /etc/fail2ban/jail.d/sshd-local.conf << 'EOF'
[sshd]
enabled = true
backend = systemd
port = ssh
maxretry = 6
findtime = 10m
bantime = 10m
EOF
```

Restarted fail2ban:

```bash
systemctl restart fail2ban
```

Checked status:

```bash
fail2ban-client status
fail2ban-client status sshd
```

Confirmed:

* jail `sshd` is active;
* fail2ban is monitoring SSH;
* soft settings are used:

  * 6 attempts;
  * 10 minute window;
  * 10 minute ban.

## SSH Attack Attempts

SSH logs showed automated bot attempts.

Examples:

```text
Invalid user admin
Failed password for invalid user admin
Invalid user ubnt
```

Confirmed:

* bots tried common usernames like `admin` and `ubnt`;
* fail2ban banned at least one attacking IP;
* no successful foreign SSH logins were found.

Checked active users:

```bash
who
w
users
ss -tnp | grep sshd
```

Checked successful SSH logins:

```bash
journalctl -u ssh --since "24 hours ago" --no-pager | grep -i "accepted"
last -a | head -30
```

Result:

* only expected SSH logins were found;
* no evidence of unauthorized access was found.

## Current Final State

Current services:

```text
SSH:
- public
- 22/tcp
- protected by fail2ban
- still password-based for now

AmneziaWG VPN:
- public
- Docker container: amnezia-awg2

Uptime Kuma:
- local only
- 127.0.0.1:3001
- Docker container: uptime-kuma
- accessed through SSH tunnel

test-nginx:
- stopped

Docker Compose:
- installed as docker-compose v1.29.2

Backups:
- Uptime Kuma backups exist in /opt/selfhost/backups
```

Current public services are mainly:

```text
22/tcp       SSH
VPN UDP port AmneziaWG
```

Uptime Kuma is no longer public.

## Important Lessons Learned

* Public VPS servers are scanned by bots very quickly.
* SSH on port 22 receives automated login attempts.
* `fail2ban` helps reduce brute-force attempts.
* Docker containers can expose ports publicly or locally.
* Binding a Docker port to `127.0.0.1` is safer for admin panels.
* `127.0.0.1` inside a container is not always the same as `127.0.0.1` on the host.
* Backups are useful only if restore logic is understood.
* Compose files will make future services easier to manage and migrate.
* Databases and admin panels should not be exposed directly to the internet without a clear reason and proper protection.

## Security Notes

This repository does not include:

* real server IP address;
* passwords;
* private keys;
* VPN client configuration files;
* QR codes;
* tokens or secrets;
* real attacker IP addresses.

Only a sanitized technical summary is stored here.

## Next Steps

Planned future work:

1. Create a small personal static site.
2. Learn Docker Compose through a safe test service.
3. Convert the personal site to Compose.
4. Later migrate Uptime Kuma to Compose with a backup.
5. Improve backups and copy them off the VPS.
6. Add Telegram notifications to Uptime Kuma.
7. Configure SSH keys after PC reinstall/new SSD.
8. Consider firewall carefully.
9. Add domain, DNS, reverse proxy, and HTTPS later.
10. Postpone Gitea and Vaultwarden until Docker, backups, HTTPS, and security are better understood.
