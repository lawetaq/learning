# Progress Log

## 2026-05-28

### Done
- Created GitHub account
- Created devops-learning repository

### Practiced
- Basic GitHub repository setup

### Problems
- None yet

### Next
- Install and configure Git locally
- Learn basic Git commands
- Add first CS50 notes

## 2026-05-28

### Done
- Set up GitHub account
- Created learning repository
- Generated SSH key
- Connected local PC to GitHub via SSH
- Cloned repository to local machine

### Next
- Practice basic Git workflow: edit, add, commit, push

## 2026-06-02

### Done

- Continued CS50 C practice.
- Practiced loops, nested loops, helper functions, and simple shape drawing.
- Wrote and tested several C programs:
  - `column.c`
  - `row.c`
  - `square.c`
  - `square_function.c`
  - `rectangle.c`
  - `rectangle_function.c`
  - `mario_stairs.c`
  - `better_mario_stairs.c`

### Practiced

- `for` loops
- `do while` loops
- nested loops
- function parameters
- simple input validation
- character input with `scanf(" %c", &dir)`
- logical operators `||` and `&&`

### Problems

- Confused incorrect OR logic like `dir == 'l' || 'L'`.
- Observed that `scanf("%i", &value)` can behave badly when letters are entered instead of numbers.

### Solved / Understood

- Correct OR logic requires repeating the full comparison: `dir == 'l' || dir == 'L'`.
- A right staircase uses both spaces and hashes:
  - `spaces = height - row - 1`
  - `hashes = row + 1`
- Functions do not automatically see variables from `main`; values must be passed as parameters.

### Next

- Practice a full CS50-style Mario pyramid.
- Add height validation from `1` to `8`.
- Learn function prototypes.
- Continue toward arrays and strings.

## 2026-06-04

### Done

- Set up the first self-hosted VPN on a Debian 12 VPS.
- Practiced SSH access and basic VPS administration.
- Tried manual Xray + VLESS + Reality deployment.
- Switched to AmneziaVPN after client-side routing issues.
- Successfully connected Linux desktop and iPhone to the VPN.

### Practiced

- VPS management
- SSH
- VPN deployment
- troubleshooting client-side routing
- comparing manual and automated deployment approaches

### Next

- Document the project in `projects/self-hosted-vpn/`.
- Later learn more about WireGuard, routing, firewall rules, and basic VPS hardening.

## 2026-06-05

### Done

* Continued working with the first Debian 12 VPS as a self-hosting and DevOps learning server.
* Preserved the existing AmneziaWG VPN container.
* Practiced Docker basics with a temporary nginx container.
* Installed and configured Uptime Kuma as the first real self-hosted monitoring service.
* Moved Uptime Kuma from public access to local-only access on `127.0.0.1:3001`.
* Set up SSH tunnel access for Uptime Kuma.
* Created Uptime Kuma data backups and documented restore logic.
* Created `/opt/selfhost` directory structure for future self-hosted services.
* Installed Docker Compose v1 from Debian packages.
* Installed and configured `fail2ban` for SSH protection.
* Checked SSH logs and confirmed automated bot login attempts.
* Verified that no unauthorized SSH logins were found.

### Practiced

* VPS administration
* SSH
* Docker containers
* Docker port mapping
* bind mounts
* local-only port binding
* SSH tunnels
* Uptime Kuma setup
* container recovery commands
* backup and restore logic
* Docker Compose basics
* fail2ban configuration
* SSH log inspection
* basic server security thinking

### Problems

* Uptime Kuma password issue required reset from inside the container.
* Uptime Kuma was initially exposed publicly on port `3001`.
* `fail2ban` initially failed because it could not find the default SSH log file.
* SSH logs showed automated bot login attempts.

### Solved / Understood

* Uptime Kuma password can be reset using container CLI recovery tools.
* Admin panels should not be exposed directly to the public internet unless there is a clear reason and proper protection.
* Docker ports can be bound to `127.0.0.1` to make a service local-only.
* SSH tunnels can be used to access local-only services securely.
* `fail2ban` can use the `systemd` backend when default log files are unavailable.
* Public VPS servers are scanned by bots very quickly.
* `127.0.0.1` inside a container is not always the same as `127.0.0.1` on the host.

### Next

* Add sanitized documentation to `projects/vps-selfhost-lab/`.
* Create a small personal static site.
* Learn Docker Compose with a safe test service.
* Improve backups and copy them off the VPS later.
* Add Uptime Kuma notifications.
* Configure SSH keys after PC reinstall/new SSD.
* Later add domain, DNS, reverse proxy, and HTTPS.
