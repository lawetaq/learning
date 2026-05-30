# Lab Summary: Practical Work 6 — Windows Registry

## Context

This practical work was completed in a Windows 10 virtual machine running in Oracle VM VirtualBox. The host system was Nobara Linux 43 KDE.

The goal of the lab was to explore the Windows Registry, understand its main branches, practice safe registry navigation, export selected registry keys, restore registry data from exported `.reg` files, create simple file associations, inspect user-specific settings, and review network-related registry entries.

Before starting the registry tasks, a VirtualBox snapshot was created to provide a safe rollback point in case incorrect registry changes caused problems.

## Main Tasks Completed

* Created a VirtualBox snapshot before starting the lab.
* Opened Registry Editor and reviewed the main registry branches.
* Located hardware-related registry information, including display/monitor and processor-related keys.
* Viewed installed font information in the registry.
* Used Registry Editor search to find entries related to Paint.
* Exported the current user environment settings to a `.reg` file.
* Opened the exported registry file as text without importing it.
* Deleted the `TMP` environment value and restored it by importing the previously exported `.reg` file.
* Created a temporary `.xtt` file association so that `.xtt` files opened as text files.
* Verified that the custom `.xtt` file opened in Notepad.
* Removed the temporary `.xtt` registry association after testing.
* Exported multiple registry sections related to CPU information, Internet Explorer settings, hive list information, hardware profile configuration, HTML file actions, Winlogon, network drives, and shared resources.
* Added a context menu command for unknown file types to open them in Notepad.
* Created an unknown file type and verified that the new context menu command worked.
* Compared the current user SID in `HKEY_USERS` with `HKEY_CURRENT_USER`.
* Checked Internet Explorer user registry settings and confirmed that no typed URL history was present.
* Checked persistent network drive information in the registry.
* Checked local shared resource information in the registry.
* Copied exported registry files to a network/shared location.
* Renamed `.reg` files to `.txt` to prevent accidental registry import.
* Removed local `.reg` files after saving converted `.txt` versions.
* Removed the Registry Editor shortcut created for the lab.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 virtual machine
* VirtualBox snapshots
* Windows Registry Editor (`regedit`)
* Windows File Explorer
* Notepad
* Command Prompt
* Shared folder / mapped network drive
* Screenshot tool

## Commands / Technical Actions

Safe commands and technical actions used during the lab:

```bat
ren *.reg *.txt
```

This command was used in the folder containing exported registry files to rename all `.reg` files to `.txt`. This reduced the risk of accidentally importing registry data by double-clicking a `.reg` file.

Other important technical actions:

* Created a snapshot before editing the registry.
* Exported selected registry branches instead of exporting the full registry.
* Opened `.reg` files with the `Edit` option rather than double-clicking them.
* Restored a deleted environment value using an exported `.reg` backup.
* Used `HKEY_CURRENT_USER\Software\Classes` for user-level file association testing instead of modifying system-wide file associations.
* Removed temporary registry changes after testing.

## Problems Encountered

* The lab manual contained some older Windows paths and assumptions that did not always match Windows 10 exactly.
* The `HKEY_CURRENT_CONFIG` export step was initially almost performed from the wrong equivalent-looking branch under `HKEY_LOCAL_MACHINE`.
* Internet Explorer typed URL history was empty.
* The registry section for shared resources did not contain user-created shared folders.
* Two mapped network drives were visible in File Explorer, but only one appeared clearly under `HKEY_CURRENT_USER\Network`.
* A leftover desktop item appeared after deleting the Registry Editor shortcut and did not immediately delete normally.

## How Problems Were Solved

* Older or slightly different Windows registry paths were adapted to the actual Windows 10 registry structure.
* The `DISPLAY.reg` export was corrected by exporting from:

```text
HKEY_CURRENT_CONFIG\System\CurrentControlSet\Services
```

instead of the similar-looking path under `HKEY_LOCAL_MACHINE`.

* The empty Internet Explorer `TypedURLs` section was documented honestly as an expected result because Internet Explorer was not actively used.
* The shared resources section was documented as having no user-created local shares.
* The persistent network drive information was taken from the available drive entry under `HKEY_CURRENT_USER\Network`.
* The leftover desktop item was treated as a non-critical visual/cleanup issue, while the required Registry Editor shortcut removal was completed.

## Skills Practiced

* Navigating Windows Registry branches.
* Understanding the purpose of major registry hives:

  * `HKEY_LOCAL_MACHINE`
  * `HKEY_CURRENT_USER`
  * `HKEY_CLASSES_ROOT`
  * `HKEY_USERS`
  * `HKEY_CURRENT_CONFIG`
* Exporting selected registry keys.
* Reading `.reg` files as text.
* Restoring registry values from exported backups.
* Creating user-level file associations.
* Adding a context menu command for unknown file types.
* Identifying the current user SID.
* Comparing `HKEY_USERS\<SID>` with `HKEY_CURRENT_USER`.
* Inspecting system login-related registry values.
* Inspecting mapped network drive registry entries.
* Inspecting shared resource registry entries.
* Using snapshots as a safety mechanism before risky system changes.
* Renaming `.reg` files to `.txt` to avoid accidental registry import.
* Documenting differences between a lab manual and the actual behavior of Windows 10.

## What I Learned

This lab showed that the Windows Registry is a central configuration database used by the operating system, applications, hardware components, user profiles, file associations, and network settings.

The most important practical lesson was that registry work must be done carefully. Even small changes can affect system behavior, so it is important to create a snapshot or backup first, export only selected branches, and avoid unnecessary edits.

The lab also demonstrated how `HKEY_CURRENT_USER` works as a user-specific view of the current SID branch under `HKEY_USERS`, and how file associations and context menu commands can be configured through registry keys.

Another useful takeaway was that older lab manuals may not fully match Windows 10 behavior, so results should be verified directly in the system and documented honestly.

## GitHub Notes

Recommended to include in the GitHub learning repository:

* A short explanation of what the Windows Registry is.
* A list of registry hives studied during the lab.
* Safe examples of exported registry areas, without including personal identifiers or full registry dumps.
* The safe command used to rename exported registry files:

```bat
ren *.reg *.txt
```

* Notes about using snapshots before registry editing.
* A short explanation of why `.reg` files were renamed to `.txt`.
* A summary of the `.xtt` file association test and the unknown-file context menu test.
* A note that some registry results may differ depending on Windows version, user activity, and VM configuration.

Not recommended to include:

* Screenshots containing personal names, exact user profile paths, SID values, or VM-identifying details.
* Full exported registry files.
* Full report text prepared for academic submission.
* Exact local usernames, group information, or teacher/group details.
* Any data that exposes personal system paths or account identifiers.
