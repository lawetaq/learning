# Lab Summary: Linux File Access Control and Steganography

## Context

This lab was completed in a Linux virtual machine running Ubuntu 24.04.4 LTS inside Oracle VM VirtualBox. The host system was Nobara Linux 43 KDE.

The main goal of the lab was to practice Linux user and group management, file permission control, system account files, shared directory access, and basic steganography using `steghide`.

The work was performed in a Linux VM through the graphical interface and terminal. The lab originally referenced older Ubuntu versions and older interface paths, so some steps were adapted to a modern Ubuntu release while keeping the same technical purpose.

## Main Tasks Completed

* Created and configured a new Ubuntu virtual machine in VirtualBox.
* Installed Ubuntu 24.04.4 LTS in the VM.
* Installed VirtualBox Guest Additions.
* Verified that the installed system was running correctly.
* Enabled and tested shared clipboard functionality between host and guest.
* Set up root access for lab purposes.
* Checked and edited sudo privileges using `visudo`.
* Created and removed a test user.
* Manually created a user by editing `/etc/passwd`.
* Created, modified, and deleted Linux groups.
* Added users to supplementary groups.
* Checked system user/group files:

  * `/etc/passwd`
  * `/etc/shadow`
  * `/etc/group`
* Practiced file and directory permissions using `chmod`.
* Created a shared directory with group-based write access.
* Verified that another user could write to the shared directory.
* Installed and used `steghide`.
* Created a JPEG image container.
* Embedded a text file into a JPEG image.
* Extracted hidden text back from the stego image.
* Checked supported encryption algorithms.
* Created a second stego image using a different encryption algorithm and mode.

## Tools Used

* Oracle VM VirtualBox
* Ubuntu 24.04.4 LTS VM
* GNOME Terminal
* Ubuntu Settings / Users panel
* VirtualBox Guest Additions
* `nano`
* `visudo`
* `apt`
* `adduser`
* `deluser`
* `passwd`
* `su`
* `id`
* `groups`
* `groupadd`
* `groupdel`
* `gpasswd`
* `usermod`
* `chmod`
* `chgrp`
* `ls`
* `cat`
* `rm`
* `mkdir`
* `cp`
* `mv`
* `steghide`
* ImageMagick

## Commands / Technical Actions

```bash
lsb_release -a
whoami
pwd
```

Used to verify the Ubuntu version, current user, and current working directory.

```bash
sudo passwd root
su root
whoami
exit
```

Used to enable and test root access for the lab.

```bash
sudo visudo
sudo cat /etc/sudoers | grep -E "root|username"
```

Used to safely edit and verify sudo privileges.

```bash
sudo adduser test
id test
```

Used to create and verify a temporary user.

```bash
id test
ls /home
```

Used after deleting the temporary user to confirm removal.

```bash
cat /etc/passwd | grep -E "root|username"
head -n 5 /etc/passwd
```

Used to inspect the structure of `/etc/passwd`.

```bash
sudo cp /etc/passwd /etc/passwd.backup
sudo cp /etc/shadow /etc/shadow.backup
sudo nano /etc/passwd
```

Used to back up important system account files before manual editing.

```bash
sudo mkdir -p /home/student
sudo chown student:mainuser /home/student
sudo chmod 755 /home/student
sudo passwd student
id student
su student
whoami
exit
```

Used to manually complete and test a user account created through `/etc/passwd`.

```bash
sudo groupadd testgroup
sudo groupadd share
sudo usermod -a -G testgroup,share student
id student
groups student
```

Used to create groups and assign a user to supplementary groups.

```bash
sudo gpasswd -d student testgroup
sudo groupdel testgroup
getent group testgroup
getent group share
```

Used to remove a user from a group and delete a group.

```bash
sudo gpasswd -a mainuser share
id mainuser
groups mainuser
getent group share
```

Used to add the main user to a shared group.

```bash
sudo gpasswd -r share
```

Used to remove the group password from the shared group.

```bash
ls -l /etc/shadow
sudo head -n 3 /etc/shadow
```

