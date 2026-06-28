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

## 2026-06-08 — SSH Keys, Docker Compose, and Local Static Site

### Goal

Continue improving the VPS self-hosting lab by:

* switching SSH from password login to key-based authentication;
* disabling password-based SSH login;
* creating the first personal static website using Docker Compose;
* keeping internal services local-only;
* adding the personal site to Uptime Kuma monitoring.

### Starting state

Before this work, the VPS already had:

* Docker installed;
* Docker Compose v1 installed;
* AmneziaWG VPN running in Docker;
* Uptime Kuma running locally on `127.0.0.1:3001`;
* fail2ban enabled for SSH;
* password-based SSH login still enabled;
* `/opt/selfhost` project structure created;
* Uptime Kuma backups already created.

Existing important containers:

```text
amnezia-awg2   -> public VPN container
uptime-kuma    -> local-only monitoring service
```

---

### SSH key authentication

A dedicated SSH key was created on the local PC for the VPS:

```bash
ssh-keygen -t ed25519 -f ~/.ssh/firstvds_ed25519 -C "firstvds-vps"
```

This created:

```text
~/.ssh/firstvds_ed25519      private key
~/.ssh/firstvds_ed25519.pub  public key
```

Important note:

* the private key must stay secret;
* the public key can be copied to the server;
* the private key was protected with a passphrase.

The public key was copied to the VPS:

```bash
ssh-copy-id -i ~/.ssh/firstvds_ed25519.pub root@<VPS_PUBLIC_IP>
```

Key-based login was tested:

```bash
ssh -i ~/.ssh/firstvds_ed25519 root@<VPS_PUBLIC_IP>
```

A local SSH config alias was added:

```sshconfig
Host firstvds
    HostName <VPS_PUBLIC_IP>
    User root
    IdentityFile ~/.ssh/firstvds_ed25519
    IdentitiesOnly yes
    SetEnv TERM=xterm-256color
```

After this, the VPS can be accessed with:

```bash
ssh firstvds
```

---

### Disabled SSH password login

Before changing SSH settings, existing SSH sessions were kept open as a safety measure.

The main SSH config was backed up:

```bash
cp /etc/ssh/sshd_config /etc/ssh/sshd_config.backup.$(date +%F-%H%M)
```

Effective SSH settings were checked with:

```bash
sshd -T | grep -E 'passwordauthentication|pubkeyauthentication|permitrootlogin|kbdinteractiveauthentication'
```

A provider SSH config file was found:

```text
/etc/ssh/sshd_config.d/40-hosting.conf
```

It contained:

```text
PermitRootLogin yes
PubkeyAuthentication yes
PasswordAuthentication yes
PermitEmptyPasswords no
```

The provider config was backed up:

```bash
cp /etc/ssh/sshd_config.d/40-hosting.conf /etc/ssh/sshd_config.d/40-hosting.conf.backup.$(date +%F-%H%M)
```

Password authentication was disabled:

```bash
sed -i 's/^PasswordAuthentication yes/PasswordAuthentication no/' /etc/ssh/sshd_config.d/40-hosting.conf
```

Configuration was checked:

```bash
sshd -t
sshd -T | grep -E 'passwordauthentication|pubkeyauthentication|permitrootlogin|kbdinteractiveauthentication'
```

Expected final state:

```text
permitrootlogin yes
pubkeyauthentication yes
passwordauthentication no
kbdinteractiveauthentication no
```

SSH was reloaded:

```bash
systemctl reload ssh
systemctl status ssh --no-pager
```

Key login was tested successfully:

```bash
ssh firstvds
```

Password login was tested and confirmed disabled:

```bash
ssh -o PubkeyAuthentication=no -o PreferredAuthentications=password root@<VPS_PUBLIC_IP>
```

Expected result:

```text
Permission denied
```

Current SSH state:

```text
SSH public port: 22/tcp
Root login: still enabled
Public key login: enabled
Password login: disabled
fail2ban: enabled for sshd
```

Future improvement:

* create a normal sudo user;
* disable direct root SSH login later.

---

### SSH key backup notes

The VPS now depends on the SSH key.

Important local files to back up before reinstalling the local OS:

```text
~/.ssh/firstvds_ed25519
~/.ssh/firstvds_ed25519.pub
~/.ssh/config
```

The private key must never be uploaded, committed to Git, or shared:

```text
~/.ssh/firstvds_ed25519
```

Recommended permissions after restoring the key:

```bash
chmod 700 ~/.ssh
chmod 600 ~/.ssh/firstvds_ed25519
chmod 644 ~/.ssh/firstvds_ed25519.pub
chmod 600 ~/.ssh/config
```

---

### Personal static website with Docker Compose

