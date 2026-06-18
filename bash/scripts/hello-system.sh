#!/usr/bin/env bash

name="lawetaq"
today=$(date)
current_dir=$(pwd)
current_user=$(whoami)
host=$(hostname)

echo "Hello, $name"
echo "Today is: $today"
echo "Current directory: $current_dir"
echo "Current user: $current_user"
echo "Hostname: $host"