Used to inspect `/etc/shadow` permissions and confirm that it is protected.

```bash
sudo cp /etc/group /etc/group.backup
sudo nano /etc/group
id mainuser
getent group editgroup
```

Used to back up and manually edit `/etc/group`.

```bash
ls -l ~ >> ~/result.txt
ls -l /etc/shadow >> ~/result.txt
ls -l /bin/su >> ~/result.txt
cat ~/result.txt
```

Used to collect file permission information into a result file.

```bash
chmod a+x result.txt
ls -l result.txt

chmod g+x-w result.txt
ls -l result.txt

chmod 666 result.txt
ls -l result.txt
```

Used to practice changing file permissions.

```bash
mkdir Folder
ls -l
chmod a-x-w Folder
ls -l
mv result.txt Folder/
chmod u+w+x Folder
cp result.txt Folder/
ls -l Folder
cat Folder/result.txt
rm Folder
rm -r Folder
```

Used to test directory permissions and recursive directory removal.

```bash
mkdir ~/Public/Share
sudo chgrp share ~/Public/Share
chmod g+w ~/Public/Share
ls -l ~/Public
ls -l ~/Public > ~/Public/Share/result1.txt
cat ~/Public/Share/result1.txt
```

Used to create a group-writable shared directory.

```bash
su student
echo "Hello from student" >> /home/mainuser/Public/Share/my_file.txt
ls -l /home/mainuser/Public/Share
cat /home/mainuser/Public/Share/my_file.txt
exit
```

Used to verify that a group member could write to the shared directory.

```bash
sudo deluser student
id student
ls /home
sudo rm -r /home/student
```

Used to remove the manually created user and its home directory.

```bash
mkdir ~/steg
cd ~/steg
echo "Hello, world! Linux steghide test." > text.txt
cat text.txt
```

Used to create a working directory and text file for steganography.

```bash
sudo apt update
sudo apt install steghide imagemagick
```

Used to install the required steganography and image tools.

```bash
convert -size 800x500 gradient:skyblue-lightgreen -gravity center -pointsize 42 -annotate 0 "Linux Lab" picture.jpg
file picture.jpg
```

Used to create and verify a JPEG image container.

```bash
steghide help
```

Used to view basic `steghide` usage.

```bash
steghide embed -ef text.txt -cf picture.jpg -sf stego.jpg
ls -lh picture.jpg stego.jpg
file stego.jpg
```

Used to embed text into a JPEG image and compare file sizes.

```bash
rm text.txt
steghide extract -sf stego.jpg -xf text.txt
ls -l
cat text.txt
```

Used to remove the original text file and extract it back from the stego image.

```bash
steghide encinfo
```

Used to list supported encryption algorithms and modes.

```bash
steghide info stego.jpg
steghide info -p <passphrase> stego.jpg
steghide info -p <passphrase> stego.jpg >> steginfo.txt
cat steginfo.txt
```

Used to inspect the stego container and save information about the embedded data.

```bash
steghide embed -e gost ctr -ef text.txt -cf picture.jpg -sf stego1.jpg
steghide info -p <passphrase> stego1.jpg
steghide info -p <passphrase> stego1.jpg >> steginfo.txt
steghide extract -sf stego1.jpg -xf text1.txt
cat text1.txt
```

Used to create a second stego image with another encryption algorithm and extract the hidden text.

## Problems Encountered

* The first Ubuntu ISO version tested caused problems in VirtualBox.
* The Ubuntu installer failed several times with an error related to package installation.
* The VM initially had shared clipboard enabled in VirtualBox settings, but copying text between host and guest did not work.
* VirtualBox Guest Additions could not be installed immediately because required build tools were missing.
* During Guest Additions installation, an incorrect ARM64 installer was accidentally launched first.
* Some lab instructions referenced older Ubuntu interface paths and older GUI behavior.
* The command `group student` was entered by mistake instead of `groups student`.
* A generated JPEG file was initially created in the home directory instead of the intended `~/steg` directory.
* Some operations involving `/etc/passwd`, `/etc/group`, and `/etc/shadow` required extra caution because mistakes in these files can break user management.

