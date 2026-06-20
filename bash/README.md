# Bash Scripting Practice

This folder contains small Bash scripts created as part of my DevOps learning path.

The goal is to practice Linux automation step by step, starting from simple scripts and gradually moving toward useful DevOps tasks such as system checks, backups, log summaries, and service monitoring.

## Current Focus

I am currently learning:

* shebang lines;
* variables;
* command substitution;
* quoting;
* script arguments;
* basic `if` conditions;
* numeric comparisons;
* input validation;
* exit codes;
* simple Linux system checks.

## Scripts

### `hello-system.sh`

A basic script that prints simple system information.

It shows:

* current user;
* current hostname;
* current directory;
* current date and time.

Practiced concepts:

* `#!/usr/bin/env bash`
* variables
* `echo`
* `date`
* `pwd`
* `whoami`
* `hostname`
* `chmod +x`
* running scripts with `bash script.sh` and `./script.sh`

### `disk-check.sh`

A small disk usage check script.

It checks root filesystem usage and compares it with a configurable limit.

Example usage:

```bash
./disk-check.sh
./disk-check.sh 85
./disk-check.sh 95
./disk-check.sh --help
```

Default limit:

```text
90%
```

Exit codes:

```text
0 = OK
1 = WARNING: disk usage is above or equal to the limit
2 = ERROR: invalid argument
```

Practiced concepts:

* command substitution
* `df`
* `tail`
* `awk`
* `tr`
* script argument `$1`
* default values
* `if`
* `[ ]`
* `[[ ]]`
* regex validation
* numeric comparison with `-ge`
* `exit 0`, `exit 1`, `exit 2`
* simple CLI help with `--help`

### `memory-check.sh`

A small memory usage check script.

It checks current RAM usage and compares it with a configurable limit.

Example usage:

```bash
./memory-check.sh
./memory-check.sh 70
./memory-check.sh 90
./memory-check.sh --help

## Notes

`chmod +x` is used to make a script executable.

Example:

```bash
chmod +x scripts/disk-check.sh
```

After that, the script can be run directly:

```bash
./scripts/disk-check.sh
```

Without execute permission, the script can still be run by explicitly passing it to Bash:

```bash
bash scripts/disk-check.sh
```

## Exit codes

* 0 = OK
* 1 = WARNING: memory usage is above or equal to the limit
* 2 = ERROR: invalid argument

## Practiced concepts:

* free
* awk
* arithmetic expansion with $(( ... ))
* script argument $1
* default values
* if
* [ ]
* [[ ]]
* regex validation
* numeric comparison with -ge
* exit 0, exit 1, exit 2
* simple CLI help with --help

### `server-status.sh`

A simple system status summary script.

It prints basic system information and runs existing check scripts.

It shows:

- hostname;
- current date and time;
- uptime;
- disk check result;
- memory check result.

Practiced concepts:

- calling one script from another script;
- command substitution;
- `hostname`;
- `date`;
- `uptime`;
- portable script paths with `dirname "$0"`;
- using a `script_dir` variable.

### `service-list.sh`

A simple service status check script.

It checks a small list of systemd services and prints whether each service is active, inactive, or missing.

Example usage:

```bash
./service-list.sh
```

Example output:

```text
OK: NetworkManager is active
WARNING: sshd is inactive
OK: docker is active
```

Practiced concepts:

* Bash arrays;
* `for` loops;
* `if`, `elif`, `else`;
* string comparison with `=`;
* checking systemd units with `systemctl cat`;
* checking service status with `systemctl is-active`;
* hiding command output with `>/dev/null 2>&1`;
* using `continue` inside a loop;
* basic service monitoring logic.

Notes:

`systemctl is-active` checks whether a service is currently active, but it does not always clearly show whether a unit exists.
For this reason, the script first checks the unit with `systemctl cat`.

Current checked services:

```text
NetworkManager
sshd
docker
```

## Next Steps

Planned scripts:

* `docker-status.sh`
* `check-ports.sh`
* `ssh-log-summary.sh`

The next goal is to create `memory-check.sh` and practice reading system memory information with `free` and `awk`.
