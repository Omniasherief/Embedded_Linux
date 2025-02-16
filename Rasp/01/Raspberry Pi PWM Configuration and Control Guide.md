Here’s an updated version of your guide with an additional section on moving from VSCode on your PC to the Raspberry Pi:

---

# Raspberry Pi PWM Configuration and Control Guide

## 1. Overview
This guide explains how to enable and configure Pulse Width Modulation (PWM) on a Raspberry Pi using hardware-supported GPIO pins. It also covers the necessary steps to modify the configuration file, verify the PWM setup, and control PWM using both command-line and Python scripts.

---

## 2. Hardware PWM-Capable GPIO Pins
The following GPIO pins on the Raspberry Pi support **hardware PWM**:

| **GPIO Pin** | **PWM Channel** | 
|--------------|-----------------|
| **GPIO 12**  | PWM0 (Channel 0) | 
| **GPIO 13**  | PWM1 (Channel 1) | 
| **GPIO 18**  | PWM0 (Channel 0) | 
| **GPIO 19**  | PWM1 (Channel 1) | 

To use PWM on these pins, you need to configure them in the Raspberry Pi’s boot configuration file.

---

## 3. Enabling PWM via `config.txt`
To enable PWM, modify the **config.txt** file located in `/boot/firmware/`.

### **Steps to Enable PWM:**
1. Open the configuration file:
   ```bash
   sudo nano /boot/firmware/config.txt
   ```
2. Add the following line to enable PWM on the desired GPIO pin. Replace `pin=12` with the appropriate pin for your setup:
   ```bash
   dtoverlay=pwm-2chan,pin=12,func=4
   ```
   - **GPIO 12, 13** → Use `func=4`
   - **GPIO 18, 19** → Use `func=2`

   **Example Configurations:**
   - **GPIO 12 (PWM0):**
     ```bash
     dtoverlay=pwm-2chan,pin=12,func=4
     ```
   - **GPIO 13 (PWM1):**
     ```bash
     dtoverlay=pwm-2chan,pin=13,func=4
     ```
   - **GPIO 18 (PWM0):**
     ```bash
     dtoverlay=pwm-2chan,pin=18,func=2
     ```
   - **GPIO 19 (PWM1):**
     ```bash
     dtoverlay=pwm-2chan,pin=19,func=2
     ```

3. Save and exit the editor (`CTRL+X`, then `Y`, then `Enter`).
4. Reboot the Raspberry Pi for the changes to take effect:
   ```bash
   sudo reboot
   ```

---

## 4. Verifying PWM Configuration
After rebooting, check if the PWM module is loaded by listing the `/sys/class/pwm` directory:
```bash
ls /sys/class/pwm
```
You should see directories like `pwmchip0` or `pwmchip1` if PWM is successfully enabled.

To manually enable PWM:
```bash
echo 0 > /sys/class/pwm/pwmchip0/export
```

---

## 5. Controlling PWM from the Command Line
Once PWM is enabled, you can control it from the command line.

### **Steps:**
1. Navigate to the PWM directory:
   ```bash
   cd /sys/class/pwm/pwmchip0
   ```
2. Export PWM0:
   ```bash
   echo 0 | sudo tee export
   ```
3. Set the PWM period (1ms = 1,000,000 ns):
   ```bash
   echo 1000000 | sudo tee pwm0/period
   ```
4. Set the duty cycle (e.g., 50% duty cycle):
   ```bash
   echo 500000 | sudo tee pwm0/duty_cycle
   ```
5. Enable PWM output:
   ```bash
   echo 1 | sudo tee pwm0/enable
   ```

---

## 6. Using Python for PWM Control
You can control PWM in Python using the `RPi.GPIO` library.

### **Steps:**
1. Install the `RPi.GPIO` library (if not already installed):
   ```bash
   pip install RPi.GPIO
   ```

