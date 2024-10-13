## **networking commands** 

---

## **1. Ping & ifconfig**

### **`ping`**  
The `ping` command checks if a remote host is reachable by sending ICMP packets.

#### Example:
```bash
ping google.com
```
**Options:**  
- `-c <count>`: Stop after sending `<count>` packets.
```bash
ping -c 4 8.8.8.8
```

---

### **`ifconfig`**  
Displays or configures network interfaces. It is replaced by `ip` in newer Linux versions but still useful.

#### Example:
```bash
ifconfig
```
- Bring up an interface:
  ```bash
  sudo ifconfig eth0 up
  ```
- Assign IP address to an interface:
  ```bash
  sudo ifconfig eth0 192.168.1.100 netmask 255.255.255.0
  ```

---

## **2. Netstat**

`netstat` shows network statistics, open ports, and active connections.

#### Example:
```bash
netstat -tuln
```
- **`-t`**: Show TCP connections  
- **`-u`**: Show UDP connections  
- **`-l`**: Show listening ports  
- **`-n`**: Show numeric addresses  

To monitor network connections in real-time:
```bash
netstat -c
```

---

## **3. SSH**

SSH (Secure Shell) allows you to access remote systems securely.

#### Example:
```bash
ssh user@192.168.1.10
```
- Connect using a specific port:
  ```bash
  ssh -p 2222 user@192.168.1.10
  ```
- Use **key-based authentication**:
  ```bash
  ssh -i /path/to/private_key user@192.168.1.10
  ```

---

## **4. SCP**

`scp` (Secure Copy Protocol) copies files between local and remote systems over SSH.

#### Example:
```bash
scp file.txt user@192.168.1.10:/home/user/
```
- Copy a file **from remote to local**:
  ```bash
  scp user@192.168.1.10:/home/user/file.txt /local/path/
  ```
- Copy an entire directory:
  ```bash
  scp -r /local/dir/ user@192.168.1.10:/remote/dir/
  ```

---

## **5. Route, ARP, and Tracepath**

### **`route`**  
Displays or manipulates the IP routing table.

#### Example:
```bash
route -n
```
- Add a default gateway:
  ```bash
  sudo route add default gw 192.168.1.1 eth0
  ```

---

### **`arp`**  
Displays and manipulates the ARP table (used to map IP addresses to MAC addresses).

#### Example:
```bash
arp -a
```
- Add an entry:
  ```bash
  sudo arp -s 192.168.1.10 00:0a:95:9d:68:16
  ```
- Delete an entry:
  ```bash
  sudo arp -d 192.168.1.10
  ```

---

### **`tracepath`**  
Similar to `traceroute`, but does not require root privileges. It traces the path to a destination host.

#### Example:
```bash
tracepath google.com
```

---
