# Local AI Agent Sandbox Experiment

## Goal

Test a local self-hosted AI agent workflow using Odysseus, Docker Compose, Ollama, and local open-weight models.

The goal was to understand how a self-hosted AI workspace works, connect it to a local model, and safely test file editing inside a Git repository without giving the agent access to the entire system.

This is a learning checkpoint / sandbox experiment, not a production AI platform.

## Environment

* Nobara Linux
* Docker
* Docker Compose
* Odysseus
* Ollama
* Local open-weight models
* Git learning repository

## Docker and Docker Compose

Docker was installed and verified successfully.

Checked:

```bash
docker --version
docker compose version
docker run hello-world
```

Docker now works without `sudo`, which makes Docker Compose workflows easier and avoids permission issues with generated files.

## Odysseus Installation

Odysseus was installed as a Docker Compose stack in a local self-hosting directory.

The stack includes:

```text
odysseus
chromadb
searxng
ntfy
```

The services were bound to localhost only:

```text
Odysseus: 127.0.0.1:7000
ChromaDB: 127.0.0.1:8100
SearXNG:  127.0.0.1:8080
ntfy:     127.0.0.1:8091
```

This means the Odysseus web UI is available only from the local machine:

```text
http://localhost:7000
```

## Ollama and Local Models

Ollama was installed and started as a systemd service.

Checked:

```bash
systemctl status ollama --no-pager
ollama list
```

Ollama detected the NVIDIA GPU/CUDA backend, so local models can use the GPU instead of CPU-only inference.

Downloaded and tested models:

```text
qwen2.5:7b
qwen2.5-coder:7b
```

Observed behavior:

* `qwen2.5:7b` worked for basic chat, but was less reliable for file-editing tasks.
* `qwen2.5-coder:7b` performed better for code, markdown, and file-editing tasks.

## Connecting Odysseus to Ollama

Odysseus was connected to the local Ollama server through Docker using:

```text
http://host.docker.internal:11434
```

Working chain:

```text
Odysseus UI
↓
Docker container
↓
host.docker.internal:11434
↓
Ollama on host
↓
Local model
```

This allows Odysseus to use local models without relying on an external API provider.

## Firewall and Local Network Safety

Ollama was temporarily configured to listen on:

```text
0.0.0.0:11434
```

This allowed the Odysseus Docker container to reach it.

After that, firewall rules were checked. The port was initially reachable from the local LAN, so a firewalld rich rule was added to block incoming LAN access to Ollama:

```bash
sudo firewall-cmd --zone=FedoraWorkstation --add-rich-rule='rule priority="-100" family="ipv4" port port="11434" protocol="tcp" reject' --permanent
sudo firewall-cmd --reload
```

The rule was verified:

```bash
sudo firewall-cmd --zone=FedoraWorkstation --list-rich-rules
```

A phone on the same Wi-Fi network could not open:

```text
http://<LOCAL_LAN_IP>:11434/api/tags
```

Final network state:

```text
Odysseus is local-only.
Ollama is reachable by the Odysseus Docker container.
Ollama is not reachable from other devices on the local network.
```

## Git Repository Sandbox

A safe sandbox folder was created inside the learning repository:

```text
ai-agent-playground/
```

Structure:

```text
ai-agent-playground/
├── README.md
├── notes/
│   └── devops-notes.md
└── tasks/
    └── first-agent-test.md
```

The initial sandbox was committed with:

```text
Add AI agent playground
```

## Docker Bind Mount for Safe Agent Access

Odysseus was not given access to the full home directory or the full repository.

Instead, only the sandbox folder was mounted into the Odysseus container using a Docker Compose override.

Example concept:

```yaml
services:
  odysseus:
    volumes:
      - /path/to/learning/ai-agent-playground:/workspace/ai-agent-playground:z
```

Inside the container, the sandbox is available as:

```text
/workspace/ai-agent-playground
```

This limits the file-editing test area and reduces the risk of accidental changes outside the sandbox.

## Agent File Editing Test

The agent was tested with a simple README editing task.

### First test: `qwen2.5:7b`

Result:

* The agent edited the file, but duplicated the requested section multiple times.
* It added too many blank lines.
* It gave a generic explanation instead of accurately explaining what went wrong.

Conclusion:

```text
qwen2.5:7b is usable for chat, but not reliable enough for agentic file editing in this setup.
```

### Second test: `qwen2.5-coder:7b`

Result:

* The agent edited only the intended README.md file.
* It added the requested section once.
* It did not create extra files.
* It did not touch files outside the sandbox.
* It completed the task faster and more cleanly.

The successful edit was committed with:

```text
Test local AI agent file editing
```

Added section:

```markdown
## Test Goals

- Test whether a local AI agent can safely read and edit files.
- Check that edits stay inside the sandbox directory.
- Review changes with Git before committing anything.
```

## Key Lessons Learned

* Docker Compose is useful for organizing multi-service self-hosted apps.
* Odysseus can run locally and connect to local Ollama models.
* Local models do not automatically mean good agent behavior; model choice matters.
* `qwen2.5-coder:7b` performed better than `qwen2.5:7b` for file-editing tasks.
* Agent access should be limited to a sandbox directory first.
* Git is important as a safety layer for reviewing and reverting AI-generated changes.
* Firewall checks are necessary when local services bind to `0.0.0.0`.
* A local AI agent should not be given broad access to the home directory, SSH keys, `.env` files, private notes, or the full repository until its behavior is better understood.

## Useful Commands

Start Odysseus:

```bash
cd ~/Projects/selfhost/odysseus
docker compose up -d
```

Stop Odysseus:

```bash
cd ~/Projects/selfhost/odysseus
docker compose down
```

Check containers:

```bash
docker compose ps
```

Check Ollama:

```bash
systemctl status ollama --no-pager
ollama list
```

Check firewall rule:

```bash
sudo firewall-cmd --zone=FedoraWorkstation --list-rich-rules
```

Check Git status:

```bash
cd ~/Projects/learning
git status
git diff
git log --oneline -5
```

## Current Status

The local AI agent sandbox setup is working.

Current working setup:

```text
Odysseus + Docker Compose + Ollama + qwen2.5-coder:7b
```

The agent has safe access only to:

```text
/workspace/ai-agent-playground
```

## Next Steps

Possible next safe tests:

1. Create a new markdown file inside the sandbox.
2. Update the existing DevOps notes file.
3. Test whether the agent can follow stricter editing instructions.
4. Review every agent change with Git before committing.
5. Avoid giving the agent access to secrets, SSH keys, `.env` files, or the full home directory.