A first personal static website was created using Docker Compose.

Project path:

```text
/opt/selfhost/personal-site
```

Project structure:

```text
/opt/selfhost/personal-site/
├── html/
│   └── index.html
└── docker-compose.yml
```

The site is a simple static self-hosted lab page about:

* VPS;
* Docker;
* Uptime Kuma;
* SSH;
* backups;
* self-hosting practice.

Docker Compose file:

```yaml
version: "3.8"

services:
  personal-site:
    image: nginx:alpine
    container_name: personal-site
    restart: unless-stopped
    ports:
      - "127.0.0.1:8080:80"
    volumes:
      - ./html:/usr/share/nginx/html:ro
```

Important port binding:

```text
127.0.0.1:8080:80
```

Meaning:

```text
VPS localhost port 8080 -> container port 80
```

The site is not directly exposed to the public internet.

The site was started with:

```bash
cd /opt/selfhost/personal-site
docker-compose up -d
```

Container status was checked:

```bash
docker ps
ss -tulpn | grep 8080
```

Expected result:

```text
127.0.0.1:8080
```

---

### HTTP vs HTTPS mistake

The site was accidentally checked with HTTPS:

```bash
curl https://127.0.0.1:8080 | head
```

This returned an SSL error because nginx was serving plain HTTP, not HTTPS.

Correct command:

```bash
curl http://127.0.0.1:8080 | head
```

Lesson:

* HTTP and HTTPS are different protocols;
* a plain nginx container without TLS should be checked with `http://`.

---

### Access through SSH tunnel

The site was accessed from the local PC through SSH tunnel:

```bash
ssh -L 8080:127.0.0.1:8080 firstvds
```

Then opened locally:

```text
http://127.0.0.1:8080
```

The site opened successfully.

---

### Uptime Kuma monitoring for personal site

At first, monitoring the site from Uptime Kuma through the host address did not work.

Reason:

* `personal-site` was bound to `127.0.0.1:8080` on the VPS host;
* Uptime Kuma runs inside a Docker container;
* `127.0.0.1` and host-local bindings behave differently from inside containers.

Docker networks were checked:

```bash
docker network ls
```

Uptime Kuma was connected to the personal site Docker network:

```bash
docker network connect personal-site_default uptime-kuma
```

After that, Uptime Kuma could reach the site by container name:

```text
http://personal-site:80
```

The monitor turned green.

Lesson:

* container-to-container access can be done through Docker networks;
* Docker service/container names can be used as internal hostnames on the same Docker network;
* internal monitoring can work without exposing the service publicly.

---

### Current service state

Current containers:

```text
amnezia-awg2    -> VPN, public UDP port
uptime-kuma     -> monitoring, local 127.0.0.1:3001
personal-site   -> nginx static site, local 127.0.0.1:8080
```

Current access methods:

```bash
ssh firstvds
```

Uptime Kuma:

```bash
ssh -L 3001:127.0.0.1:3001 firstvds
```

Then open:

```text
http://127.0.0.1:3001
```

Personal site:

```bash
ssh -L 8080:127.0.0.1:8080 firstvds
```

Then open:

```text
http://127.0.0.1:8080
```

Publicly exposed services are still limited mainly to:

```text
22/tcp       SSH
VPN UDP port AmneziaWG
```

Uptime Kuma and the personal site are local-only.

---

### Useful commands for personal site

Go to project folder:

```bash
cd /opt/selfhost/personal-site
```

Show status:

```bash
docker-compose ps
```

Show logs:

```bash
docker-compose logs --tail=30
```

Restart:

```bash
docker-compose restart
```

Stop and remove container/network:

```bash
docker-compose down
```

Start again:

```bash
docker-compose up -d
```

---

### Important lessons learned

* SSH keys are safer than password login because bots cannot brute-force a disabled password login.
* SSH private keys are not tied to hardware; they are files and must be backed up securely.
* A passphrase protects the private key if the key file is stolen.
* Password-based SSH login should only be disabled after key login is fully tested.
* Provider SSH config files can affect expected SSH settings.
* `sshd -T` is useful for checking the final effective SSH configuration.
* Docker Compose makes service configuration easier to document and reproduce.
* Binding a service to `127.0.0.1` keeps it local-only.
* HTTP and HTTPS are different.
* Docker containers have their own networking.
* Container-to-container access can be done using Docker networks and container names.
* Uptime Kuma can monitor internal services without exposing them publicly.

---

### Current final state

The VPS is now in a better state:

```text
SSH:
- key-based login works
- password login disabled
- fail2ban still enabled
- root login still enabled for now

Uptime Kuma:
- local-only
- monitored and healthy
- accessed through SSH tunnel

Personal Site:
- first Docker Compose project
- nginx static site
- local-only
- accessible through SSH tunnel
- monitored by Uptime Kuma

AmneziaWG:
- still running
- not modified during this work
```

