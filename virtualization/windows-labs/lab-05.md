# Lab Summary: Practical Work 5 — Windows 10 Environment Configuration

## Context

This practical work was completed in a Windows 10 virtual machine running in Oracle VM VirtualBox. The host system was Nobara Linux 43 KDE.

The goal of the lab was to practice basic Windows 10 administration tasks, including system configuration, privacy settings, startup management, virtual memory configuration, restore points, local users and groups, and local security policies.

The work was performed inside a Windows 10 Pro VM. A VirtualBox snapshot was created before starting the lab so the system could be safely restored if configuration changes caused problems.

## Main Tasks Completed

* Checked the VirtualBox network adapter configuration and confirmed that the VM used NAT.
* Created a pre-lab snapshot for safe rollback.
* Enabled the “This PC” desktop icon.
* Collected system information from Windows Settings.
* Ran a Windows system assessment command to inspect CPU, memory, and VM hardware information.
* Customized the Start menu and taskbar.
* Reviewed and configured startup applications.
* Adjusted Windows privacy settings.
* Configured screen timeout and power settings.
* Changed File Explorer settings to show file extensions and full paths.
* Disabled AutoPlay for removable media.
* Stopped and disabled automatic Windows Update behavior for the training VM.
* Displayed hidden and protected system files to inspect paging files.
* Checked RAM usage in Task Manager.
* Manually configured the Windows paging file size.
* Enabled System Protection and created a restore point.
* Tested System Restore and confirmed that user files were not removed.
* Created local Windows users through both GUI tools and CMD.
* Added a user to the Power Users group.
* Created local groups through both Computer Management and CMD.
* Added a user to a custom local group.
* Configured local security policies for interactive logon.
* Added a logon message shown before signing in.
* Configured password policy with a minimum password length.
* Verified that a short password was rejected.
* Configured account lockout after repeated failed login attempts.
* Verified account lockout behavior using a non-administrator account.
* Checked account policy settings using CMD.
* Reset account lockout threshold after testing.
* Created a protocol text file containing command outputs.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 Pro VM
* VirtualBox snapshots
* Windows Settings
* Control Panel
* File Explorer
* Task Manager
* Computer Management
* Local Users and Groups
* Local Security Policy
* Local Group Policy Editor
* Services management console
* Command Prompt as Administrator
* Notepad
* Shared folder / file transfer between VM and host

## Commands / Technical Actions

Safe and useful commands used during the lab:

```cmd
winsat cpu -v
```

Used to display Windows assessment information, including CPU, memory, and virtual hardware details.

```cmd
net user
```

Used to list local user accounts.

```cmd
net user <username>
```

Used to display information about a specific local user.

```cmd
net user <username> * /add
```

Used to create a new local user and enter the password interactively.

```cmd
net localgroup
```

Used to list local groups.

```cmd
net localgroup <groupname> /add
```

Used to create a new local group.

```cmd
net localgroup <groupname> <username> /add
```

Used to add a local user to a local group.

```cmd
net accounts
```

Used to display current password and account lockout policy settings.

```cmd
notepad <path_to_file>
```

Used to open the protocol text file for review.

The command output was redirected into a protocol text file using `>>`, which appends command results to an existing file instead of overwriting it.

## Problems Encountered

* Some personalization settings were unavailable because Windows inside the VM was not activated.
* The VM was running on a Linux host, so the Windows-only `winsat` command could not be executed on the host OS for comparison.
* The `winsat cpu -v` command displayed useful system information but also returned a message about missing assessment mode.
* System Restore behavior needed to be tested carefully to avoid unnecessary risk.
* Account lockout testing could potentially block access if performed on the wrong account.

## How Problems Were Solved

* Windows activation was not bypassed. No activation keys or unofficial activation tools were used. The limitation was documented honestly as part of the lab.
* The host comparison for `winsat` was handled conceptually, because `winsat` is a Windows utility and is not available on Nobara Linux.
* The `winsat` output was still useful because it showed CPU, RAM, and virtual hardware information.
* A VirtualBox snapshot was created before making major system changes.
* System Restore was tested using a safe user-created text file and visible desktop changes instead of risky changes such as modifying system time.
* Account lockout was tested only on a non-administrator account, and the lockout threshold was reset afterward.

## Skills Practiced

* Managing VirtualBox VM settings and snapshots.
* Working with Windows 10 system settings.
* Using Control Panel and modern Windows Settings.
* Managing Windows services.
* Configuring Windows Update behavior in a test VM.
* Viewing hidden and protected system files.
* Understanding Windows paging files.
* Monitoring RAM usage in Task Manager.
* Configuring virtual memory.
* Creating and using Windows restore points.
* Managing local users and groups.
* Using administrative CMD commands.
* Redirecting command output to a text file.
* Configuring local security policies.
* Testing password policy enforcement.
* Testing account lockout behavior safely.
* Documenting technical work in a structured way.

## What I Learned

This lab showed how Windows 10 workstation administration is split between several tools: Settings, Control Panel, Computer Management, Services, Local Security Policy, Group Policy Editor, and CMD.

I practiced configuring the system environment, managing local accounts, setting password and lockout rules, and checking how these policies affect user login behavior. I also learned that restore points protect system configuration but do not act as full disk backups and do not normally remove user documents.

Another important lesson was that VM-based labs should be done with snapshots before changing system policies. This makes it safer to experiment with settings that could otherwise make the system inconvenient or difficult to access.

## GitHub Notes

Recommended content to include in a GitHub learning repository:

* A short explanation of the lab goal.
* A sanitized list of Windows administration tools used.
* Safe CMD commands used for local users, groups, and account policies.
* A brief explanation of paging files and System Restore.
* Notes about password policies and account lockout testing.
* A short “problems and solutions” section.
* A note that Windows activation was not bypassed and unavailable personalization settings were documented honestly.

Content that should not be added to GitHub:

* Full academic report.
* Screenshots containing personal data.
* Full names, group numbers, teacher names, or institution-specific details.
* Passwords or real account credentials.
* Full contents of the protocol file if it includes identifying local usernames.
* VM snapshots, disk images, or large binary files.
* Any activation-related tools or unofficial workarounds.
