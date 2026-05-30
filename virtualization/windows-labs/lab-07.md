# Lab Summary: Windows File Systems, Virtual Disks, Storage Spaces, NTFS Permissions, and EFS

## Context

This lab was performed in a Windows 10 virtual machine running in Oracle VM VirtualBox on a Nobara Linux 43 KDE host system.

The main goal of the lab was to practice Windows storage management, virtual disks, file systems, NTFS permissions, access control lists, file ownership, integrity levels, and EFS encryption.

The work was done inside a Windows 10 VM using Disk Management, DiskPart, Command Prompt, Control Panel, File Explorer, Storage Spaces, and VirtualBox virtual disk settings.

## Main Tasks Completed

* Added several additional virtual hard disks to the Windows VM.
* Created and formatted volumes with different file systems:

  * FAT32
  * exFAT
  * NTFS
* Used Disk Management and DiskPart to manage disks and partitions.
* Created a VHD file on an exFAT volume.
* Attached, initialized, and formatted the VHD as an NTFS volume.
* Verified that the attached VHD worked like a regular disk by creating a test file on it.
* Detached and reattached the VHD.
* Tested the FAT32 file size limitation by trying to copy a 5 GB VHD file to a FAT32 volume.
* Created and removed an NTFS mount point.
* Created a Storage Spaces pool from two virtual disks.
* Created a two-way mirror storage space.
* Created and deleted a simple storage space.
* Compared FAT32, exFAT, and NTFS capabilities using `fsutil`.
* Created a folder structure for NTFS permission testing.
* Disabled and converted inherited NTFS permissions.
* Configured explicit permissions for groups and local users.
* Created local Windows users for access testing.
* Tested folder access from different user accounts.
* Used `cacls` and `icacls` to view, modify, save, and restore ACLs.
* Practiced working with file ownership and special permissions.
* Tested copy and move behavior on NTFS volumes.
* Tested Windows integrity level modification.
* Created and tested an EFS-encrypted file.
* Exported ACL data into a text file.
* Collected command output into a lab protocol file.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 VM
* VirtualBox virtual disks
* Windows Disk Management
* DiskPart
* Command Prompt
* Control Panel
* Storage Spaces
* File Explorer
* Notepad
* `fsutil`
* `cacls`
* `icacls`
* `cipher`
* `dir`
* `xcopy`
* `move`
* Shared folder / host file transfer

## Commands / Technical Actions

Useful commands used during the lab:

```bat
diskpart
list disk
select disk 3
list part
create partition primary
format fs=exfat quick label=EXFAT_USB
list volume
select volume 5
assign letter=F
exit
```

```bat
mkdir C:\stud
fsutil fsinfo volumeinfo E:
fsutil fsinfo volumeinfo F:
fsutil fsinfo volumeinfo C:
fsutil fsinfo volumeinfo F: >> C:\stud\lab6.txt
fsutil fsinfo volumeinfo C: >> C:\stud\lab6.txt
```

```bat
mkdir C:\ACCESS
mkdir C:\ACCESS\INFO
mkdir C:\ACCESS\DATA
mkdir C:\ACCESS\DOCS
mkdir C:\ACCESS\LIB

echo info test > C:\ACCESS\INFO\info.txt
echo data test > C:\ACCESS\DATA\data.txt
echo docs test > C:\ACCESS\DOCS\docs.txt
echo lib test > C:\ACCESS\LIB\lib.txt
```

```bat
cacls access
cacls access >> C:\stud\lab6.txt
cacls access\info
cacls access\info >> C:\stud\lab6.txt
cacls access\*
cacls access\* >> C:\stud\lab6.txt
```

Local users were created for access testing. For a public learning repository, passwords should be replaced with placeholders:

```bat
net user user1 <password> /add
net user user2 <password> /add
net user
net localgroup Users
```

