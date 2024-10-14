
---

# 🚀 **Bash Scripts Collection**  
A set of powerful bash scripts to automate everyday tasks—from project creation to video downloading and system service setup. Everything you need to make your life easier. 🎯

---

## 📁 **1. Create Project Based on Makefile** (`script.sh`)  
This script helps you bootstrap a C++ project with a pre-configured `Makefile` for quick builds.

### Usage:
1. **Run the script**:
   ```bash
   bash script.sh
   ```
2. **Enter your project name** when prompted.
3. A folder structure like this will be created:
   ```
   project_name/
   ├── src/
   │   └── main.cpp
   ├── include/
   ├── build/
   └── Makefile
   ```
4. **Build your project** with:
   ```bash
   make -C project_name
   ```

---

## 🛠️ **2. Create Systemd Service** (`create_service.sh`)  
Automate your tasks by creating a custom **systemd service** that starts on boot! 

### Usage:
1. **Run the script with `sudo`**:
   ```bash
   sudo bash create_service.sh
   ```
2. **Provide a service name**.
3. Enable and start the service with:
   ```bash
   sudo systemctl enable <service_name>
   sudo systemctl start <service_name>
   ```
4. This service will execute a bash script located in `/home/$USER`.

---

## 🎥 **3. YouTube Video Downloader** (`download_youtube.sh`)  
Download your favorite YouTube videos with **`yt-dlp`** in one go!

### Usage:
1. **Ensure `yt-dlp` is installed** (the script will install it if missing).
2. Run the script:
   ```bash
   bash Download_Videos.sh
   ```
3. **Paste the video URL** when prompted.
4. The video will be saved with the original title and file extension. 📥

---

## 📖 **4. Wiki Helper Script** (`wiki_helper.sh`)  
Get quick access to useful code snippets and Linux commands with this script. 🧠

### Usage:
1. **Run the script**:
   ```bash
   bash wiki_helper.sh
   ```
2. **Choose an option**:
   - 📝 **C++ Hello World**
   - 🐍 **Python Hello World**
   - 🖥️ **Useful Linux Commands**
   - 🛡️ **Bash Hello World**

---

## ➗ **5. Advanced Calculator** (`calculator.sh`)  
Perform basic and advanced calculations with this script using **`bc`**. 🧮

### Usage:
1. **Run the script**:
   ```bash
   bash calculator.sh
   ```
2. **Enter two numbers** and **choose an operation**:
   - ➕ **Addition**
   - ➖ **Subtraction**
   - ✖️ **Multiplication**
   - ➗ **Division**  
   _(Division by zero is handled gracefully!)_  
   - 🔢 **Power**

---

## 💼 **Prerequisites**  
Ensure you have the following installed:  
- **Bash**: Pre-installed on most Unix-based systems.  
- **bc**: For the calculator script:
  ```bash
  sudo apt install bc
  ```
- **yt-dlp**: For downloading YouTube videos:
  ```bash
  sudo apt install yt-dlp
  ```
- **Permission**: Before running script 
  ```bash
  chmod +x scriptname
  ```
---

## 🛠️ **Contributing**  
We welcome contributions! If you have ideas for improvements or new scripts. 💡

---

## 📝 **License**  
This project is released under the **MIT License**. Feel free to use, modify, and share it!

---

## 🏁 **Get Started Today!**  
Clone the repository, try out the scripts, and see how much easier life can get with automation! ✨

---

