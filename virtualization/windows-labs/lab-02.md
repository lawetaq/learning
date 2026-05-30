# Lab Summary: Windows CMD Basics / Command Line Practice

## Context

This lab was completed in a Windows 10 virtual machine running in Oracle VM VirtualBox. The host system was Nobara Linux 43 KDE.

The goal of the practice was to learn basic Windows command-line operations: navigating directories, creating and managing files and folders, using redirection and pipes, working with command filters, and creating simple batch scripts.

The work was done inside a Windows VM using `cmd.exe`. A removable USB drive was also connected to the virtual machine to practice volume label commands.

## Main Tasks Completed

* Opened and used Windows Command Prompt.
* Checked the Windows version with `ver`.
* Practiced basic system commands such as `cls`, `date`, `time`, `path`, and `doskey`.
* Created directories on the `C:` drive.
* Created a virtual drive using `subst`.
* Connected a USB drive to the Windows VM through VirtualBox USB passthrough.
* Checked and confirmed the USB volume label.
* Created a directory tree on a virtual `G:` drive.
* Navigated between directories using absolute and relative paths.
* Listed files and directories with different `dir` options.
* Created and edited text files from the command line.
* Copied, renamed, moved, and deleted files.
* Used file masks such as `*.txt`, `*.PNF`, `*.HLP`, and `D*.*`.
* Used output redirection with `>` and `>>`.
* Used input redirection with `<`.
* Used pipes with `|`.
* Practiced command filters such as `more`, `sort`, `findstr`, and `clip`.
* Created and tested batch files.
* Modified a batch file to accept command-line parameters.
* Solved an individual command-line/path task based on file paths and relative references.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 virtual machine
* Nobara Linux 43 KDE host system
* Windows Command Prompt (`cmd.exe`)
* Windows Notepad
* VirtualBox USB passthrough
* File manager
* Microsoft Word / LibreOffice Writer for the final report
* PDF export for checking the final document

## Commands / Technical Actions

Safe and useful commands practiced during the lab:

```cmd
cls
ver
date
time
path
doskey /?
```

Directory navigation and structure:

```cmd
cd \
cd /D C:\LABOS
cd /D G:\LAB\LAB1
md gcat
md labos
md G:\TEMP
md G:\TEMP\TEMP1
md G:\LAB
md G:\LAB\LAB1
tree G:
```

Virtual drive creation:

```cmd
subst G: \gcat
dir G:
```

USB volume checking:

```cmd
wmic logicaldisk get name,volumename,description
label E:
vol E:
```

File and directory listing:

```cmd
dir C:\Windows
dir C:\Windows /P
dir C:\Windows /W /P
dir C:\Windows\*.exe /P /O:S
dir C:\Windows\*.exe /P /O:-S
dir C:\Windows /P /O:N /A:D
dir C:\Windows\win.ini /Q
```

Text file creation and viewing:

```cmd
copy con \LAB\TEXT.TXT
type \LAB\TEXT.TXT
copy \LAB\TEXT.TXT con
more \LAB\TEXT.TXT
```

File operations:

```cmd
copy \LAB\TEXT.TXT TEXT1.TXT
ren TEXT1.TXT FAM.*
move FAM.TXT \LAB
copy C:\Windows\INF\*.PNF \TEMP\TEMP1
ren \TEMP\TEMP1\*.PNF *.HLP
move \TEMP\TEMP1\D*.* \TEMP
del \TEMP\TEMP1\*.*
rd \TEMP\TEMP1
```

Redirection, filters, and pipes:

```cmd
DIR C:\ > \LAB\c.dir
MORE \LAB\c.dir
DIR /? | MORE
TYPE \LAB\FAM.TXT | SORT
SORT /R < \LAB\FAM.TXT > \FAM1.TXT
SORT /R < CON > \LAB\NUM.TXT
SORT /? > \LAB\LAB1\HELP.TXT
COPY /? >> \LAB\LAB1\HELP.TXT
MORE \LAB\LAB1\HELP.TXT
```