## How Problems Were Solved

* A stable Ubuntu 24.04.4 LTS ISO was downloaded from the official Ubuntu releases server.
* The VM was recreated and configured with more RAM, 2 CPUs, VMSVGA graphics, 128 MB video memory, NAT networking, and 3D acceleration disabled.
* The installer was retried after configuration adjustments and eventually completed successfully.
* VirtualBox Guest Additions were installed after installing the required packages:

  * `gcc`
  * `make`
  * `perl`
  * Linux kernel headers
* The correct Guest Additions installer for the VM architecture was used.
* After Guest Additions installation and reboot, shared clipboard functionality worked.
* Modern Ubuntu settings were used as the equivalent of older GUI user management steps.
* System files were backed up before manual editing.
* Commands were checked through verification commands such as `id`, `groups`, `getent`, `ls -l`, and `cat`.
* The generated JPEG file was moved into the correct `~/steg` working directory.

## Skills Practiced

* Creating and configuring a Linux VM in VirtualBox.
* Installing Ubuntu in a virtual machine.
* Installing VirtualBox Guest Additions.
* Working with Linux users and groups.
* Understanding UID, GID, primary groups, and supplementary groups.
* Using `sudo`, `su`, and root access.
* Editing privileged configuration files safely.
* Understanding `/etc/passwd`, `/etc/shadow`, and `/etc/group`.
* Creating, modifying, and deleting users.
* Creating, modifying, and deleting groups.
* Managing file and directory permissions.
* Understanding `r`, `w`, and `x` permissions for files and directories.
* Using symbolic and numeric `chmod` modes.
* Creating a group-writable shared directory.
* Testing access permissions from another user account.
* Using absolute paths to avoid ambiguity.
* Understanding recursive deletion with `rm -r`.
* Installing and using command-line tools through `apt`.
* Creating a JPEG image with ImageMagick.
* Using `steghide` to embed and extract hidden data.
* Checking steganography encryption settings.
* Documenting troubleshooting steps.

## What I Learned

This lab helped reinforce how Linux controls access through users, groups, ownership, and permission bits. It showed that permissions behave differently for files and directories, especially the importance of the execute bit on directories.

The lab also demonstrated how sensitive system account files are structured and why they should be edited carefully. Backups are important before changing files like `/etc/passwd` or `/etc/group`.

The steganography part showed how data can be hidden inside an image file and protected with encryption. The default steghide container used Rijndael-128 in CBC mode with compression enabled, while the second container used GOST in CTR mode.

The troubleshooting process was also useful: VM installation issues, missing packages, Guest Additions problems, and command mistakes were diagnosed step by step rather than ignored.

## GitHub Notes

Good materials to include in the GitHub learning repository:

* A cleaned Markdown summary of the lab.
* Safe command examples for:

  * checking users and groups;
  * creating temporary users and groups;
  * checking permissions;
  * using `chmod`;
  * creating shared group directories;
  * basic `steghide` usage.
* A short troubleshooting section about:

  * Ubuntu installer issues in VirtualBox;
  * Guest Additions requiring build tools;
  * shared clipboard requiring Guest Additions.
* A short explanation of:

  * `/etc/passwd`;
  * `/etc/shadow`;
  * `/etc/group`;
  * `su` vs `sudo`;
  * absolute paths;
  * `rm`, `rm -r`, and `rm -f`;
  * basic steganography workflow.

Things not worth adding to GitHub:

* Passwords or passphrases.
* Personal names, group numbers, teacher names, or student identifiers.
* Full screenshots from the academic report.
* Full contents of `/etc/shadow`.
* The complete DOCX report submitted for class.
* Any files containing private VM/user details.
* Excessive installer screenshots that do not add technical value.

A good GitHub structure could be:

```text
linux-vm-labs/
  lab-09-linux-access-control-steghide/
    README.md
    commands.md
    notes.md
```

Suggested repository content:

* `README.md`: concise overview, goals, and what was practiced.
* `commands.md`: cleaned safe command list.
* `notes.md`: troubleshooting notes and lessons learned.
