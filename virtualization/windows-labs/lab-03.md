# Lab Summary: Practice 3 — Introduction to PowerShell

## Context

This lab was completed in a Windows 10 virtual machine running in Oracle VM VirtualBox on a Nobara Linux 43 KDE host system.

The main goal of the lab was to practice basic Windows PowerShell usage: working with cmdlets, aliases, help pages, pipelines, services, processes, files, variables, functions, and PowerShell scripts.

The work was performed inside the Windows VM using an elevated Windows PowerShell session. A temporary logical drive `G:` was mapped to a folder on the system drive and used as the working location for lab files and scripts.

## Main Tasks Completed

* Launched Windows PowerShell with administrator privileges.
* Checked the installed PowerShell version using `$PSVersionTable`.
* Created or reused a working folder and mapped it as a logical drive `G:`.
* Practiced searching PowerShell cmdlets with `Get-Command`.
* Used PowerShell help commands to inspect cmdlet syntax and parameters.
* Found and used aliases for common PowerShell cmdlets.
* Displayed and filtered running processes with `Get-Process`.
* Used pipelines with `Format-List`, `Format-Wide`, `Format-Table`, `Select-Object`, `Where-Object`, and `Get-Member`.
* Displayed process owner information with the `-IncludeUserName` parameter.
* Displayed, filtered, and sorted Windows services with `Get-Service`.
* Compared service search by internal service name and display name.
* Checked dependent and required services for a selected Windows service.
* Created and edited text files from PowerShell.
* Practiced file output using `Out-File`, including overwrite and append behavior.
* Created a file containing service information.
* Practiced file system navigation and listing with `Get-ChildItem`.
* Used recursive file search and sorted files by size.
* Practiced variables, conditional logic, and functions in PowerShell.
* Created and executed a basic `.ps1` script.
* Changed PowerShell script execution policy from `Restricted` to `RemoteSigned`.
* Created an interactive PowerShell script using `Read-Host`.
* Created a parameterized script that analyzes file sizes in a selected directory.
* Modified the script to accept both a path parameter and a numeric count parameter.

## Tools Used

* Oracle VM VirtualBox
* Windows 10 virtual machine
* Windows PowerShell
* Windows PowerShell running as Administrator
* Windows File Explorer
* Notepad
* PowerShell scripts with `.ps1` extension
* Virtual logical drive created with `subst`

## Commands / Technical Actions

Useful PowerShell commands and actions practiced during the lab:

```powershell
$PSVersionTable
```

```powershell
md C:\gcat
subst G: C:\gcat
G:
Get-Location
```

```powershell
Get-Command
Get-Command un*
Get-Command -Verb Uninstall
Get-Command -Noun Process
Get-Command *process*
```

```powershell
Get-Help Get-Process
Get-Help Get-Process -Detailed
Get-Help Get-Process -Parameter IncludeUserName
```

```powershell
Get-Alias
Get-Alias -Definition Get-Command
Get-Command help, man, Get-Help
```

```powershell
Get-Process
Get-Process m*
Get-Process m* | Format-List
Get-Process m* | Format-Wide
Get-Process m* | Format-Table
```

```powershell
Get-Process m* | Select-Object ProcessName, StartTime, MainWindowTitle, Path, Company
Get-Process msedgewebview2 | Format-List *
```

```powershell
Get-Process m* -IncludeUserName
Get-Process m* -IncludeUserName | Get-Member
Get-Process m* -IncludeUserName | Select-Object ProcessName, UserName
Get-Process m* -IncludeUserName | Where-Object {$_.UserName -eq "NT AUTHORITY\SYSTEM"}
```

```powershell
Get-Service
Get-Service -Name se*
Get-Service -DisplayName se*
Get-Service EventLog
Get-Service EventLog -DependentServices
Get-Service EventLog -RequiredServices
```

```powershell
Get-Service | Sort-Object Status
Get-Service | Where-Object {$_.Status -eq "Running"}
Get-Service | Where-Object {$_.Status -eq "Running"} | Sort-Object DisplayName
```

```powershell
"Ivanov" | Out-File G:\test.txt
Get-Content G:\test.txt
"Ivan" | Out-File G:\test.txt
"Ivanov" | Out-File G:\test.txt -Append
```

```powershell
Get-Service | Sort-Object Status | Out-File G:\test1.txt -Append
Get-Service | Where-Object {$_.Status -eq 'Running'} | Select-Object DisplayName | Out-File G:\test1.txt -Append
```

```powershell
Get-ChildItem C:\Windows\Logs
Get-ChildItem C:\Windows\Logs -Directory
Get-ChildItem C:\Windows\Logs -File | Sort-Object Length -Descending
Get-ChildItem C:\Windows\Logs -File -Recurse | Sort-Object Length -Descending | Select-Object -First 3
```