### Next possible steps

* Update `/opt/selfhost/docs/server-state.txt` with SSH key and personal-site information.
* Make a small backup of the personal-site project files.
* Put safe configs/docs into Git.
* Convert Uptime Kuma from `docker run` to Docker Compose.
* Improve backup workflow and copy backups to the local PC.
* Later configure a domain, DNS, reverse proxy, and HTTPS.
* Later create a normal sudo user and disable direct root SSH login.
* Later configure firewall carefully.

## 2026-06-17 — Git for Safe VPS Configs and Firewall Cleanup

### Goal

Continue improving the Debian 12 VPS self-hosting lab by:

* creating a separate local Git repository for safe self-hosting configs and notes;
* practicing basic Git workflow on the VPS;
* documenting the current server state;
* reviewing existing firewall rules;
* removing unused firewall allow rules;
* avoiding changes that could break SSH, Docker, or the VPN service.

### Starting state

The VPS already had several services and tools configured:

* Docker;
* Docker Compose;
* AmneziaWG VPN in Docker;
* Uptime Kuma monitoring;
* a simple static personal site served by nginx;
* SSH key-based access;
* fail2ban for SSH protection.

Important safety goal:

* preserve SSH access;
* preserve the existing VPN service;
* avoid blindly changing Docker or firewall rules.

---

### Local Git repository for safe configs

A separate local Git repository was created on the VPS:

```text
/opt/selfhost-configs
```

The repository is intended to store only safe configuration files and notes, such as:

* README files;
* documentation;
* safe Docker Compose files;
* static website files;
* service notes.

The repository should not contain:

* SSH private keys;
* passwords;
* tokens;
* `.env` files with secrets;
* service databases;
* backup archives;
* VPN private configs.

Initial repository structure:

```text
/opt/selfhost-configs/
├── README.md
├── .gitignore
├── docs/
│   ├── server-state.md
│   ├── git-notes.md
│   └── firewall-plan.md
└── services/
    └── personal-site/
        ├── docker-compose.yml
        └── html/
            └── index.html
```

The personal site files were copied into this repository as safe examples.

The actual running service files remained in their original location.

---

### Git workflow practiced

Basic Git workflow was practiced directly on the VPS:

```bash
git status
git diff
git add
git commit
git log --oneline
git commit --amend
```

Concepts reviewed:

* working tree;
* staging area;
* commit;
* local repository;
* difference between Git and GitHub;
* difference between `git commit` and `git push`.

A typo in a commit message was corrected with:

```bash
git commit --amend -m "Add basic Git workflow notes"
```

Important note:

* Git was used locally on the VPS.
* GitHub was not required for this step.
* A private GitHub repository may be created later for safe self-hosting configs.

Current plan:

* keep the main `learning` repository public;
* use a separate private repository later for safe VPS configs;
* add only cleaned learning summaries to the public `learning` repository.

---

### Firewall review

UFW was already installed and active on the VPS.

It was not installed from scratch during this session. The existing firewall configuration likely came from the VPS image, provider setup, or server management panel.

Initial UFW policy:

```text
incoming: deny
outgoing: allow
routed: deny
```

Initial allowed rules included:

* SSH;
* HTTP;
* HTTPS;
* ispmanager.

After checking active services, some allowed rules were found to be unnecessary.

---

### Firewall cleanup

Unused UFW allow rules were removed:

* HTTP;
* HTTPS;
* ispmanager.

The SSH allow rule was kept.

Final UFW allow rules:

* SSH over IPv4;
* SSH over IPv6.

The VPN service was not modified and continued working.

SSH was tested from a new terminal after the firewall cleanup and still worked.

The VPN was also tested and continued working.

---

### Docker firewall note

Docker creates its own iptables rules for published container ports.

Because of this, Docker services may not appear in the normal UFW allow list in the same way as regular host services.

The AmneziaWG VPN port continued to work through Docker-managed firewall/NAT rules.

Important safety rule:

```text
Do not blindly run commands such as `ufw reset` or `iptables -F` on a Docker-based VPS.
```

Reason:

* these commands may break container networking;
* they may break VPN access;
* they can remove important Docker-managed firewall/NAT rules.

---

### Current security state after cleanup

The server now has a cleaner firewall configuration:

* UFW is active;
* incoming traffic is denied by default;
* outgoing traffic is allowed by default;
* SSH remains allowed;
* unused HTTP, HTTPS, and ispmanager allow rules were removed;
* Uptime Kuma remains local-only;
* the personal site remains local-only;
* the VPN service continues to work.

