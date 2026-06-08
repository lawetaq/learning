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

## 2026-06-06

### Done

* Continued CS50x and watched the Arrays lecture section from `04:27:58` to `06:53:32`.
* Practiced arrays, strings, command-line arguments, linear search, and Caesar cipher in standard C.
* Created a new CS50 practice block:

  * `cs50/practice/03-arrays-strings-search/`
* Wrote and tested several C programs:

  * `scores.c`
  * `scores_dynamic.c`
  * `string_length.c`
  * `string_length_fgets.c`
  * `uppercase.c`
  * `greet_args.c`
  * `search_score.c`
  * `search_name.c`
  * `caesar_simple.c`

### Practiced

* integer arrays
* variable-length arrays
* array indexing
* loops over arrays
* `char` arrays
* `fgets`
* `scanf`
* manual string length calculation
* command-line arguments
* linear search
* arrays of strings
* `strcmp`
* Caesar cipher logic

### Problems

* Confused the whole array with one array element.
* Tried to use `scores[n]` as if it were the last valid element.
* Used `&target` incorrectly with `char target[100]`.
* Put `Not found` inside a search loop too early.
* Forgot that `scanf("%s")` reads only one word.

### Solved / Understood

* Array indexes start at `0`.
* If an array has size `n`, the last valid index is `n - 1`.
* Strings in C are `char` arrays ending with `'\0'`.
* `fgets` can read full lines with spaces.
* Strings should be compared with `strcmp`, not `==`.
* Linear search should only print `Not found` after checking all elements.
* Caesar cipher can be implemented with character arithmetic and `% 26`.

### Next

* Practice compiler warnings with `-Wall -Wextra -Werror`.
* Improve input safety by checking the return value of `scanf`.
* Refactor selected programs into helper functions.
* Continue to the next CS50 topic.

## 2026-06-08

### Done

* Improved SSH security on the Debian 12 VPS.
* Created a dedicated SSH key for the FirstVDS VPS.
* Added a local SSH config alias: `firstvds`.
* Disabled password-based SSH login after confirming key-based login worked.
* Verified final SSH settings with `sshd -T`.
* Confirmed that password login is disabled.
* Created the first personal static website using Docker Compose.
* Bound the personal site to `127.0.0.1:8080` so it is local-only.
* Accessed the personal site through an SSH tunnel.
* Added the personal site to Uptime Kuma monitoring.
* Connected Uptime Kuma to the personal-site Docker network.
* Verified that Uptime Kuma can monitor the site internally using `http://personal-site:80`.

### Practiced

* SSH key authentication
* SSH config aliases
* disabling password-based SSH login
* checking effective SSH daemon configuration with `sshd -T`
* Docker Compose
* nginx static site container
* local-only port binding
* SSH tunnels
* Docker networks
* container-to-container communication
* Uptime Kuma internal monitoring
* HTTP vs HTTPS troubleshooting

### Problems

* Provider SSH config file kept `PasswordAuthentication yes` active.
* Initial override config did not disable password login.
* Accidentally tested a plain HTTP nginx site using HTTPS.
* Uptime Kuma could not initially monitor the local-only personal site through the host address.

### Solved / Understood

* Provider SSH config files can affect final SSH behavior.
* `sshd -T` shows the effective SSH configuration.
* Password login should only be disabled after key login is tested.
* A plain nginx container without TLS should be checked with `http://`, not `https://`.
* Services bound to `127.0.0.1` on the host are not always reachable from another container through the same address.
* Docker containers can communicate by container name when connected to the same Docker network.
* Uptime Kuma can monitor internal services without exposing them to the public internet.

### Next

* Update server documentation on the VPS.
* Back up the personal-site project files.
* Add safe personal-site configs/docs to Git later.
* Convert Uptime Kuma from `docker run` to Docker Compose.
* Improve backup workflow and copy backups off the VPS.
* Later configure domain, DNS, reverse proxy, and HTTPS.
* Later create a normal sudo user and disable direct root SSH login.

## 2026-06-08

### Done

* Tested a local self-hosted AI agent workflow using Odysseus, Docker Compose, Ollama, and local models.
* Installed and verified Docker / Docker Compose locally.
* Installed Odysseus as a local Docker Compose stack.
* Installed and tested Ollama as a systemd service.
* Tested local models:

  * `qwen2.5:7b`
  * `qwen2.5-coder:7b`
* Connected Odysseus to Ollama through `host.docker.internal:11434`.
* Checked local network exposure after binding Ollama to `0.0.0.0:11434`.
* Added a firewalld rich rule to block LAN access to Ollama.
* Created a safe Git sandbox folder:

  * `ai-agent-playground/`
* Mounted only the sandbox folder into Odysseus instead of giving access to the full home directory or full repository.
* Tested AI agent file editing.
* Compared `qwen2.5:7b` and `qwen2.5-coder:7b` for agentic file editing.
* Committed the successful sandbox edit.

### Practiced

* Docker Compose
* local self-hosted services
* Ollama local models
* systemd service checks
* local-only web UIs
* Docker-to-host connectivity
* firewall checks
* firewalld rich rules
* safe bind mounts
* Git as a safety layer for AI-generated edits
* sandboxing an AI file-editing agent

### Problems

* `qwen2.5:7b` duplicated README sections and produced messy edits.
* Ollama became reachable from the local LAN after listening on `0.0.0.0:11434`.
* Broad filesystem access for an AI agent would be risky.

### Solved / Understood

* `qwen2.5-coder:7b` performed better for code and markdown editing than the general chat model.
* Local models still require careful testing; local does not automatically mean reliable.
* Docker bind mounts should be limited to a safe sandbox first.
* Git makes it possible to review and revert AI-generated file changes.
* Firewall rules should be checked whenever a service listens on `0.0.0.0`.
* AI agents should not be given access to SSH keys, `.env` files, private notes, or the full home directory.

### Next

* Document the experiment in `projects/local-ai-agent-sandbox/`.
* Test a slightly more complex but still safe sandbox task.
* Continue using Git to review all agent-generated changes.
* Keep Odysseus and Ollama local-only.
