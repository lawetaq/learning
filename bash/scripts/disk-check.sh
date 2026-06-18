#!/usr/bin/env bash

if [ "$1" = "--help" ]; then
    echo "Usage: ./disk-check.sh [limit_percent]"
    echo
    echo "Checks root disk usage."
    echo "Default limit: 90"
    echo
    echo "Examples:"
    echo "  ./disk-check.sh"
    echo "  ./disk-check.sh 85"
    echo "  ./disk-check.sh 95"
    echo
    echo "Exit codes:"
    echo "  0 = OK"
    echo "  1 = WARNING: disk usage is above or equal to the limit"
    echo "  2 = ERROR: invalid argument"
    exit 0
fi

usage=$(df / | tail -n 1 | awk '{print $5}' | tr -d '%')

if [ -z "$1" ]; then
    limit=90
else
    limit="$1"
fi

if ! [[ "$limit" =~ ^[0-9]+$ ]]; then
    echo "ERROR: limit must be a number"
    echo "Example: ./disk-check.sh 90"
    exit 2
fi

echo "Root disk usage: ${usage}%"
echo "Limit: ${limit}%"

if [ "$usage" -ge "$limit" ]; then
    echo "WARNING: root disk usage is high"
    exit 1
else
    echo "OK: root disk usage is normal"
    exit 0
fi
