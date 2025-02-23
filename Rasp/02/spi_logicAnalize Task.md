### **📌 Testing SPI with a Logic Analyzer on Raspberry Pi**
Using a **logic analyzer** is one of the best ways to debug and analyze SPI communication on Raspberry Pi. It allows you to visualize clock signals, MOSI/MISO data, and chip select activity.

---

## **🛠 Steps to Test SPI with a Logic Analyzer**
### **1️⃣ Connect the Logic Analyzer to Raspberry Pi**
You'll need to connect the **SPI pins** of Raspberry Pi to the **logic analyzer**.  

| SPI Signal | Raspberry Pi Pin | Logic Analyzer Channel |
|------------|-----------------|------------------------|
| **MOSI** (Master Out, Slave In) | GPIO 10 (Pin 19) | Any channel (e.g., CH0) |
| **MISO** (Master In, Slave Out) | GPIO 9 (Pin 21) | Any channel (e.g., CH1) |
| **SCLK** (Clock) | GPIO 11 (Pin 23) | Any channel (e.g., CH2) |
| **CE0 (Chip Select 0)** | GPIO 8 (Pin 24) | Any channel (e.g., CH3) |
| **CE1 (Chip Select 1)** | GPIO 7 (Pin 26) | Any channel (e.g., CH4) |
| **GND** | Any GND pin | GND of Logic Analyzer |

---

### **2️⃣ Enable SPI on Raspberry Pi**
By default, SPI is disabled. Enable it using:
```bash
sudo raspi-config
```
- Navigate to **Interfacing Options → SPI → Enable**  
- Reboot Raspberry Pi:
  ```bash
  sudo reboot
  ```

---

### **3️⃣ Install SPI Tools for Testing**
```bash
sudo apt update
sudo apt install -y python3-spidev spidev
```

---

### **4️⃣ Generate SPI Test Signals**
Create a simple Python script to send data via SPI:
```python
import spidev
import time

spi = spidev.SpiDev()
spi.open(0, 0)  # Use CE0 (Chip Select 0)
spi.max_speed_hz = 500000  # 500 kHz clock speed

while True:
    spi.xfer2([0xAA])  # Send test byte 0xAA (10101010)
    time.sleep(0.5)
```
This will repeatedly send `0xAA` via SPI.

---

### **5️⃣ Capture Signals with the Logic Analyzer**
#### **Using PulseView (Sigrok)**
1. Install **PulseView (Sigrok)**:
   ```bash
   sudo apt install -y pulseview sigrok-cli
   ```
2. Connect the **Logic Analyzer** to your PC and launch PulseView:
   ```bash
   pulseview
   ```
3. Set up channels:
   - **MOSI → CH0**
   - **MISO → CH1**
   - **SCLK → CH2**
   - **CE0 → CH3**
   - **GND → GND**
4. Click **Run** to start capturing SPI signals.
5. Analyze waveforms:
   - **MOSI** should show `0xAA` (10101010 in binary).
   - **SCLK** should toggle at 500 kHz.
   - **CE0** should go LOW before transmission and HIGH after.

---

### **6️⃣ Debugging SPI Issues**
- **No Clock Signal (SCLK)?** → Check if SPI is enabled in `raspi-config`.
- **CE0 Always HIGH?** → Ensure correct wiring.
- **MISO is Always Low?** → Check if the slave device is responding.

---

## **🎯 Conclusion**
- **A logic analyzer is a powerful tool** for debugging SPI.
- Use **PulseView** to visualize SPI communication.
- Test with a **simple Python script** to generate signals.

