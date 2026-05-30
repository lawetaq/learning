# Lab Summary: Linux/GNU Practical Work 11 — Bash Shell Basics

## Context

This lab was completed in an Ubuntu Linux virtual machine running in Oracle VM VirtualBox. The host system was a Linux desktop, and the guest OS was Ubuntu 24.04 LTS.

The main goal of the lab was to practice basic Bash shell usage, including working with text files, sorting and filtering file contents, using environment variables, configuring aliases, changing the command prompt, and creating simple Bash scripts.

The work was performed mainly through the Linux terminal. A graphical text editor was attempted for editing `.bashrc`, but terminal-based file editing/redirection was used instead because of a permission/display issue.

## Main Tasks Completed

* Checked the current working directory and listed the contents of the home directory.
* Created a text file containing several surname-like values.
* Created calendar files for the current month and two selected months of the variant year.
* Practiced sorting text files with `sort`.
* Created sorted and unique versions of text files.
* Extracted parts of files using `head` and `tail`.
* Compared sorted files using `comm`.
* Created and sorted a file with numbers using numeric sorting.
* Counted words and characters with `wc`.
* Filtered file contents using `grep` and `grep -v`.
* Practiced file searching with `find`.
* Created temporary Bash aliases.
* Added persistent aliases to `.bashrc`.
* Viewed environment variables such as `HOME`, `PATH`, and variables listed by `env`.
* Created a `Scripts` directory and added it to the user `PATH`.
* Compared user-level `PATH` changes with global environment settings.
* Temporarily changed the Bash prompt using `PS1`.
* Created and executed simple Bash scripts:

  * `hello.sh`
  * `ff.sh`
  * `print.sh`
  * `print_files.sh`
* Verified that created scripts had executable permissions.
* Tested script execution through Bash, another shell, and direct execution through `PATH`.

## Tools Used

* Oracle VM VirtualBox
* Ubuntu Linux VM
* Linux terminal
* Bash shell
* `gedit` text editor
* `.bashrc` configuration file
* File manager
* Screenshot tools
* DOCX report template

## Commands / Technical Actions

Safe and useful commands practiced during the lab:

```bash
pwd
ls
touch fio.txt
echo "Text" >> file.txt
cat file.txt
cal
sort file.txt
sort -c file.txt
sort -ur file.txt
sort -o output.txt -u input.txt
head -n 2 file.txt
tail -n 1 file.txt
comm file1.txt file2.txt
wc -w file.txt
wc -m file.txt
grep pattern file.txt
grep -v pattern file.txt
find -name "*.txt"
find -maxdepth 1 -type f -not -name "*.txt"
alias
alias custom_alias='command'
source ~/.bashrc
echo $HOME
echo $PATH
env | more
mkdir Scripts
cat /etc/environment
sudo -i
echo $PS1
chmod a+x script.sh
which sh
bash script.sh
sh script.sh
```

Examples of Bash script concepts practiced:

```bash
#!/bin/bash
echo "Hello, world!"
```

```bash
#!/bin/bash
read name
echo "Hello, $name!"
```

```bash
#!/bin/bash
find ~ -maxdepth "$2" -type f -name "$1*"
```

```bash
#!/bin/bash
if [ -f "$1" ]; then
    cat "$1"
else
    echo "File not found"
fi
```

```bash
#!/bin/bash
files=`find ~ -maxdepth 1 -type f -name "$1*"`

for file in $files
do
    echo "----- $file -----"
    cat "$file"
done
```

## Problems Encountered

* The `cal` command was not available by default in the Ubuntu VM.
* Opening `.bashrc` with `sudo gedit` caused a graphical display authorization error.
* Opening `.bashrc` with `gedit` continued to show a permission-related error, even though the file ownership looked correct.
* The lab manual contained a likely typo in one alias command for finding `.txt` files.
* During later VM transfer preparation, copying the VM to a USB flash drive failed with an input/output error.
* On another PC, VirtualBox showed a warning about an inaccessible Guest Additions ISO file because the ISO path referenced the original Linux host location.

## How Problems Were Solved

* The missing `cal` command was solved by installing the package that provides it.
* The `.bashrc` editing issue was avoided by appending the required configuration directly from the terminal using heredoc redirection.
* The `.bashrc` file was checked afterward to confirm that only the intended alias and `PATH` lines were added.
* The incorrect alias from the lab manual was replaced with a correct command using `find -maxdepth 1 -type f -name "*.txt"`.
* The USB transfer error was investigated with `dmesg`, which showed USB reset and I/O errors. The flash drive was checked with `fsck.exfat`, reconnected to another USB port, and the transfer process was treated as unreliable unless verified.
* The VirtualBox Guest Additions warning on Windows was identified as non-fatal. The old ISO attachment could be removed from the VM storage settings because the installed guest OS boots from the virtual disk, not from the ISO.

## Skills Practiced

* Basic Bash command-line navigation.
* Text file creation and editing through shell redirection.
* Sorting and filtering text data.
* Comparing files.
* Counting words and characters in files.
* Searching files with `find`.
* Creating and using aliases.
* Making aliases persistent through `.bashrc`.
* Understanding user-level and global environment variables.
* Modifying the user `PATH`.
* Changing the shell prompt with `PS1`.
* Creating executable Bash scripts.
* Using positional parameters in scripts.
* Using conditional statements in Bash.
* Using loops in Bash scripts.
* Testing scripts from different directories.
* Basic troubleshooting of Linux command-line and VirtualBox issues.

## What I Learned

This lab helped me understand how Bash works as both an interactive shell and a scripting environment. I practiced creating files, redirecting command output, sorting and filtering text, and comparing files.

I also learned how aliases work, why aliases created in one terminal session disappear in a new session, and how `.bashrc` can be used to make them persistent. Adding a custom `Scripts` directory to `PATH` showed how Linux finds executable files.

The scripting part helped me understand the basics of Bash automation: using `#!/bin/bash`, reading user input, using script parameters like `$1` and `$2`, checking whether a file exists, and processing multiple files with a loop.

## GitHub Notes

Good items to include in the GitHub learning repository:

* A short explanation of the lab goal.
* A cleaned list of Bash commands practiced.
* Example scripts created during the lab.
* Notes about aliases, `.bashrc`, `PATH`, and `PS1`.
* A short troubleshooting section about missing commands, `.bashrc` editing issues, and VM transfer warnings.
* Personal learning notes about Bash scripting and environment configuration.

Items that should not be added to GitHub:

* Passwords or login credentials.
* Full names, group numbers, teacher names, or other personal academic details.
* Screenshots containing personal information.
* Full DOCX report contents intended for academic submission.
* Raw VM files or virtual disks.
* USB device identifiers if they are not needed.
* Any private file paths that reveal personal usernames or local system structure.
