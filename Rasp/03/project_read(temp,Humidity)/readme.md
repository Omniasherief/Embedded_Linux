# Raspberry Pi Sensor Logger & Data Transfer

## Project Overview

This project enables real-time collection, logging, and visualization of temperature and humidity sensor data on a Raspberry Pi. The data is logged into a CSV file and transferred to a remote PC for further analysis using a Python-based GUI.

## Components

1. **C++ Application (`sensor_logger.cpp`)** – Reads sensor data and writes it to a CSV file.
2. **Python GUI (`gui_display.py`)** – Displays recorded temperature and humidity data.
3. **Bash Script (`transfer_csv.sh`)** – Transfers the CSV file from Raspberry Pi to a PC via SCP.

---

## File Breakdown & Execution

### 1. C++ Sensor Logger (`sensor_logger.cpp`)

- **Purpose:** Simulates or reads actual sensor data and logs it to a CSV file.
- **Target Device:** Raspberry Pi (can also be tested on a PC).
- **Compilation & Execution:**
  ```sh
  g++ sensor_logger.cpp -o sensor_logger
  ./sensor_logger
  ```
- **Cross-compilation for Raspberry Pi:**
  ```sh
  arm-linux-gnueabihf-g++ sensor_logger.cpp -o sensor_logger
  ```

### 2. Python GUI (`gui_display.py`)

- **Purpose:** Reads `sensor_data.csv` and provides a graphical display of average temperature and humidity.
- **Target Device:** PC (or Raspberry Pi with a display).
- **Execution:**
  ```sh
  python3 gui_display.py
  ```

### 3. Bash Script for Data Transfer (`transfer_csv.sh`)

- **Purpose:** Automates the transfer of `sensor_data.csv` from Raspberry Pi to a remote PC using SCP.
- **Execution:**
  ```sh
  chmod +x transfer_csv.sh
  ./transfer_csv.sh
  ```
- **Automate with Cron Job (Runs Every Hour):**
  ```sh
  crontab -e
  0 * * * * /path/to/transfer_csv.sh
  ```

---

## Deployment on Raspberry Pi

### Steps:

1. **Cross-compile and transfer the binary to Raspberry Pi:**
   ```sh
   arm-linux-gnueabihf-g++ sensor_logger.cpp -o sensor_logger
   scp sensor_logger pi@192.168.X.X:/home/pi/
   ```
2. **Run the C++ application on the Pi:**
   ```sh
   ssh pi@192.168.X.X
   ./sensor_logger
   ```
3. **Configure and run the transfer script:**
   - Update `transfer_csv.sh` with your PC’s IP & username.
   - Enable passwordless SSH login for automatic transfers.
   - Execute:
     ```sh
     chmod +x transfer_csv.sh
     ./transfer_csv.sh
     ```

---

## Troubleshooting & Fixes

### 1. Password Prompt in SCP (Fix SSH Key Authentication)

- Set up SSH keys on the Raspberry Pi to enable passwordless login:
  ```sh
  ssh-keygen -t rsa
  ssh-copy-id user@192.168.X.X
  ```

### 2. Crontab Not Executing the Script

- Ensure the script has executable permissions.
- Use absolute paths inside the script.
- Add to crontab with:
  ```sh
  crontab -e
  SHELL=/bin/bash
  0 * * * * /absolute/path/to/transfer_csv.sh
  ```

### 3. Version Compatibility Issues (GCC Version Mismatch)

- Verify the installed cross-compiler version:
  ```sh
  arm-linux-gnueabihf-g++ --version
  ```
- If needed, install a compatible version:
  ```sh
  sudo apt install g++-arm-linux-gnueabihf
  ```

---

## Final Notes

- **Ensure correct IP Address & Username in scripts.**
- **Set up SSH access properly before enabling automation.**
- **Run scripts manually before automating to verify functionality.**
- **Modify paths and configurations as needed for your setup.**