2. Write a Python script to control PWM (example: LED brightness control).

   **Python Script:**
   ```python
   import RPi.GPIO as GPIO
   from time import sleep

   led_pin = 12  # Change based on your setup
   GPIO.setwarnings(False)
   GPIO.setmode(GPIO.BOARD)
   GPIO.setup(led_pin, GPIO.OUT)

   pi_pwm = GPIO.PWM(led_pin, 1000)  # Set frequency to 1kHz
   pi_pwm.start(0)  # Start with 0% duty cycle

   while True:
       for duty in range(0, 101, 1):
           pi_pwm.ChangeDutyCycle(duty)
           sleep(0.01)
       for duty in range(100, -1, -1):
           pi_pwm.ChangeDutyCycle(duty)
           sleep(0.01)
   ```

3. Run the script:
   ```bash
   python3 led_pwm.py
   ```

---

## 7. Cross-Compiling C/C++ Code for Raspberry Pi
Cross-compilation allows you to build executables on a PC and transfer them to the Raspberry Pi.

### **Steps:**
1. **Install a cross-compiler** on your PC (Linux):
   ```bash
   sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
   ```

2. **Write the C program** (example: `led.c`):
   ```c
   #include <wiringPi.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>

   #define LED 12

   int main() {
       wiringPiSetupGpio();
       pinMode(LED, PWM_OUTPUT);
       pwmWrite(LED, 512);  // 50% duty cycle
       sleep(5);
       pwmWrite(LED, 0);
       return 0;
   }
   ```

3. **Cross-compile the C program**:
   ```bash
   arm-linux-gnueabihf-gcc -o led led.c -lwiringPi
   ```

4. **Transfer the compiled binary** to the Raspberry Pi:
   ```bash
   scp led omnia@raspberrypi.local:/home/omnia/
   ```

5. **Run the program** on Raspberry Pi:
   ```bash
   chmod +x led
   ./led
   ```

---

## 8. Moving Code from VSCode on Your PC to Raspberry Pi
To easily move and run your code from VSCode on your PC to the Raspberry Pi, follow these steps:

### **Steps to Set Up Remote Development:**
1. **Install the Remote - SSH Extension** in VSCode:
   - Open VSCode on your PC and go to the **Extensions** view.
   - Search for and install **Remote - SSH**.

2. **Connect VSCode to your Raspberry Pi**:
   - Click on the green bottom-left corner of VSCode to open the **Remote Explorer**.
   - Select **Remote-SSH: Connect to Host...** and enter the Raspberry Pi's IP address or hostname (e.g., `raspberrypi.local`).
   - Enter your Raspberry Pi credentials to establish the connection.

3. **Open a Folder on Raspberry Pi**:
   - Once connected, navigate to a folder on your Raspberry Pi where you want to work.
   - You can now edit files directly on the Raspberry Pi as if you were working locally.

4. **Transfer Code via SSH**:
   - Alternatively, you can use the `scp` (secure copy) command to transfer files from your PC to the Raspberry Pi:
     ```bash
     scp /path/to/your/script.py omnia@raspberrypi.local:/home/omnia/
     ```

5. **Run and Test Code Remotely**:
   - After editing or transferring your code, you can run and test it directly from your Raspberry Pi terminal or within VSCode’s integrated terminal.

---

## 9. Troubleshooting
If PWM is not working as expected, check the following:

1. **If `gpio readall` fails**: Ensure WiringPi is installed or use the sysfs method for GPIO control.
2. **If `wiringPi` doesn’t work**: Use the `/sys/class/pwm` approach, or update WiringPi manually.
3. **Verify PWM status**:
   ```bash
   dmesg | grep pwm
   ```
   If no PWM message appears, recheck the `/boot/firmware/config.txt` changes.

---

## 10. Conclusion
This guide covers enabling PWM on the Raspberry Pi through both the **device tree** and **sysfs** methods, controlling PWM from the command line, using Python scripts for PWM control, and cross-compiling C programs for the Raspberry Pi. Additionally, we have outlined the steps for setting up a seamless development environment by moving code from your PC to Raspberry Pi using VSCode and SSH.
