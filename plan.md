# Learning Plan: DevOps / Infrastructure / Cloud Path

## Main Goal

Build practical IT skills step by step and move toward a future role in DevOps, Infrastructure, Cloud Engineering, or SRE.

Long-term goal:

* get the first IT job;
* gain real experience;
* build a practical portfolio;
* save money;
* prepare for remote work or relocation in the future.

This plan is not meant to be a strict “learn everything before working” roadmap.
The goal is to build useful skills in stages, where each stage already gives practical value.

---

## Current Focus

Current main learning areas:

* CS50x / C basics;
* Git and GitHub;
* Linux basics;
* Markdown documentation;
* small programming exercises;
* building a clean learning repository.

Current repository:

```text
~/Projects/learning
```

---

## Learning Principles

## 1. Practice over passive watching

Watching courses is useful, but every topic should lead to something practical:

* a small program;
* a command practiced in terminal;
* a short note;
* a README;
* a Git commit;
* a mini-project.

## 2. Track progress in GitHub

Learning should leave a visible trail:

* notes;
* code;
* summaries;
* practice programs;
* lab summaries;
* project documentation.

## 3. Learn step by step

Do not try to learn Linux, Docker, Kubernetes, Terraform, Python, cloud, and CI/CD all at once.

The correct order for now:

```text
Programming basics → Git → Linux → Bash → Networking → Docker → VPS → CI/CD → Ansible → Monitoring → Cloud → Kubernetes
```

## 4. Prefer useful intermediate skills

The plan should create useful skills before reaching full DevOps level:

* Linux basics can help with support/sysadmin roles;
* Git and Markdown help with any technical role;
* Bash helps with automation;
* Docker helps with deployment;
* CI/CD is a direct DevOps skill;
* VPS practice helps with real server administration.

## 5. Keep the plan flexible

If DevOps stops feeling right, the learned skills can still be reused in:

* Linux administration;
* technical support;
* backend basics;
* cloud support;
* cybersecurity basics;
* infrastructure support.

---

# Stage 0 — Current Setup

## Goal

Create a clean learning environment and tracking system.

## Tasks

* Create GitHub account.
* Create learning repository.
* Set up Git locally.
* Connect GitHub via SSH.
* Create basic repository structure.
* Add `README.md`.
* Add `progress.md`.
* Add `skills.md`.
* Add `.gitignore`.
* Start tracking CS50 and C practice.
* Add sanitized virtualization lab summaries.

## Result

A working local + GitHub learning repository.

## Status

In progress / mostly completed.

---

# Stage 1 — Programming Basics and CS50

## Timeframe

Current focus: first weeks/months.

## Goal

Understand basic programming logic and become comfortable writing small programs.

## Topics

* variables;
* conditions;
* loops;
* functions;
* input and output;
* basic C syntax;
* compiling with `make`;
* running programs from terminal;
* debugging simple mistakes;
* basic strings in standard C.

## Current C Practice

Programs already practiced:

* `hello.c`;
* `name.c`;
* `compare.c`;
* `password.c`;
* `counter.c`;
* `meow.c`;
* `password_attempts.c`;
* `meow_function.c`.

## Important Concepts

* `#include`;
* `int main(void)`;
* `printf`;
* `scanf`;
* `char` arrays;
* `strcmp`;
* `for`;
* `do while`;
* `break`;
* flag variables;
* custom functions;
* difference between CS50 library helpers and standard C.

## Next Topics

* nested loops;
* simple grid printing;
* function prototypes;
* arrays;
* command-line arguments;
* memory basics;
* later: Python, SQL, web basics.

## Proof of Progress

* C source files in repository;
* CS50 progress notes;
* C practice summaries;
* Git commits.

---

# Stage 2 — Git, GitHub, and Documentation

## Goal

Use Git and GitHub confidently for learning, code, and documentation.

## Topics

* `git status`;
* `git diff`;
* `git add`;
* `git commit`;
* `git push`;
* `git pull`;
* `.gitignore`;
* commit messages;
* repository structure;
* Markdown;
* README files.

## Current Comfortable Commands

```bash
git status
git diff
git add <file>
git commit -m "message"
git push
git log --oneline
```

## Next Git Topics

* `git pull`;
* `git restore`;
* branches;
* merge conflicts;
* GitHub Issues;
* GitHub Projects.

## Proof of Progress

* clean repository structure;
* regular commits;
* Markdown summaries;
* organized learning notes.

---

# Stage 3 — Linux Basics

## Goal

Become comfortable using Linux as a technical environment.

## Topics

