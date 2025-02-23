### **Connecting Raspberry Pi 4 to Another Device via Serial (UART)**  

Since you want to control the LED **via serial**, you need to **physically connect the Raspberry Pi's UART pins** to another device, like a PC or another Raspberry Pi.  

---

## **1️⃣ Raspberry Pi Serial (UART) Pinout**
The Raspberry Pi has a **UART interface** on **GPIO14 (TX) and GPIO15 (RX)**.

| **Raspberry Pi Pin** | **Function** |
|----------------------|-------------|
| **Pin 8 (GPIO14)** | **TX (Transmit)** |
| **Pin 10 (GPIO15)** | **RX (Receive)** |
| **Pin 6** | **GND** |

---

## **2️⃣ Wiring Raspberry Pi to Another Device (PC or Raspberry Pi)**
There are two ways to connect the Raspberry Pi serially:

### **A) Using USB-to-TTL Converter (Recommended for PC)**
If you're connecting the Raspberry Pi to a **PC**, use a **USB-to-TTL converter**.

#### **🛠 Required Components**
- USB-to-TTL Serial Adapter  
- 3x Female-to-Female Jumper Wires  

#### **📌 Wiring Raspberry Pi to USB-TTL**
| **Raspberry Pi** | **USB-TTL Adapter** |
|------------------|--------------------|
| **Pin 8 (GPIO14 - TX)** | **RX (Receive)** |
| **Pin 10 (GPIO15 - RX)** | **TX (Transmit)** |
| **Pin 6 (GND)** | **GND** |

✅ **Make sure TX and RX are crossed** (Raspberry Pi TX → USB-TTL RX, and vice versa).  

🔌 **Connect the USB-TTL adapter to your PC's USB port**.

---

### **B) Direct Raspberry Pi to Raspberry Pi Connection**
If you're connecting **two Raspberry Pi devices directly**, wire them as follows:

| **Raspberry Pi 1** | **Raspberry Pi 2** |
|------------------|------------------|
| **Pin 8 (TX)** | **Pin 10 (RX)** |
| **Pin 10 (RX)** | **Pin 8 (TX)** |
| **Pin 6 (GND)** | **Pin 6 (GND)** |

---

## **3️⃣ Enable Serial Port on Raspberry Pi**
By default, the Raspberry Pi’s UART is disabled. You need to enable it.

1️⃣ **Run the following command on Raspberry Pi**:
```bash
sudo raspi-config
```
2️⃣ **Navigate to**:  
   ```
   Interface Options → Serial Port
   ```
3️⃣ **Choose:**
   - **"Would you like a login shell to be accessible over serial?"** → **NO**  
   - **"Would you like the serial port hardware enabled?"** → **YES**  

4️⃣ **Reboot the Raspberry Pi**:
```bash
sudo reboot
```

---

## **4️⃣ Setting Up Serial Communication on PC or Second Raspberry Pi**
Once the physical connection is complete, you need to **open a serial terminal** on the PC or second Raspberry Pi.

### **A) If Using a PC (With USB-TTL)**
1. **Check which port is assigned to the USB-TTL Adapter**  
   Run:
   ```bash
   ls /dev/ttyUSB*
   ```
   It should output something like:
   ```
   /dev/ttyUSB0
   ```
2. **Open Serial Communication on PC**  
   ```bash
   screen /dev/ttyUSB0 115200
   ```
   - Now you can send commands to the Raspberry Pi via serial.

---

### **B) If Using Another Raspberry Pi**
1. **Check Serial Port**
   ```bash
   ls /dev/serial*
   ```
   Expected output:
   ```
   /dev/serial0
   ```
2. **Open a Serial Terminal on Raspberry Pi 2**  
   ```bash
   sudo apt install minicom
   minicom -b 115200 -o -D /dev/serial0
   ```
   - Now you can send and receive serial messages.

---

## **5️⃣ Sending Commands to Control LED**
Once the connection is established, you can **run the LED control script on the first Raspberry Pi**:

```bash
python3 serial_led.py
```
Then, on the **PC or second Raspberry Pi**, type:
```
turn led on
turn led off
```
The LED should turn **ON/OFF** based on your command. 🚀

---

### **🎯 Summary**
✔ **Connected Raspberry Pi UART (TX, RX, GND) to PC (USB-TTL) or another Raspberry Pi**  
✔ **Enabled UART on Raspberry Pi**  
✔ **Opened Serial Terminal on PC or Second Raspberry Pi**  
✔ **Controlled LED via Serial Commands**  
