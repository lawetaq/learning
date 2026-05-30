# Lab Summary: Practical Work 4 — Windows Processes and Threads

## Context

This practical work was completed in a Windows 10 virtual machine running in Oracle VM VirtualBox on a Nobara Linux 43 KDE host system.

The main goal of the lab was to study Windows processes and threads, understand how they differ, and practice using built-in and external diagnostic tools to inspect process activity, services, loaded modules, threads, handles, and process creation events.

The work focused on Windows system analysis using command-line tools, Task Manager, Sysinternals utilities, Debugging Tools for Windows, and a safe alternative to the outdated QuickSlice utility.

## Main Tasks Completed

* Viewed active Windows processes using the `tasklist` command.
* Checked process IDs, session types, memory usage, and process names.
* Displayed loaded DLL modules for processes.
* Filtered processes by loaded module and process name.
* Used Windows Task Manager to inspect processes, details, users, and services.
* Saved service information from `tasklist /svc` into a text file.
* Compared services shown in `tasklist /svc` with services shown in Task Manager.
* Checked which process hosts a selected Windows service.
* Opened process file properties and verified a Microsoft digital signature.
* Downloaded and used Process Explorer from Microsoft Sysinternals.
* Viewed processes as a hierarchical tree.
* Identified parent-child process relationships, including `services.exe` as the parent for many `svchost.exe` service-hosting processes.
* Enabled process image path display in Process Explorer.
* Observed process creation highlighting by launching Calculator.
* Viewed browser process threads using Process Explorer.
* Inspected `notepad.exe` process properties, including threads, call stack, environment variables, and security context.
* Viewed loaded DLLs and open handles for a selected process.
* Downloaded and used Process Monitor from Microsoft Sysinternals.
* Captured and filtered events related to Calculator startup.
* Installed Windows SDK components required for Debugging Tools for Windows.
* Used `tlist` to view active processes, process tree structure, and browser thread information.
* Attempted to use QuickSlice, but replaced it with Process Explorer due to download/access issues with the outdated utility.
* Used Process Explorer to observe Paint and browser process activity and threads as a safe alternative.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 VM
* Windows Command Prompt
* Windows Task Manager
* File Explorer
* Notepad
* Microsoft Edge
* Paint
* Microsoft Sysinternals Process Explorer
* Microsoft Sysinternals Process Monitor
* Windows SDK installer
* Debugging Tools for Windows
* `tlist.exe`
* Screenshot tools on the host system
* Archive tools for packaging screenshots
* DOCX report template from previous practical work

## Commands / Technical Actions

```cmd
mkdir C:\Student_lab4
```

Created a working directory for lab files.

```cmd
tasklist
```

Displayed the list of active Windows processes.

```cmd
tasklist /m
```

Displayed loaded DLL modules for active processes.

```cmd
tasklist /m KERNEL32.DLL
```

Filtered processes that use `KERNEL32.DLL`.

```cmd
tasklist /m ntdll.dll
```

Filtered processes that use `ntdll.dll`.

```cmd
tasklist /m | findstr explorer.exe
```

Filtered module output for `explorer.exe`.

```cmd
tasklist /m | findstr cmd.exe
```

Filtered module output for `cmd.exe`.

```cmd
tasklist /fi "USERNAME eq Student"
```

Displayed processes running under the selected local user account.

```cmd
tasklist /svc
```

Displayed processes and hosted Windows services.

```cmd
tasklist /svc > C:\Student_lab4\services.txt
```

Saved the service list to a text file.

```cmd
notepad C:\Student_lab4\services.txt
```

Opened the saved service list in Notepad.

```cmd
tasklist /svc /fi "SERVICES eq KeyIso"
```

Found the process hosting the `KeyIso` service.

```cmd
tasklist /svc | findstr KeyIso
```

Found the same service-hosting process using text filtering.

```cmd
winver
```

Checked the Windows 10 version before installing Windows SDK tools.

```cmd
tlist
```

Displayed active processes using TList.

```cmd
tlist /t
```

Displayed a process tree using TList.

```cmd
tlist msedge
```

Displayed thread information for a Microsoft Edge process.

Other technical actions included:

* Opening Task Manager and switching between the Processes, Details, and Services tabs.
* Sorting processes by user name and services by status.
* Opening process properties and checking digital signatures.
* Enabling the Image Path column in Process Explorer.
* Viewing process threads and thread stacks.
* Viewing process environment variables and security context.
* Using Process Monitor filters to capture Calculator startup events.
* Excluding noisy registry operations from Process Monitor output.
* Installing only selected Windows SDK components: Windows Performance Toolkit and Debugging Tools for Windows.
* Using Process Explorer as a safe replacement for QuickSlice.