```powershell
$myvar = 18
$myvar | Out-File G:\test.txt -Append
```

```powershell
if ($myvar -lt 10) {$mystr = 'True'} else {$mystr = 'False'}
$mystr | Out-File G:\test.txt -Append
```

```powershell
function StudentFunction($a)
{
    return $a * $a
}
```

```powershell
$myvar2 = $myvar + 10
$result = StudentFunction $myvar2
$result | Out-File G:\test.txt -Append
```

```powershell
Get-Content G:\test.txt | Select-String -Pattern '18'
```

```powershell
Get-ExecutionPolicy
Set-ExecutionPolicy RemoteSigned
```

Example interactive script:

```powershell
Write-Host 'Hello, World!'
$UName = Read-Host 'What is your name?'
Write-Host "Hello, $UName"
Get-Date
Wait-Event -Timeout 5
```

Example parameterized file information script:

```powershell
Param (
    [string]$path,
    [int]$count
)

Write-Host "Largest files:"
Get-ChildItem $path -File -Recurse | Sort-Object Length -Descending | Select-Object -First $count

Write-Host "Smallest files:"
Get-ChildItem $path -File -Recurse | Sort-Object Length | Select-Object -First $count
```

Example script execution:

```powershell
G:\FileInfo.ps1 C:\Windows\Logs 3
```

## Problems Encountered

* The working folder `C:\gcat` already existed when the folder creation command was executed.
* The Windows VM did not have a Russian keyboard layout, and Cyrillic text input caused incorrect characters to appear.
* The logical drive `G:` created with `subst` in an elevated PowerShell session was not visible in normal File Explorer.
* `Get-Alias -Definition Get-Help` did not return a direct alias for `Get-Help`.
* The first attempt to run a `.ps1` script failed because PowerShell script execution was blocked by the `Restricted` execution policy.
* Some command outputs were too long to fit conveniently into a single screenshot.

## How Problems Were Solved

* The existing `C:\gcat` folder was reused instead of recreating it.
* Latin transliteration was used for text input instead of Cyrillic, which made the file contents readable and avoided keyboard layout issues.
* The file was opened from the same elevated PowerShell session using Notepad, or through the real folder path behind the mapped drive.
* `Get-Command help, man, Get-Help` was used to inspect how help-related commands are represented in PowerShell.
* The script execution policy was changed to `RemoteSigned`, which allowed locally created scripts to run while keeping a safer policy than `Unrestricted` or `Bypass`.
* Long outputs were documented with grouped screenshots and shorter commands such as `-TotalCount`, `-Tail`, and `Select-Object -First`.

## Skills Practiced

* Running PowerShell as Administrator.
* Using PowerShell cmdlets and aliases.
* Reading cmdlet documentation with `Get-Help`.
* Searching commands with `Get-Command`.
* Understanding PowerShell object-based output.
* Building command pipelines.
* Filtering objects with `Where-Object`.
* Selecting object properties with `Select-Object`.
* Formatting output with `Format-List`, `Format-Wide`, and `Format-Table`.
* Inspecting object properties with `Get-Member`.
* Working with Windows processes and services.
* Creating, overwriting, appending, and reading text files.
* Navigating and inspecting the Windows file system.
* Sorting files and services.
* Using variables and conditional logic.
* Creating and calling simple functions.
* Creating and running PowerShell scripts.
* Working with script execution policy.
* Creating interactive scripts with user input.
* Creating parameterized scripts.

## What I Learned

This lab showed how PowerShell differs from the classic Windows Command Prompt. PowerShell works with objects, not just plain text, which makes it useful for filtering, sorting, and selecting specific properties.

I practiced how to combine cmdlets into pipelines and how to use commands such as `Where-Object`, `Select-Object`, and `Sort-Object` to process data. I also learned how PowerShell handles file output, including the difference between overwriting a file and appending data to it.

Another important part of the lab was script execution. I learned that Windows may block `.ps1` scripts by default through the execution policy, and that `RemoteSigned` is a safer practical option for running locally created scripts during lab work.

## GitHub Notes

Recommended to include in the GitHub learning repository:

* A cleaned Markdown summary of the lab.
* Safe PowerShell command examples.
* General notes about PowerShell pipelines, aliases, services, processes, and scripts.
* Example sanitized scripts such as:

  * a basic interactive script;
  * a parameterized file information script.
* A short explanation of problems encountered and how they were solved.

Not recommended to include:

* Full academic report document.
* Screenshots from the VM.
* Personal names, group information, teacher information, or title page data.
* Any account names, local paths containing personal data, passwords, or private system details.
* Raw large outputs from service/process listings unless sanitized and shortened.
* Files from the VM that contain personal or identifying information.
