#!/usr/bin/env bash

if [ "$1" = "--help" ]; then
    echo "Usage: ./memory-check.sh [limit_percent]"
    echo
    echo "Checks memory usage."
    echo "Default limit: 80"
    echo
    echo "Examples:"
    echo "  ./memory-check.sh"
    echo "  ./memory-check.sh 70"
    echo "  ./memory-check.sh 90"
    echo
    echo "Exit codes:"
    echo "  0 = OK"
    echo "  1 = WARNING: memory usage is above or equal to the limit"
    echo "  2 = ERROR: invalid argument"
    exit 0
fi

total=$(free | awk '/Mem:/ {print $2}')
used=$(free | awk '/Mem:/ {print $3}')

usage=$((used * 100 / total))

if [ -z "$1" ]; then
    limit=80
else
    limit="$1"
fi

if ! [[ "$limit" =~ ^[0-9]+$ ]]; then
    echo "ERROR: limit must be a number"
    echo "Usage: ./memory-check.sh [limit_percent]"
    echo "Example: ./memory-check.sh 80"
    exit 2
fi

echo "Memory usage: ${usage}%"
echo "Limit: ${limit}%"

if [ "$usage" -ge "$limit" ]; then
    echo "WARNING: memory usage is high"
    exit 1
else
    echo "OK: memory usage is normal"
    exit 0
fi