## Problems Encountered

* The Windows VM initially failed to boot normally after a host restart or interrupted VM session.
* Windows entered automatic repair and cleanup mode.
* The VM had to be handled carefully to avoid further corruption or forced shutdown.
* The Process Monitor filter setup was confusing at first because the interface required specific filter conditions.
* Calculator appeared as `CalculatorApp.exe` instead of the expected `Calculator.exe`.
* QuickSlice could not be downloaded normally from the page specified in the lab instructions.
* The Softpedia page for QuickSlice appeared broken or incomplete, and the download did not start.
* QuickSlice is outdated, so downloading executable files from random mirrors or GitHub repositories was considered unsafe.
* The lab instructions referenced Chrome, but Microsoft Edge was used instead because it is Chromium-based and already available in the VM.

## How Problems Were Solved

* The VM was allowed to complete Windows automatic repair and cleanup without being powered off.
* A VirtualBox snapshot was created before continuing the lab to provide a safe restore point.
* The VM was later used normally after Windows finished recovery.
* Process Monitor filtering was corrected by using an exact process name condition and confirming the actual process name shown in the event log.
* Since Calculator appeared as `CalculatorApp.exe`, the report can mention the actual process name used by this Windows version.
* QuickSlice was not downloaded from untrusted mirrors. Instead, the issue was documented, and Process Explorer was used as a safer alternative for observing CPU activity and process threads.
* Microsoft Edge was used instead of Chrome because it is based on Chromium and demonstrates similar multi-process and multi-threaded browser behavior.

## Skills Practiced

* Basic Windows process inspection.
* Understanding the difference between processes, services, DLL modules, handles, and threads.
* Using `tasklist` with filters and output redirection.
* Comparing command-line process information with Task Manager.
* Inspecting service-hosting processes.
* Verifying process file digital signatures.
* Using Sysinternals Process Explorer for deeper process analysis.
* Reading process trees and identifying parent-child relationships.
* Viewing process threads and thread call stacks.
* Inspecting process environment variables and security context.
* Viewing loaded DLLs and open handles.
* Using Sysinternals Process Monitor to trace process startup activity.
* Filtering noisy diagnostic logs.
* Installing selected Windows SDK components.
* Using TList from Debugging Tools for Windows.
* Making safe decisions when old utilities are unavailable or potentially risky.
* Documenting technical problems honestly in a lab/report context.

## What I Learned

This lab helped me understand that Windows applications are not just simple visible programs. Each running application is represented by one or more processes, and each process may contain multiple threads. Processes can load many DLL modules, open handles to files, registry keys, synchronization objects, and other system resources.

I also learned that many Windows services are hosted inside `svchost.exe` processes, and that tools like Task Manager, Process Explorer, Process Monitor, and TList provide different levels of detail about the same system activity.

The lab also showed how process creation can be traced step by step: a process starts, DLL images are loaded, files are opened and read, threads are created, and handles are opened or closed. Process Monitor was especially useful for seeing this activity in real time.

Another important takeaway was that old tools from lab instructions may no longer be easily available or safe to download. In that case, it is better to document the problem and use a trusted alternative instead of downloading random executable files from questionable sources.

## GitHub Notes

Recommended to include in the GitHub learning repository:

* A short explanation of the difference between processes and threads.
* A list of Windows process analysis tools used in the lab.
* Safe command examples such as `tasklist`, `tasklist /m`, `tasklist /svc`, and `tlist`.
* Notes about using Process Explorer to inspect process trees, threads, DLLs, handles, environment variables, and security context.
* Notes about using Process Monitor to filter events for a specific process.
* A short troubleshooting note about outdated tools such as QuickSlice and why a safe alternative was used.
* A brief reflection on what was learned about Windows internals.

Do not include:

* Full academic report text.
* Personal names, group number, teacher name, or other identifying details.
* Screenshots showing personal account names or system-specific paths if they reveal private information.
* Full VM file paths that include personal usernames, unless anonymized.
* Raw logs with excessive system details.
* Downloaded executable files.
* Random third-party download links for old utilities.
* Any sensitive information from the VM or host system.

A good GitHub entry for this lab should be a technical learning note, not a submission report. It should focus on what tools were used, what each tool shows, what commands were practiced, and what was learned about Windows process and thread analysis.