* terminal navigation;
* file system structure;
* file operations;
* users and groups;
* permissions;
* processes;
* packages;
* services;
* logs;
* basic troubleshooting.

## Commands to Practice

```bash
pwd
ls
cd
mkdir
touch
cp
mv
rm
cat
less
grep
find
chmod
chown
ps
top
systemctl
journalctl
```

## Practical Tasks

* create and manage files/folders from terminal;
* write Linux notes in Markdown;
* document useful commands;
* practice permissions;
* inspect running processes;
* read logs.

## Proof of Progress

* `linux/` notes;
* small command summaries;
* practical examples;
* Git commits.

---

# Stage 4 — Bash Scripting

## Goal

Learn simple automation.

## Topics

* shell scripts;
* variables;
* conditions;
* loops;
* arguments;
* exit codes;
* basic automation;
* cron basics.

## Practice Projects

* backup script;
* script that checks if a website is reachable;
* script that creates a folder structure;
* script that prints system information.

## Proof of Progress

* `.sh` scripts;
* README explaining each script;
* examples of usage.

---

# Stage 5 — Networking Fundamentals

## Goal

Understand the basics needed for servers, Docker, web apps, and DevOps.

## Topics

* IP addresses;
* ports;
* DNS;
* HTTP / HTTPS;
* TCP / UDP;
* localhost;
* NAT basics;
* SSH;
* firewalls;
* reverse proxy concept.

## Practice Tasks

* check IP address;
* use `ping`;
* use `curl`;
* inspect open ports;
* connect with SSH;
* understand how a browser reaches a website.

## Useful Commands

```bash
ip a
ping
curl
ss -tulnp
ssh
dig
traceroute
```

## Proof of Progress

* networking notes;
* small troubleshooting examples;
* terminal command practice.

---

# Stage 6 — Docker and Docker Compose

## Goal

Learn how to run applications in containers.

## Topics

* containers;
* images;
* Dockerfile;
* volumes;
* networks;
* environment variables;
* Docker Compose.

## Practice Projects

* run Nginx container;
* run a simple app in Docker;
* create a Dockerfile;
* run app + database with Docker Compose;
* learn how logs work in Docker.

## Commands

```bash
docker run
docker ps
docker stop
docker logs
docker build
docker compose up
docker compose down
```

## Proof of Progress

* Docker practice folder;
* Dockerfile examples;
* Docker Compose examples;
* README files.

---

# Stage 7 — VPS and Basic Server Administration

## Goal

Use a real remote server for practical infrastructure learning.

## Topics

* VPS basics;
* SSH access;
* users;
* firewall;
* updates;
* Nginx;
* Docker on server;
* basic security;
* backups.

## Practice Projects

* connect to VPS with SSH;
* create non-root user;
* set up SSH keys;
* configure firewall;
* run a simple service;
* deploy a small app;
* set up Nginx reverse proxy.

## Optional Project

Set up personal WireGuard VPN on VPS.

Important note:

A VPS-based VPN is useful for learning and routing traffic through your server, but it is not the same as full anonymity.

## Proof of Progress

* server setup notes;
* safe command summaries;
* deployment README;
* no secrets committed.

---

# Stage 8 — CI/CD

## Goal

Automate build and deployment.

## Topics

* GitHub Actions or GitLab CI;
* workflows;
* build steps;
* secrets;
* test steps;
* deployment steps;
* Docker image build;
* basic rollback idea.

## Practice Project

Create a pipeline:

```text
git push → CI/CD pipeline → build → deploy to server
```

## Proof of Progress

* workflow files;
* README explaining the pipeline;
* screenshots are optional, but not required;
* no secrets committed.

---

# Stage 9 — Ansible and Configuration Management

## Goal

Stop configuring servers manually.

## Topics

* inventory;
* playbooks;
* roles;
* variables;
* idempotency;
* server setup automation.

## Practice Tasks

* install packages with Ansible;
* create users;
* configure firewall;
* install Docker;
* set up Nginx;
* apply the same configuration to a fresh server.

## Proof of Progress

* Ansible playbooks;
* README with usage instructions;
* example inventory without real secrets.

---

# Stage 10 — Monitoring and Backups

## Goal

Learn how to keep services observable and recoverable.

## Topics

* logs;
* uptime checks;
* alerts;
* metrics;
* backups;
* restore testing;
* health checks.

## Tools to Try

* Uptime Kuma;
* Prometheus;
* Grafana;
* basic log inspection;
* simple backup scripts.

## Practice Tasks

* monitor a service;
* create a health check;
* configure a simple alert;
* back up project data;
* test restore process.

