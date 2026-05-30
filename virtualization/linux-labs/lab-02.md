# Lab Summary: Linux Filesystems — ext4 and exFAT

## Context

This lab was completed in a Linux virtual machine running Ubuntu 24.04 LTS inside Oracle VM VirtualBox on a Linux host system.

The main goal of the practice was to learn how to work with additional virtual disks and Linux file systems. The lab focused on creating and mounting two file systems:

* ext4 — a native Linux journaling file system.
* exFAT — a cross-platform file system often used for removable drives and external storage.

The work was performed in a VirtualBox Linux VM using the terminal, the graphical file manager, and standard Linux disk/file-system utilities.

## Main Tasks Completed

* Added two small additional virtual disks to the Linux VM in VirtualBox.
* Booted the Ubuntu VM and verified that the new disks were visible in the system.
* Identified the system disk and separated it from the newly attached lab disks.
* Installed exFAT support packages for Ubuntu.
* Created an ext4 file system on one additional disk.
* Created an exFAT file system on the second additional disk.
* Verified file system types and labels using block device tools.
* Created mount points under `/media`.
* Mounted both file systems manually.
* Checked that both mounted volumes appeared in the graphical file manager.
* Fixed write permissions for the mounted file systems.
* Created test directories and text files inside both mounted file systems.
* Checked disk usage and file system types with `df`.
* Inspected ext4 file system parameters with `tune2fs`.
* Calculated the percentage of reserved ext4 blocks.
* Reduced the ext4 reserved block percentage from the default value to a lower value.
* Unmounted both file systems and confirmed that they were no longer mounted.

## Tools Used

* Oracle VM VirtualBox
* Ubuntu Linux VM
* GNOME Files file manager
* Linux terminal
* `lsblk`
* `mount`
* `umount`
* `df`
* `mkfs`
* `tune2fs`
* `apt`
* exFAT support utilities:

  * `exfat-fuse`
  * `exfatprogs`

## Commands / Technical Actions

Useful commands and actions practiced during the lab:

```bash
ls /dev/ | grep sd
```

Used to list disk devices with names such as `sda`, `sdb`, and `sdc`.

```bash
mount | grep /dev/sd
```

Used to check which disk devices were currently mounted.

```bash
lsblk
```

Used to inspect block devices, their sizes, partitions, and mount points.

```bash
sudo apt update
sudo apt install exfat-fuse exfatprogs
```

Used to install exFAT support tools on Ubuntu.

```bash
lsblk -f | grep sd
```

Used to display file system information for disk devices.

```bash
sudo mkdir -p /media/ext4
sudo mkdir -p /media/exfat
```

Used to create mount points for the two file systems.

```bash
sudo mount /dev/sdX /media/ext4
sudo mount /dev/sdY /media/exfat
```

Used to manually mount the created file systems.

```bash
mount | grep /media
```

Used to verify that the file systems were mounted under `/media`.

```bash
df
df -m | grep sd
df -Tm | grep sd
df -m -t ext4
```

Used to inspect disk usage, available space, and file system types.

```bash
sudo tune2fs -l /dev/sdX | more
```

Used to inspect ext4 file system settings.

```bash
sudo tune2fs -l /dev/sdX | grep -E "Filesystem created|Last mount time|Last write time|Reserved block count|Block count"
```

Used to extract the most relevant ext4 metadata for the lab.

```bash
sudo tune2fs -m 2 /dev/sdX
```

Used to reduce the reserved block percentage on the ext4 file system.

```bash
sudo umount /dev/sdX
sudo umount /dev/sdY
```

Used to unmount the lab file systems.

> Note: exact disk names such as `/dev/sdb` and `/dev/sdc` should always be checked with `lsblk` before running disk or file system commands. Disk formatting commands were used only on newly created empty lab disks.

## Problems Encountered

Several small issues occurred during the lab:

* Two virtual disks were accidentally created with the same name.
* The newly mounted file systems were not writable by the regular user at first.
* The graphical file manager did not offer an option to create a new text file through the right-click menu.
* The graphical file manager did not clearly show an unmount/eject button for the mounted volumes.
* Clipboard/paste behavior in the VM terminal became unreliable at one point.
* A typo was made when entering a `df` command.

## How Problems Were Solved

* The duplicate virtual disks were removed and recreated with separate clear names.
* The main system disk was carefully identified and avoided before any file system creation commands were used.
* For the ext4 mount point, ownership was changed so the regular user could write to it.
* For the exFAT mount point, the file system was remounted with user ownership options.
* Text files were created through the terminal instead of the graphical file manager.
* Both file systems were unmounted through the terminal when the graphical file manager did not provide a clear unmount option.
* Clipboard issues were handled by checking VirtualBox shared clipboard settings and using terminal-specific paste shortcuts.
* The mistyped command was corrected and rerun successfully.

## Skills Practiced

* Adding virtual disks to a VirtualBox VM.
* Identifying Linux disks and partitions safely.
* Understanding the difference between a whole disk and a partition.
* Creating file systems on additional storage devices.
* Working with ext4 and exFAT file systems.
* Installing Linux packages for file system support.
* Mounting and unmounting file systems manually.
* Creating and verifying files on mounted volumes.
* Checking disk usage with `df`.
* Inspecting ext4 metadata with `tune2fs`.
* Understanding ext4 reserved blocks.
* Adjusting ext4 reserved block percentage.
* Troubleshooting Linux permissions on mounted file systems.
* Using both terminal tools and graphical file manager checks.

## What I Learned

This practice helped me understand how Linux detects and works with additional storage devices. I learned that a virtual disk must have a file system before it can be used for normal file storage.

I also learned the practical difference between ext4 and exFAT. ext4 is a native Linux file system with Linux permissions, journaling, and system-oriented features. exFAT is more suitable for removable or cross-platform storage, but it does not handle Linux ownership and permissions in the same way.

Another important part of the lab was learning to be careful with disk names. Commands that create file systems can destroy data if the wrong disk is selected, so checking `lsblk` before running them is essential.

The lab also showed that mounting a file system does not automatically mean the current user can write to it. Permissions and mount options may need to be adjusted depending on the file system type.

## GitHub Notes

Good things to include in a GitHub learning repository:

* A short explanation of ext4 vs exFAT.
* A cleaned list of safe inspection commands such as `lsblk`, `df`, `mount`, and `tune2fs`.
* A brief note about checking disk names carefully before formatting.
* A short troubleshooting section about mount permissions.
* A summary of how ext4 reserved blocks work.
* A note that exFAT may require additional packages on Linux.
* Generalized examples using `/dev/sdX` instead of real disk names.

Things not to include:

* Screenshots containing personal information.
* Full academic report text.
* Passwords or account details.
* Full names, group numbers, teacher names, or other identifying data.
* Exact VM names if they contain personal information.
* Dangerous formatting commands as copy-paste instructions without strong warnings.
* Unnecessary temporary files or raw terminal history.
