# AI Agent Playground

This folder is a safe sandbox for testing local AI agents with file editing.

The agent may read and edit files only inside this folder.
It must not edit files outside this directory.
It must not delete files.
It must not commit or push changes without explicit confirmation.

## Test Goals

- Test whether a local AI agent can safely read and edit files.
- Check that edits stay inside the sandbox directory.
- Review changes with Git before committing anything.
