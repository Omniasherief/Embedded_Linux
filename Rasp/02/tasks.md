
---

### 1. **Servo Motor with Raspberry Pi**
To control a servo motor using Raspberry Pi, you’ll need the following:
- Servo Motor (typically powered by 5V)
- Raspberry Pi GPIO pins

#### Steps:
1. **Hardware Connection:**
   - Connect the **servo motor's power (VCC)** pin to the **5V** pin on the Raspberry Pi.
   - Connect the **servo motor's ground (GND)** pin to the **GND** pin on the Raspberry Pi.
   - Connect the **control (signal)** pin of the servo to a **GPIO pin** (e.g., GPIO17).

2. **Software Setup:**
   - Install `RPi.GPIO`:
     ```bash
     sudo apt-get install python3-rpi.gpio
     ```
   - Example Python code to control the servo:
     ```python
     import RPi.GPIO as GPIO
     import time

     GPIO.setmode(GPIO.BCM)
     GPIO.setup(17, GPIO.OUT)  # GPIO17 for controlling the servo

     pwm = GPIO.PWM(17, 50)  # 50Hz frequency (servo motors are usually controlled at 50Hz)
     pwm.start(0)

     def set_angle(angle):
         duty_cycle = angle / 18 + 2
         GPIO.output(17, True)
         pwm.ChangeDutyCycle(duty_cycle)
         time.sleep(1)
         GPIO.output(17, False)
         pwm.ChangeDutyCycle(0)

     try:
         while True:
             for angle in range(0, 180, 5):
                 set_angle(angle)
             for angle in range(180, 0, -5):
                 set_angle(angle)
     except KeyboardInterrupt:
         pwm.stop()
         GPIO.cleanup()
     ```

3. **Video Tutorial:**  
   ▶ [Raspberry Pi Servo Motor Control - YouTube](https://www.youtube.com/watch?v=xHDT4CwjUQE&utm_source=chatgpt.com)

---

### 2. **USB TTL and Connect Raspberry Pi with PC**
To establish a connection between the Raspberry Pi and your PC via USB TTL:
- **USB to TTL Adapter**
- Raspberry Pi GPIO or Serial Pins

#### Steps:
1. **Hardware Connection:**
   - Connect the **TX** pin of the USB TTL adapter to the **RX** pin of the Raspberry Pi (GPIO15).
   - Connect the **RX** pin of the USB TTL adapter to the **TX** pin of the Raspberry Pi (GPIO14).
   - Connect the **GND** pin of the USB TTL adapter to the **GND** pin of the Raspberry Pi.

2. **Communication on PC (Linux):**
   - Use `minicom` or `screen` to communicate over the serial port.
     ```bash
     screen /dev/ttyUSB0 115200
     ```
   - Replace `/dev/ttyUSB0` with the correct serial device on your PC.

3. **On Raspberry Pi:**
   - Install `pySerial` and run:
     ```bash
     sudo apt-get install python3-serial
     ```
   - Example Python code:
     ```python
     import serial
     ser = serial.Serial('/dev/ttyAMA0', 115200)
     ser.write(b'Hello from Pi\n')
     ```

4. **Video Tutorial:**  
   ▶ [Connecting Raspberry Pi to PC via TTL - YouTube](https://m.youtube.com/watch?t=94s&v=AeaBQBoi3MQ&utm_source=chatgpt.com)

---

### 3. **Connect MCU with Raspberry Pi using UART (System Call Poll)**
For connecting an MCU (e.g., Arduino) to Raspberry Pi over UART:
- **UART Communication Pins**: RX, TX, GND

#### Steps:
1. **Hardware Connection:**
   - Connect the **TX** pin of the MCU to the **RX** pin of the Raspberry Pi (GPIO15).
   - Connect the **RX** pin of the MCU to the **TX** pin of the Raspberry Pi (GPIO14).
   - Connect the **GND** pins of both devices.

2. **Software Setup:**
   - Install `pySerial`:
     ```bash
     sudo apt-get install python3-serial
     ```
   - Example code using `poll()`:
     ```python
     import serial
     import select

     ser = serial.Serial('/dev/ttyAMA0', 9600)

     while True:
         rlist, _, _ = select.select([ser], [], [], 1)
         if rlist:
             data = ser.readline()
             print(data.decode().strip())
     ```

3. **Video Tutorial:**  
   ▶ [UART Communication with Polling & Interrupt - YouTube](https://www.youtube.com/watch?v=wC9a0IkPA1A&utm_source=chatgpt.com)

---

