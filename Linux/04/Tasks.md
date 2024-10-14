
### 1. Catch Interrupt Signal and Print Exit Before Termination

You can create a simple shell script that handles the SIGINT signal (Ctrl+C) and prints a message before exiting.

```bash
#!/bin/bash

# Function to handle SIGINT
cleanup() {
    echo "Exiting gracefully..."
    exit 0
}

# Trap SIGINT
trap cleanup SIGINT

# Keep the script running
echo "Press Ctrl+C to exit."
while true; do
    sleep 1
done
```

### 2. Kill All Firefox Processes

You can use the `pkill` command to kill all Firefox processes directly in the terminal:

```bash
pkill firefox
```

### 3. Access Your PC via SSH

To enable SSH access on your machine:

1. Install OpenSSH server:
   - For Ubuntu/Debian:
     ```bash
     sudo apt update
     sudo apt install openssh-server
     ```

2. Start the SSH service:
   ```bash
   sudo systemctl start ssh
   ```

3. Enable it to start on boot:
   ```bash
   sudo systemctl enable ssh
   ```

4. Find your local IP address:
   ```bash
   hostname -I
   ```

5. Connect to your PC from another machine:
   ```bash
   ssh username@your_ip_address
   ```

### 4. Create Users, Add to Sudoers Group, Then Delete Them

Here's a script that creates users, adds them to the `sudo` group, and then deletes them:

```bash
#!/bin/bash

# Create users
for i in {1..3}; do
    username="user$i"
    sudo useradd -m -s /bin/bash $username
    sudo usermod -aG sudo $username
done

# List users
echo "Users created:"
getent passwd | grep user

# Delete users
for i in {1..3}; do
    username="user$i"
    sudo userdel -r $username
done

echo "Users deleted."
```

### 5. Mount and Unmount Flash Drive

Assuming your flash drive is located at `/dev/sdb1` and you want to mount it to `/mnt/usb`:

```bash
# Create a mount point
sudo mkdir -p /mnt/usb

# Mount the flash drive
sudo mount /dev/sdb1 /mnt/usb

# Unmount the flash drive
sudo umount /mnt/usb
```

### 6. Clear SD Card and Write Random Values

To clear an SD card and write random values to it (replace `/dev/sdc` with the correct device path for your SD card):

```bash
# Clear the SD card (WARNING: This will erase all data!)
sudo dd if=/dev/zero of=/dev/sdc bs=4M status=progress

# Write random values to the SD card
sudo dd if=/dev/urandom of=/dev/sdc bs=4M status=progress
```

### Important Notes:
- **Backup Data:** Always back up your data before running commands that can delete or modify disk content.
- **Permissions:** You might need to run these commands with `sudo` for proper permissions.
- **Device Identification:** Be careful with device paths (`/dev/sdb1`, `/dev/sdc`, etc.) to avoid data loss on the wrong device. You can check connected devices with `lsblk`.
