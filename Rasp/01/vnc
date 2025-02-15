To access a VNC server from both your Raspberry Pi and pc, follow these steps:

---

### **1. Set Up the VNC Server**
You'll need to install and start a VNC server on the system you want to control.

#### **For Raspberry Pi (If it's the server)**
1. **Enable VNC on Raspberry Pi**  
   Run the following command:
   ```bash
   sudo raspi-config
   ```
   - Go to **Interface Options > VNC** and enable it.
   - Install the VNC server if not installed:
     ```bash
     sudo apt update && sudo apt install realvnc-vnc-server realvnc-vnc-viewer
     ```
   - Start the server:
     ```bash
     sudo systemctl enable vncserver-x11-serviced
     sudo systemctl start vncserver-x11-serviced
     ```
   - Check the IP address of your Raspberry Pi:
     ```bash
     hostname -I
     ```

#### **For a Linux/Windows Server**
If you're running the VNC server on a different system:
- Install **TigerVNC**, **x11vnc**, or **RealVNC Server**:
  ```bash
  sudo apt install tigervnc-standalone-server
  ```
  - Start the server:
    ```bash
    vncserver
    ```
  - Set a password when prompted.
  - Find the server’s IP using `ip a` (Linux) or `ipconfig` (Windows).

---

### **2. Connect to the VNC Server**
Now, from both your Raspberry Pi and laptop, install a **VNC viewer**.

#### **On Raspberry Pi (Client Mode)**
1. Install the RealVNC Viewer:
   ```bash
   sudo apt install realvnc-vnc-viewer
   ```
2. Open the VNC Viewer GUI and enter the server's IP (e.g., `192.168.1.100:1`).

#### **On Laptop**
- **For Linux**:
  ```bash
  sudo apt install tigervnc-viewer
  vncviewer <server-ip>:1
  ```
- **For Windows**:
  - Download **VNC Viewer** from [RealVNC](https://www.realvnc.com/en/connect/download/viewer/).
  - Enter the **server IP** and port (e.g., `192.168.1.100:1`).

---

### **3. Forwarding (Optional - For Remote Access)**
If you need to access your VNC server **outside your local network**:
- Configure **port forwarding** on your router.
- Open port **5900** (or the one set in the VNC server).
- Use a dynamic DNS service like **No-IP** if your IP changes.

---
