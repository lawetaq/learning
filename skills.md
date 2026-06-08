# Skills Tracker

## Level scale

| Level | Meaning |
|---:|---|
| 0 | Not started |
| 1 | Understand the basic idea |
| 2 | Can do it with notes or examples |
| 3 | Can do it mostly independently |
| 4 | Can explain it and troubleshoot common issues |

## Skills

| Category | Skill | Level | Proof | Next step |
|---|---|---:|---|---|
| Git | GitHub basics | 1 | Created repository | Learn Git locally |
| Git | Git basic workflow | 3 | Regularly used `status`, `diff`, `add`, `commit`, and `push` | Practice `pull` and `restore` |
| Git | Git SSH authentication | 2 | Connected local PC to GitHub using SSH key | Use SSH workflow regularly |
| Documentation | Markdown basics | 2 | Created README, progress, and skills files | Keep writing notes |
| Linux | Linux basics | 1 | Previous Linux practice | Systematize notes |
| Bash | Bash scripting | 0 | — | Write first script |
| CS50 / C | CS50 basics | 2 | Watched intro, Scratch, and early C section | Continue C section |
| CS50 / C | C basics | 2 | Wrote and tested small C programs with variables, input, conditions, loops, and functions | Practice arrays and strings |
| CS50 / C | C loops | 2 | Created counter, meow, column, row, square, rectangle, and stairs programs | Practice nested loops more |
| CS50 / C | C functions | 2 | Used helper functions like `print_row`, `print_left_stairs`, and `print_right_stairs` | Learn function prototypes |
| CS50 / C | CS50 Mario pyramid | 2 | Built `mario_pyramid.c` using nested loops, spaces, hashes, and height validation | Refactor using helper functions |
| CS50 / C | C input validation | 2 | Used `do while` to validate height from `1` to `8` and direction input | Learn safer `scanf` handling |
| CS50 / C | Nested loops | 2 | Built square, rectangle, stairs, and CS50-style Mario pyramid | Practice more complex patterns |
| CS50 / C | C arrays | 2 | Wrote `scores.c` and `scores_dynamic.c` using fixed-size and variable-length arrays | Practice arrays with helper functions |
| CS50 / C | C strings | 2 | Wrote string length and uppercase programs using `char` arrays and `fgets` | Continue deeper string handling |
| CS50 / C | Command-line arguments | 1 | Wrote `greet_args.c` using `argc` and `argv` | Practice more CLI-style programs |
| CS50 / C | Linear search | 2 | Wrote `search_score.c` and `search_name.c` | Compare with binary search later |
| CS50 / C | Caesar cipher | 2 | Built `caesar_simple.c` with character arithmetic and `% 26` | Refactor and improve input handling |
| Networking | SSH tunneling | 2 | Accessed Uptime Kuma and personal site through local SSH tunnels | Use tunnels for internal admin services |
| Networking | VPN troubleshooting | 1 | Tested VLESS/Reality, Hiddify, Nekoray, and AmneziaVPN routing behavior | Study routing, TUN mode, and firewall basics |
| Infrastructure | VPS basics               |     2 | Managed a Debian 12 VPS via SSH and documented server state            | Configure SSH keys and basic hardening       |
| Infrastructure | Self-hosting basics      |     2 | Created `/opt/selfhost` structure and deployed first services          | Add personal static site                     |
| Docker         | Docker basics            |     2 | Ran nginx and Uptime Kuma containers with port mapping and bind mounts | Learn Docker Compose through a test service  |
| Docker         | Docker networking basics |     1 | Practiced public and local-only port bindings                          | Study Docker networks and gateway behavior   |
| Docker         | Docker Compose basics | 2 | Created first Compose project for a local-only nginx static site | Convert Uptime Kuma to Compose later |
 Docker | Docker networks | 1 | Connected Uptime Kuma to the personal-site Docker network for internal monitoring | Study Docker network types |
| Monitoring     | Uptime Kuma              |     2 | Deployed Uptime Kuma and added basic monitors                          | Add notifications and monitor more services  |
| Security       | SSH security basics      |     1 | Installed fail2ban and checked SSH logs for bot attempts               | Configure SSH keys and review firewall later |
| Backups        | Basic service backups    |     1 | Created Uptime Kuma tar backups and documented restore logic           | Test restore and copy backups off-server     |
| Infrastructure | SSH key authentication | 2 | Created a dedicated SSH key, configured SSH alias, and logged into VPS using the key | Back up key securely before OS reinstall |
| Security | SSH password login hardening | 2 | Disabled password-based SSH login and verified it with `sshd -T` and forced password test | Create sudo user and later disable direct root login |
| Monitoring | Internal service monitoring | 2 | Monitored local-only personal site from Uptime Kuma using container name | Add notifications later |
| Web | Static site hosting basics | 1 | Served a simple static page with nginx in Docker Compose | Add reverse proxy, domain, and HTTPS later |
