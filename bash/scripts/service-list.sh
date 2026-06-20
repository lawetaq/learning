#!/usr/bin/env bash

services=("NetworkManager" "sshd" "docker")

for service in "${services[@]}"; do
    if ! systemctl cat "$service" >/dev/null 2>&1; then
        echo "ERROR: $service not found"
        continue
    fi

    status=$(systemctl is-active "$service")

    if [ "$status" = "active" ]; then
        echo "OK: $service is active"
    else
        echo "WARNING: $service is $status"
    fi
done