## Proof of Progress

* monitoring notes;
* backup scripts;
* recovery notes;
* README documentation.

---

# Stage 11 — Cloud, Terraform, and Kubernetes

## Goal

Move from basic server work to modern infrastructure.

## Topics

* cloud basics;
* Terraform;
* infrastructure as code;
* managed services;
* Kubernetes basics;
* Helm;
* Ingress;
* ConfigMaps;
* Secrets;
* observability.

## Important Rule

Do not rush into Kubernetes too early.

Recommended before Kubernetes:

* Linux basics;
* networking basics;
* Docker;
* Docker Compose;
* CI/CD;
* VPS deployment.

## Proof of Progress

* small Terraform examples;
* Kubernetes notes;
* local cluster experiments;
* deployment examples.

---

# Job Search Strategy

## First Target Roles

The first IT job does not have to be named “DevOps Engineer”.

Good entry points:

* Technical Support Engineer;
* Linux Support;
* Hosting Support;
* NOC Engineer;
* Junior System Administrator;
* Junior Infrastructure Engineer;
* DevOps Intern;
* Cloud Support Associate.

## When to Start Applying

Start looking casually after:

* Git/GitHub basics;
* Linux basics;
* Bash basics;
* Docker basics;
* one or two practical projects.

More serious applications after:

* Docker Compose project;
* basic VPS deployment;
* clear GitHub repository;
* English README files;
* some CI/CD practice.

## Portfolio Direction

The portfolio should show:

* practical work;
* clean documentation;
* learning consistency;
* real commands and code;
* no sensitive data;
* no messy screenshots;
* no academic reports with personal information.

---

# Relocation Strategy

## Main Idea

Do not relocate without money, skills, or a realistic income source.

Better path:

```text
learn → first IT job → experience → savings → remote/relocation opportunities
```

## Long-Term Direction

After gaining experience:

* search for international remote roles;
* build English CV;
* improve GitHub portfolio;
* prepare LinkedIn;
* research countries and visa options;
* save a financial buffer;
* consider relocation with stable income.

## Important Personal Requirement

The goal is not just to leave, but to live safely and sustainably:

* rent a good apartment;
* support myself;
* potentially support girlfriend and dog;
* have enough income to visit family when possible.

---

# Weekly Learning Routine

## Normal Week

Suggested rhythm:

* CS50 / programming: 3–4 sessions;
* GitHub notes and commits: 2–3 times per week;
* Linux/DevOps practice: 2 sessions;
* review and cleanup: 1 session.

## Simple Weekly Review

At the end of each week, write:

```md
## Weekly Review — YYYY-MM-DD

### Completed

- ...

### Practiced

- ...

### Problems

- ...

### What I learned

- ...

### Next week

- ...
```

## Bad Week / Low Energy Mode

If motivation or mental state is bad:

Minimum task:

* open repository;
* read previous progress;
* write one small note;
* fix one typo;
* watch 10 minutes of CS50;
* do one tiny command practice.

The goal is not perfection.
The goal is to avoid losing the thread completely.

---

# Repository Rules

## Add to Git

Good files to commit:

* `.md` notes;
* `.c` source files;
* `.sh` scripts;
* README files;
* sanitized lab summaries;
* Dockerfiles;
* safe config examples.

## Do Not Add to Git

Never commit:

* passwords;
* tokens;
* private SSH keys;
* `.env` with secrets;
* personal documents;
* screenshots with private data;
* compiled binaries;
* temporary files;
* real server credentials.

## Basic Git Workflow

```bash
git status
git diff
git add <file>
git commit -m "Clear commit message"
git push
```

Use this often.

---

# Current Immediate Next Steps

## Programming / CS50

* Continue CS50 from current timestamp.
* Practice nested loops.
* Write small programs with `#`.
* Learn function prototypes.
* Continue saving source files and summaries.

## Repository

* Keep `cs50/progress.md` updated.
* Keep `cs50/c-practice-summary.md` updated.
* Add new `.c` files when they are useful.
* Keep README files clean.

## DevOps Track

After getting more comfortable with C basics:

* start Linux notes;
* practice terminal commands systematically;
* write first Bash script;
* prepare for Docker basics later.

---

# Current Status Summary

I am currently in the early foundation stage.

Already started:

* GitHub repository;
* Git basics;
* Markdown documentation;
* CS50x;
* C practice;
* virtualization lab summaries.

Next major milestone:

```text
Finish CS50 C basics → start systematic Linux + Bash practice → move toward Docker and VPS.
```
