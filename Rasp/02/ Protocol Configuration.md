### Configuring Communication Protocols on Raspberry Pi

Depending on which protocol you need to configure, here are the steps for setting up **UART, I2C, and SPI** on Raspberry Pi.

---

## **1. Enable Protocols in Raspberry Pi Configuration**
Before using any communication protocol, you must enable it in the Raspberry Pi settings.

### **Option 1: Using `raspi-config`**
1. Open the terminal and type:
   ```bash
   sudo raspi-config
   ```
2. Navigate to **"Interfacing Options"**.
3. Enable the protocol you need:
   - **I2C** → Enable
   - **SPI** → Enable
   - **Serial (UART)** → Disable login shell, then enable serial port.
4. Reboot the Raspberry Pi:
   ```bash
   sudo reboot
   ```

---

## **2. Configuring UART (Serial Communication)**
### **Checking UART Status**
- To check if UART is enabled, run:
  ```bash
  ls -l /dev/serial*
  ```
  - You should see `/dev/serial0` (default UART port) and `/dev/serial1` (secondary port if available).

### **Disabling the Console Login (If Needed)**
- Open the boot configuration file:
  ```bash
  sudo nano /boot/config.txt
  ```
- Add or modify these lines at the end:
  ```bash
  enable_uart=1
  ```
- Save the file (CTRL+X → Y → ENTER) and reboot:
  ```bash
  sudo reboot
  ```

### **Testing UART Communication**
- Connect a USB-TTL adapter to the Raspberry Pi **TX (GPIO14)** and **RX (GPIO15)**.
- Install `minicom`:
  ```bash
  sudo apt-get install minicom
  ```
- Open the serial monitor:
  ```bash
  minicom -b 115200 -o -D /dev/serial0
  ```

---

## **3. Configuring I2C (Inter-Integrated Circuit)**
### **Enable I2C Kernel Module**
1. Open the I2C configuration file:
   ```bash
   sudo nano /boot/config.txt
   ```
2. Add the following lines (if not already present):
   ```bash
   dtparam=i2c_arm=on
   ```
3. Save and reboot:
   ```bash
   sudo reboot
   ```

### **Check I2C Devices**
- Install I2C tools:
  ```bash
  sudo apt-get install i2c-tools
  ```
- Check connected I2C devices:
  ```bash
  i2cdetect -y 1
  ```
  - This will show addresses of connected I2C devices.

### **Testing I2C Communication**
#### **Master (Raspberry Pi)**
- Install `smbus` for I2C communication:
  ```bash
  sudo apt-get install python3-smbus
  ```
- Example Python code for I2C communication:
  ```python
  import smbus
  import time

  bus = smbus.SMBus(1)  # Use bus 1
  slave_address = 0x04   # Example address of slave device

  while True:
      bus.write_byte(slave_address, 0x42)  # Send byte
      time.sleep(1)
  ```

---

## **4. Configuring SPI (Serial Peripheral Interface)**
### **Enable SPI Kernel Module**
1. Open the boot configuration file:
   ```bash
   sudo nano /boot/config.txt
   ```
2. Ensure this line is present:
   ```bash
   dtparam=spi=on
   ```
3. Save and reboot:
   ```bash
   sudo reboot
   ```

### **Check SPI Devices**
- Check available SPI devices:
  ```bash
  ls /dev/spidev*
  ```
  - You should see `/dev/spidev0.0` and `/dev/spidev0.1`.

### **Testing SPI Communication**
- Install `spidev` Python library:
  ```bash
  sudo pip3 install spidev
  ```
- Example Python code for SPI communication:
  ```python
  import spidev

  spi = spidev.SpiDev()
  spi.open(0, 0)  # Open SPI bus 0, device 0
  spi.max_speed_hz = 50000

  data = [0x01, 0x02, 0x03]  # Example data
  response = spi.xfer2(data)

  print("Received:", response)
  ```