Batch file examples:

```bat
CLS
DIR /S %1
DIR /S %1 | FINDSTR %2
DIR /S %1 | FINDSTR %2 | CLIP
PAUSE
TREE /F %1
PAUSE
```

Example batch launch with parameters:

```cmd
C:\LABOS\VIEW.BAT G: .HLP
```

## Problems Encountered

* The USB drive did not appear in the Windows VM at first.
* VirtualBox showed USB devices by hardware/controller name instead of the drive label, which made it unclear which device was the flash drive.
* A keyboard-like USB device was accidentally selected in the VirtualBox USB menu, causing the keyboard to briefly disconnect.
* While appending names to a text file, one line was joined incorrectly because the previous file content did not end with a clean line break.
* A command for adding text to the beginning of a file caused an overwrite prompt, which made the process confusing.
* A file copy command was accidentally repeated, causing Windows to ask whether existing files should be overwritten.
* The first generated DOCX report had white horizontal artifacts on inserted screenshots.
* Some commands in the lab manual were outdated, awkward, or easy to mistype.

## How Problems Were Solved

* The USB drive was identified on the Linux host using:

```bash
lsblk -o NAME,SIZE,FSTYPE,LABEL,MODEL,MOUNTPOINTS
lsusb
```

* The correct USB device was matched to the flash drive and passed through to the Windows VM using VirtualBox.
* The incorrect USB device was avoided after it was identified as unrelated to the flash drive.
* The text file was recreated cleanly with the correct final content instead of keeping the broken intermediate version.
* The repeated file copy operation was safely interrupted with `Ctrl+C`, then the target directory was checked with `dir`.
* Screenshot artifacts in the DOCX were fixed by regenerating the document with images saved without transparency.
* The final document was also exported to PDF to confirm that the display issue was resolved.

## Skills Practiced

* Basic Windows command-line navigation.
* Understanding current directory behavior.
* Using absolute and relative paths.
* Creating and deleting directories.
* Copying, renaming, moving, and deleting files.
* Using file masks and wildcards.
* Viewing and sorting command output.
* Redirecting command output into files.
* Appending command output to existing files.
* Passing command output through pipes.
* Using simple filters such as `sort`, `more`, `findstr`, and `clip`.
* Creating and running `.bat` scripts.
* Using batch parameters such as `%1` and `%2`.
* Connecting USB devices to a VM through VirtualBox.
* Troubleshooting command-line mistakes safely.
* Preparing a clean technical report from practical work.

## What I Learned

This lab showed how Windows file system operations can be performed from the command line instead of the graphical file manager.

The most important concepts were:

* The command prompt always works relative to the current directory.
* Absolute paths point to a full location, while relative paths depend on the current location.
* File masks such as `*.txt` and `D*.*` are useful for batch operations.
* Redirection allows command output to be saved into files.
* Pipes allow one command to pass its output to another command.
* Batch files can automate repeated command sequences.
* Parameters such as `%1` and `%2` make batch files reusable for different directories and file types.

The lab also showed that `cmd.exe` is not always convenient for everyday Windows use, but it is useful for automation, troubleshooting, and understanding how commands work behind the graphical interface.

## GitHub Notes

Good material to add to the GitHub learning repository:

* A short explanation of Windows command-line navigation.
* Examples of safe commands used for listing, copying, moving, and renaming files.
* Notes about absolute vs relative paths.
* Examples of redirection and pipes.
* A cleaned-up example of a `.bat` file with parameters.
* A short troubleshooting section about USB passthrough in VirtualBox.
* A note about screenshot/document formatting issues and how they were fixed.

Do not add:

* Full academic report text.
* Screenshots containing personal names, group information, teacher names, or local user details.
* Full directory listings if they contain identifying information.
* Raw Word/PDF report files prepared for submission.
* Any personal data from the title page.
* Excessive screenshots from the VM.
* Mistyped commands unless they are included as a short troubleshooting note.