```bat
cacls C:\ACCESS\DOCS /G Users:C
cacls C:\ACCESS\DOCS
cacls C:\ACCESS\DOCS >> C:\stud\lab6.txt
```

```bat
echo adm1 test > C:\ACCESS\DOCS\adm1.txt
echo adm2 test > C:\ACCESS\DOCS\adm2.txt
echo adm3 test > C:\ACCESS\DOCS\adm3.txt
```

```bat
icacls C:\ACCESS\DOCS\adm1.txt /inheritance:d
icacls C:\ACCESS\DOCS\adm2.txt /inheritance:d
icacls C:\ACCESS\DOCS\adm3.txt /inheritance:d
```

```bat
icacls C:\ACCESS\DOCS\adm1.txt /remove:g Users
icacls C:\ACCESS\DOCS\adm2.txt /remove:g Users
icacls C:\ACCESS\DOCS\adm3.txt /remove:g Users
```

```bat
icacls C:\ACCESS\DOCS\adm1.txt /grant user1:M
icacls C:\ACCESS\DOCS\adm2.txt /grant "user1:(R,WO)"
icacls C:\ACCESS\DOCS\adm3.txt /grant "user1:(R,WDAC)"
```

```bat
dir \ACCESS\DOCS /q
dir \ACCESS\DOCS /q >> C:\stud\lab6.txt
```

```bat
icacls C:\ACCESS\DATA /save C:\stud\acl_data.txt /t
notepad C:\stud\acl_data.txt
```

```bat
icacls C:\ACCESS\DATA /grant Users:F /t
cacls C:\ACCESS\DATA
cacls C:\ACCESS\DATA\*
```

```bat
icacls C:\ACCESS\ /restore C:\stud\acl_data.txt
cacls C:\ACCESS\DATA
cacls C:\ACCESS\DATA\*
```

```bat
xcopy C:\ACCESS\LIB C:\ACCESS\DOCS\LIB_COPY /E /I
cacls \ACCESS\DOCS\LIB_COPY
```

```bat
xcopy C:\ACCESS\LIB H:\LIB_COPY /E /I
cacls H:\LIB_COPY
```

```bat
move C:\ACCESS\LIB C:\ACCESS\INFO\LIB
cacls \ACCESS\INFO\LIB
```

```bat
icacls C:\ACCESS\DOCS\adm1.txt /setintegritylevel H
icacls C:\ACCESS\DOCS\adm1.txt
```

```bat
mkdir C:\EFS_TEST
echo secret admin file > C:\EFS_TEST\secret.txt
cipher /e C:\EFS_TEST
cipher /e C:\EFS_TEST\secret.txt
cipher C:\EFS_TEST
```

```bat
type C:\EFS_TEST\secret.txt
```

```bat
cipher /w:C:\EFS_TEST
```

## Problems Encountered

* The exFAT option was not available in the Disk Management formatting wizard.
* After formatting the exFAT volume, it did not immediately appear in File Explorer.
* FAT32 could not store the 5 GB VHD file.
* After rebooting the VM, the attached VHD was no longer mounted automatically.
* Removing inherited permissions from `C:\ACCESS` caused access to the folder to be denied.
* Some permission buttons were disabled until “Change permissions” was selected in Advanced Security Settings.
* `icacls` rejected some special permission syntax when rights were written without parentheses.
* Some commands were accidentally run from an Administrator Command Prompt instead of the intended user account.
* Restoring ACLs produced an access denied message for a file created by another user.
* Copying or moving some folders through File Explorer was unavailable because of NTFS permission restrictions.
* Setting a high integrity level on `adm1.txt` failed with `Access is denied`.
* The VM became slow because the Windows system disk had very little free space left.
* The Windows VM was later removed to free disk space before continuing with Linux labs.

## How Problems Were Solved

