#!/usr/bin/env bash

script_dir="$(cd "$(dirname "$0")" && pwd)"

echo "Server Status"
echo "-------------"
echo "Hostname: $(hostname)"
echo "Date: $(date)"
echo "Uptime: $(uptime -p)"
echo

echo "Disk check:"
"$script_dir/disk-check.sh"
echo

echo "Memory check:"
"$script_dir/memory-check.sh"
