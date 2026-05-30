# Lab Summary: Installing Windows 10 in VirtualBox

## Context

This lab focused on creating and configuring a Windows 10 virtual machine using Oracle VM VirtualBox.
The host system was a Linux desktop environment, and the guest system was Windows 10.
The main goal was to practice basic virtualization workflow: creating a VM, installing an operating system, configuring virtual hardware, shared folders, USB passthrough, and network access.

The work was done as a practical introduction to desktop virtualization and VM management.

## Main Tasks Completed

* Installed and configured Oracle VM VirtualBox on a Linux host.
* Enabled hardware virtualization in BIOS/UEFI.
* Created a new Windows 10 virtual machine.
* Configured virtual hardware:

  * RAM allocation
  * CPU count
  * virtual disk size
  * display memory
  * 3D acceleration
  * PAE/NX
* Created a dynamically allocated VHD virtual disk.
* Attached a Windows 10 ISO image to the VM.
* Installed Windows 10 manually.
* Created a local Windows user account instead of using a Microsoft account.
* Installed VirtualBox Guest Additions.
* Configured shared clipboard and drag-and-drop.
* Created and connected a shared folder between host and guest.
* Mapped the shared folder as a network drive inside Windows.
* Formatted a USB flash drive and passed it through to the Windows VM.
* Created a test file on the USB drive from inside the guest OS.
* Changed the VM network mode from NAT to Bridged Adapter.
* Verified internet access from the Windows VM.
* Located the VM disk file on the host system.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 virtual machine
* Linux terminal
* Windows Command Prompt
* Windows File Explorer
* VirtualBox Guest Additions
* USB flash drive
* Linux disk utilities:

  * `lsblk`
  * `parted`
  * `mkfs.exfat`
  * `wipefs`

## Commands / Technical Actions

Checked CPU and virtualization-related information:

```bash
lscpu | grep -E 'Model name|Virtualization'
grep -Ewo 'svm|vmx' /proc/cpuinfo | sort | uniq
```

Checked and installed VirtualBox-related packages:

```bash
sudo dnf install VirtualBox akmod-VirtualBox kernel-devel kernel-headers
```

Checked whether VirtualBox kernel modules were loaded:

```bash
lsmod | grep vbox
```

Restarted the VirtualBox driver service:

```bash
sudo systemctl restart vboxdrv.service
```

Added the user to the VirtualBox USB access group:

```bash
sudo usermod -aG vboxusers $USER
```

Created a shared folder on the Linux host:

```bash
mkdir -p ~/VirtualBox_Lab/Share
```

Mapped the shared folder inside the Windows guest:

```cmd
net use s: \\vboxsvr\SharedFolderName
```

Removed an already used network drive mapping:

```cmd
net use s: /delete
```

Checked disks and USB devices on Linux:

```bash
lsblk -o NAME,SIZE,FSTYPE,LABEL,MODEL,TYPE,MOUNTPOINTS
```

Recreated and formatted a USB flash drive:

```bash
sudo umount /dev/sdX1
sudo wipefs -a /dev/sdX
sudo parted /dev/sdX --script mklabel msdos
sudo parted /dev/sdX --script mkpart primary fat32 1MiB 100%
sudo mkfs.exfat -n USBLABEL /dev/sdX1
```

Important note: `/dev/sdX` is a placeholder. The actual disk name must always be checked carefully with `lsblk` before formatting.

Created a test file on the USB drive inside Windows:

```cmd
echo test > E:\test.txt
```

## Problems Encountered

* Hardware virtualization was not initially visible from the Linux host.
* VirtualBox was not available from the default package repositories.
* VirtualBox kernel module was not loaded after installation.
* Windows 10 Enterprise Evaluation ISO was no longer easily available from the expected Microsoft page.
* The first VM was created with a VDI disk instead of the required VHD format.
* USB devices were not visible in VirtualBox at first.
* The USB flash drive still contained a bootable Linux installer layout.
* Formatting the USB drive as exFAT required extra steps.
* Mapping the shared folder to drive `S:` initially returned an error because the drive letter was already in use.
* Bridged networking had to be configured manually.

## How Problems Were Solved

* Hardware virtualization was enabled in BIOS/UEFI.
* RPM Fusion repository was added to make VirtualBox packages available.
* The VirtualBox driver service was restarted to load the required kernel modules.
* A regular official Windows 10 ISO was used instead of the unavailable Enterprise Evaluation ISO.
* The VM was recreated before installation so that the virtual disk could be created as VHD.
* The user was added to the `vboxusers` group, then the host session was restarted so VirtualBox could access USB devices.
* The USB flash drive was cleaned with `wipefs`, repartitioned with `parted`, and formatted as exFAT.
* The existing `S:` network drive mapping was deleted before recreating it.
* The network adapter was switched from NAT to Bridged Adapter and internet access was verified in the guest OS.

## Skills Practiced

* Basic virtualization concepts
* VirtualBox installation and troubleshooting on Linux
* BIOS/UEFI virtualization settings
* Creating and configuring a Windows VM
* Manual Windows installation
* Virtual disk format selection
* Guest Additions installation
* Host-to-guest shared folders
* Windows network drive mapping
* USB passthrough in VirtualBox
* Linux USB drive formatting
* VM network configuration
* NAT vs Bridged Adapter basics
* Safe handling of disk devices in Linux
* Documenting technical work with screenshots

## What I Learned

This lab helped me understand how a virtual machine is created, configured, and used in practice.
I learned that virtualization depends not only on the VM software, but also on BIOS settings, kernel modules, user permissions, disk format choices, and guest tools.

I also practiced troubleshooting common VirtualBox issues on Linux, especially USB passthrough and kernel module loading.
The lab showed the difference between a host OS and a guest OS, and how shared folders, virtual disks, network adapters, and removable devices work across that boundary.

## GitHub Notes

Recommended to include in the GitHub learning repository:

* A short Markdown summary of the lab.
* Key concepts learned:

  * host OS vs guest OS
  * virtual disk formats
  * NAT vs Bridged Adapter
  * Guest Additions
  * USB passthrough
* Safe terminal commands used for checking virtualization, VirtualBox modules, and disk devices.
* A short troubleshooting section describing problems and solutions.

Do not include:

* Passwords
* Personal names or full identity data
* Group number
* Teacher name
* Screenshots with personal information
* Full academic report
* VM disk files
* Windows ISO files
* Any private paths that reveal personal details
* Unnecessary generated files or temporary screenshots

A good repository structure could be:

```text
learning/
└── virtualization/
    └── virtualbox-windows10-install/
        ├── README.md
        └── notes.md
```

Possible README focus:

* What was done
* What tools were used
* What problems appeared
* What was learned
* Useful commands
