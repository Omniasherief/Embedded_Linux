#!/bin/bash

# Set the maximum threshold for disk usage
MAX=90

# Check if a partition name is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <partition-name>"
    exit 1
fi

# Get the partition name from the first argument
PARTITION=$1

# Get disk usage for the specified partition
storage=$(df -h | grep "$PARTITION" | awk '{print $5}') # Use the provided partition name

# Check if the partition was found
if [ -z "$storage" ]; then
    echo "Partition $PARTITION not found."  # Update to the partition you're monitoring
    exit 1
fi

echo "Current Disk Usage for $PARTITION: $storage"

# Remove the percentage sign from the usage value
val=${storage::-1}

# Check if the last character was removed correctly
if [[ -z "$val" ]]; then
    echo "Error: Could not retrieve a valid percentage."
    exit 1
fi

echo "Usage Value (without %): $val"

# Check if the value is a valid integer
if ! [[ "$val" =~ ^[0-9]+$ ]]; then
    echo "Error: '$val' is not a valid number."
    exit 1
fi

# Compare the usage value with MAX
if [ "$val" -gt "$MAX" ]; then
    # Use sudo to retrieve the size of the Docker directory
    dockersize=$(sudo du -h -s /var/lib/docker/overlay2 | awk '{print $1}')
    
    # Send a notification with the disk and Docker directory sizes
    notify-send "Disk Usage Alert" "Disk Usage for $PARTITION: $storage\nDocker Size: $dockersize"
    
    # Open a terminal to continuously monitor disk usage
    /usr/bin/x-terminal-emulator -e "bash -c 'watch df -h'"
fi

# ./disk_monitor.sh   nvme0n1p1