Current public exposure is intentionally minimal:

```text
22/tcp       SSH
VPN UDP port managed by Docker / AmneziaWG
```

---

### Lessons learned

* Git is useful for tracking infrastructure notes and safe configuration files.
* GitHub is optional and should only be used after checking that no secrets are included.
* A clean `.gitignore` is important for self-hosting repositories.
* Firewall rules should be reviewed before changing them.
* Existing firewall configurations may come from a VPS image, provider setup, or control panel.
* Docker can manage its own iptables rules, so Docker and UFW must be handled carefully together.
* Before firewall changes, it is important to keep an active SSH session open and verify SSH key login.
* Minimal allow rules are safer than leaving unused ports open.
* Infrastructure changes should be documented and committed.

### Next possible steps

* Create proper backups for Uptime Kuma, personal site files, and safe configs.
* Copy important backups from the VPS to the local PC.
* Create a private GitHub repository for safe self-hosting configs.
* Review whether LLMNR on port `5355` should be disabled.
* Later configure a domain, reverse proxy, and HTTPS.
* Later convert more services to Docker Compose.

# Self-Hosted VPS Progress: Uptime Kuma Compose Migration and Telegram Alerts

## Context

This summary documents a self-hosting practice session on a Debian 12 VPS used for DevOps learning.

The server already had:

* Docker
* Docker Compose
* AmneziaWG VPN in Docker
* Uptime Kuma monitoring
* A static personal site served by nginx
* SSH key-based access
* UFW firewall
* fail2ban for SSH protection
* a private Git repository for safe VPS configs

The goal of this session was to improve service reproducibility and alerting.

## Main Goals

* Migrate Uptime Kuma from a manually created Docker container to Docker Compose.
* Preserve existing Uptime Kuma data and monitors.
* Keep Uptime Kuma local-only.
* Keep the personal site monitor working through the existing Docker network.
* Configure Telegram notifications for important monitors.
* Document and commit the safe configuration changes.

## Uptime Kuma Migration to Docker Compose

Before migration, Uptime Kuma was running as a manually created Docker container.

Important existing settings were checked first:

* Image: `louislam/uptime-kuma:1`
* Restart policy: `unless-stopped`
* Bind address: `127.0.0.1:3001`
* Data directory: `/opt/selfhost/uptime-kuma/data`
* Additional Docker network: `personal-site_default`

A fresh backup was created before changing the container startup method.

The old Uptime Kuma container was stopped and removed, but the persistent data directory was kept.

A new `docker-compose.yml` was created for Uptime Kuma, using the same data directory and local-only port binding.

The service was then started with Docker Compose.

After migration:

* Uptime Kuma started successfully.
* The container became healthy.
* Existing monitors and data were preserved.
* The service stayed local-only on `127.0.0.1:3001`.
* The connection to the `personal-site_default` Docker network was preserved.
* The personal site monitor continued working.

## Telegram Alerts

Telegram notifications were configured inside Uptime Kuma.

A Telegram bot was created using BotFather.

Uptime Kuma was configured with:

* Telegram notification type
* Bot token
* Chat ID

The bot token and chat ID were not committed to Git.

Telegram test notifications were successfully received.

Telegram alerts were enabled for:

* SSH monitor
* Personal Site monitor
* Uptime Kuma self-check

## Git and Documentation

The Uptime Kuma Compose configuration was copied into the private `selfhost-configs` repository as a safe config example.

Documentation was updated to describe:

* Uptime Kuma Compose migration
* persistent data directory
* local-only access
* Docker network connection
* Telegram alert setup
* security rules for Telegram secrets

The changes were committed and pushed to the private GitHub repository.

## Important Security Notes

The following data must not be committed to public repositories:

* Telegram bot token
* Telegram chat ID
* SSH private keys
* passwords
* VPN configs with private keys
* Uptime Kuma database/data directory
* backup archives

Uptime Kuma remains local-only and is accessed through an SSH tunnel.

## Lessons Learned

* Docker Compose makes service startup reproducible and easier to document.
* Persistent service data must be separated from disposable containers.
* A container can be safely recreated if its data directory is preserved.
* Backups should be created before service migration.
* Uptime Kuma can monitor internal Docker services through shared Docker networks.
* Telegram alerts make monitoring more useful because failures are delivered directly to the user.
* Secrets should stay inside service settings or secret storage, not in Git.
* Infrastructure changes should be documented and committed after testing.

## Current Result

After this session:

* Uptime Kuma is managed by Docker Compose.
* Uptime Kuma data was preserved.
* Uptime Kuma remains local-only.
* The personal site monitor works.
* Telegram alert notifications work.
* Safe configs and notes are stored in a private Git repository.
