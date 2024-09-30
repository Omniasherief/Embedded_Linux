IPC in Linux allows processes not only to communicate with each other but also to synchronize their actions. In Linux, there are several mechanisms for IPC, each suited for different use cases, offering various levels of complexity and speed. Below is an overview of some common methods of IPC in Linux.

## stop ✋🏻🛑 

**Check out this video, it could be useful**

-[click](https://www.youtube.com/watch?v=BU9m45WWqjM)


### 1. **Pipes - Anonymous and Named**
- **Anonymous Pipes**: These are used for communication between the parent and child process. A pipe allows flow of data in one direction, often from one process to another.
     - Example: `pipe()`, is generally used together with `fork()`.
   - **Named Pipes (FIFOs)**: Unlike anonymous pipes, the named ones can be accessed by unrelated processes and can be identified by a file path.
- **Command**: `mkfifo`
     - **Use Case**: IPC among unrelated processes running within the same or different sessions.
   
   ```c
   // Example of creating a named pipe
   mkfifo("/tmp/myfifo", 0666);
   ```

### 2. **Message Queues**
- The message queues allow the process to pass message or data in a well-structured format. Messages are placed in queues, thus enabling the receiving and sending processes to operate asynchronously.
     - **System Calls**: `msgget()`, `msgsnd()`, `msgrcv()`, `msgctl()`
     - **Use Case**: Messaging between processes in large number, and it is useful when you want more control over the order of the communication and priority.
   
```c
int msqid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
   msgsnd(msqid, &message, sizeof(message), 0);
   ```
### 3. **Shared Memory**
   - Shared memory is the fastest form of IPC. It allows multiple processes to access a common memory space. Synchronisation mechanisms like semaphores are usually required to avoid race conditions.
     - **System Calls**: `shmget()`, `shmat()`, `shmdt()`, `shmctl()`
- **Use Case**: When speed is of essence, and huge data must be shared among processes.
  
```c
   int shmid = shmget(IPC_PRIVATE, 1024, 0666|IPC_CREAT);
   char *str = (char*) shmat(shmid, NULL, 0);
  
  
  
### 4. **Semaphores**
- Semaphores are used so that multiple processes can share the same resources. They work somewhat like flags, and are part of a signaling mechanism that controls process synchronization.
     - **System Calls**: `semget()`, `semop()`, `semctl()`
     - **Use Case**: To synchronize processes and control access to shared resources like files or memory.
   
```c
int semid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
   struct sembuf sb = {0, -1, 0}; // P operation
   semop(semid, &sb, 1);
   ```
   
### 5. **Sockets**
   - Sockets provide a more general form of IPC that can be used for communication between processes on the same machine or different machines over a network.
- **Types**: Unix domain sockets - for local communications and TCP/UDP sockets for network communications.
     - **System Calls**: `socket()`, `bind()`, `connect()`, `send()`, `recv()`
     - **Usage:** Network-based communication or local using Unix domain sockets.
   
   ```c
   int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
   connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
   ```

### 6. **Signals**
   - Signals are a basic form of IPC. This is how one process can send asynchronous notifications to another.
     - **Common Signals**: `SIGINT`, `SIGTERM`, `SIGKILL`
     - **System Calls**: `kill()`, `signal()`, `sigaction()`
     - **Use Case**: Simple notifications between processes. Usually used for killing or restarting processes.
   
```c
kill(pid, SIGKILL);
   ```
/// 7. **Memory-Mapped Files (mmap)**
   - `mmap` enables processes to share memory by mapping files or devices into memory. This can be used for fast file access but also as one method of implementing IPC.
     - **System Calls**: `mmap()`, `munmap()`
     - **Use Case**: Fast data exchange between processes using shared memory or via file exchanges.
```c
   void *addr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
   ```

### Choice of IPC
- **Pipes and FIFOs**: Suitable for simple, unidirectional flow.
- **Message Queues**: Good when exchanging data between running processes as structured messages.
- **Shared Memory**: Good when large data has to be exchanged among processes with a high speed.
- **Semaphores:** To synchronize access to shared resources.
- **Sockets**: applied either in network or local communication, especially when flexibility and scalability become necessary.
- **Signals**: useful for event-driven notifications.
- **Memory-Mapped Files**: ideal if an application requires high-speed access to file data or shared memory.
