# Raspberry Pi Network Debugging Log

## Overview
This repository documents the troubleshooting process for networking issues on a Raspberry Pi, focusing on SSH connectivity, route configuration, and interface prioritization.

## Problem Description
The Raspberry Pi has multiple network interfaces (Ethernet and Wi-Fi), and SSH over Wi-Fi (`wlan0`) was failing when unplugging the Ethernet cable (`eth0`). The goal is to ensure that the Raspberry Pi reliably uses the `BORM` Wi-Fi network for SSH access and internet connectivity.

## Debugging Steps

### 1. Checking Active Connections
```bash
nmcli connection show --active
```
**Output:**
```
NAME                UUID                                  TYPE      DEVICE
Wired connection 1  3d15671a-668c-3fc1-98a4-4725352487d9  ethernet  eth0   
BORM                2035459d-f756-4058-8f93-1cd6f67e045d  wifi      wlan0   
```

### 2. Verifying Network Interfaces and Routes
```bash
ip route show
```
**Output:**
```
default via 192.168.1.1 dev wlan0 proto dhcp src 192.168.1.65 metric 600
default via 192.168.1.1 dev eth0 proto dhcp src 192.168.1.17 metric 100
192.168.1.0/24 dev eth0 proto kernel scope link src 192.168.1.17 metric 100
192.168.1.0/24 dev wlan0 proto kernel scope link src 192.168.1.65 metric 600
```

### 3. Testing SSH Over Wi-Fi
```bash
ssh omnia@192.168.1.65
```
- **Issue:** SSH works initially but freezes when `eth0` is unplugged.
- **Possible Cause:** `eth0` is prioritized over `wlan0`, causing connection loss when unplugged.

### 4. Checking Connectivity
```bash
ping google.com
```
- **Issue:** Internet may not work consistently on `wlan0` when `eth0` is unplugged.

## Solution: Prioritizing Wi-Fi Over Ethernet
1. **Delete or Modify Ethernet Route** (if not needed for SSH)
   ```bash
   sudo ip route del default via 192.168.1.1 dev eth0
   ```
2. **Set Higher Priority for `wlan0`**
   ```bash
   sudo ip route add default via 192.168.1.1 dev wlan0 metric 50
   ```
3. **Restart Networking Services**
   ```bash
   sudo systemctl restart networking
   ```

## Conclusion
- The Raspberry Pi was initially prioritizing `eth0` for network access.
- SSH connections would drop when `eth0` was unplugged.
- Modifying routing priorities resolved the issue, ensuring stable SSH access over Wi-Fi (`BORM`).

### Next Steps
- Automate route prioritization using a startup script.
- Ensure `BORM` remains the primary network even after reboots.

---
**Author:** Omnia