* exFAT formatting was completed using DiskPart instead of the Disk Management GUI.
* The exFAT volume was made visible by assigning it a drive letter manually.
* The FAT32 file size limitation was confirmed by attempting to copy a 5 GB VHD file and receiving a “file too large” error.
* The VHD was reattached manually through Disk Management after reboot.
* NTFS inheritance behavior was intentionally tested by removing inherited permissions and then adding explicit permissions.
* Disabled inheritance on child folders was handled by selecting “Change permissions” first, then converting inherited permissions into explicit permissions.
* `icacls` special permissions were corrected using syntax like:

```bat
icacls C:\ACCESS\DOCS\adm2.txt /grant "user1:(R,WO)"
icacls C:\ACCESS\DOCS\adm3.txt /grant "user1:(R,WDAC)"
```

* Commands were rerun under the correct user account when needed.
* ACL restore errors were documented honestly. The main folder and original file ACLs were restored successfully, while a user-created file had separate ownership and permissions.
* `xcopy` was used instead of File Explorer when GUI copy/paste was restricted.
* The failed integrity level command was documented as a permissions-related result.
* Disk cleanup was considered, but the VM was ultimately deleted after the Windows labs were completed.

## Skills Practiced

* Managing virtual disks in VirtualBox.
* Using Windows Disk Management.
* Using DiskPart for partitioning and formatting.
* Creating, attaching, detaching, initializing, and formatting VHD files.
* Comparing FAT32, exFAT, and NTFS behavior.
* Understanding FAT32 file size limitations.
* Creating NTFS mount points.
* Creating and managing Windows Storage Spaces.
* Creating two-way mirror and simple storage spaces.
* Reading file system capabilities with `fsutil`.
* Managing NTFS permissions through GUI and CLI tools.
* Disabling and converting inherited permissions.
* Creating local Windows users.
* Testing permissions from different user accounts.
* Using `cacls` and `icacls`.
* Saving and restoring ACLs.
* Working with file ownership and special permissions.
* Testing copy and move ACL behavior on NTFS.
* Testing Windows integrity labels.
* Encrypting files with EFS.
* Verifying EFS access restrictions between users.
* Collecting technical evidence for a report.

## What I Learned

This lab showed how Windows file systems differ in real use, not only in theory. FAT32 is widely compatible but has a strict file size limitation, while exFAT works better for large portable files. NTFS is much more advanced and supports ACLs, ownership, EFS, compression-related features, quotas, hard links, metadata features, and other Windows-specific mechanisms.

The lab also showed that NTFS permissions are more complex than simple read/write flags. Access can come from group membership, explicit permissions, inherited permissions, special permissions, ownership, and sometimes integrity levels.

Copying and moving files can also affect permissions differently depending on where the operation happens. Copying to another location usually makes the copied object inherit permissions from the destination, while moving inside the same NTFS volume can preserve the original ACL.

EFS encryption was especially useful to test because it demonstrated that normal file permissions and encryption are separate layers. Even if a user can see a file path, they may still be unable to read encrypted file contents without the correct user certificate or key.

## GitHub Notes

Good things to include in a GitHub learning repository:

* A short technical summary of the lab.
* A sanitized list of tools used.
* Safe command examples with placeholders instead of real passwords.
* A table comparing FAT32, exFAT, and NTFS.
* A short explanation of FAT32’s file size limitation.
* A short explanation of VHD creation and attachment.
* A short explanation of NTFS inheritance and explicit permissions.
* A sanitized permission matrix for test users.
* Notes about ACL backup and restore using `icacls`.
* Notes about EFS behavior and access denial from another user.
* Problems encountered and how they were solved.

Do not include:

* Real names, group number, teacher name, or title page data.
* Real passwords or password-like examples.
* Screenshots showing personal files, usernames, host paths, or sensitive VM details.
* Full academic report text.
* Full `lab6.txt` or `acl_data.txt` if it contains machine-specific SIDs, usernames, or internal paths.
* Unnecessary VM screenshots.
* The original DOCX report.
