

### FIFO System Call Explained

**FIFO (First In, First Out)** is a type of named pipe that allows processes to communicate with each other by reading and writing data in a sequential manner (first data written will be the first read). Named pipes, unlike anonymous pipes, are persistent and exist as special files in the filesystem.

The command to create a named pipe:
```bash
mkfifo /tmp/myfifo
```

This creates a special file (`/tmp/myfifo`) that acts as a communication channel between two processes.

### Code Breakdown

Here are two C programs from the image that work with FIFO:

#### 1. FIFO Reader Program
This program opens a FIFO for reading and prints data from the FIFO.
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Open the named pipe (FIFO) for reading
    const char *fifo_path = "/tmp/myfifo"; // Path to the FIFO
    int fifo_fd = open(fifo_path, O_RDONLY); // Open FIFO in read-only mode
    if (fifo_fd == -1) { 
        perror("open"); // Error handling if open fails
        exit(EXIT_FAILURE); // Exit with failure code
    }

    // Read data from the FIFO
    char buffer[1024]; // Buffer to store the read data
    ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer)); // Read data into buffer
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Reader received: %s\n", buffer); // Print the received data
    }

    close(fifo_fd); // Close the FIFO file descriptor
    return 0;
}
```
- **open()**: Opens the FIFO (`/tmp/myfifo`) for reading using `O_RDONLY`. If it fails, the program prints an error and exits.
- **read()**: Reads data from the FIFO into a buffer. It checks if data has been read and then prints it out.
- **close()**: Closes the FIFO file descriptor.

#### 2. FIFO Writer Program
This program opens a FIFO for writing and sends a message through it.
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Create or open the named pipe (FIFO) for writing
    const char *fifo_path = "/tmp/myfifo";
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo"); // Error handling for mkfifo
        exit(EXIT_FAILURE);
    }

    int fifo_fd = open(fifo_path, O_WRONLY); // Open FIFO in write-only mode
    if (fifo_fd == -1) {
        perror("open"); // Error handling if open fails
        exit(EXIT_FAILURE);
    }

    // Write data to the FIFO
    char message[] = "Hello, reader!\n"; // Message to send
    write(fifo_fd, message, strlen(message)); // Write the message to the FIFO

    close(fifo_fd); // Close the FIFO file descriptor
    return 0;
}
```
- **mkfifo()**: Creates the FIFO at the given path (`/tmp/myfifo`) with read/write permissions (`0666`).
- **open()**: Opens the FIFO in write-only mode (`O_WRONLY`).
- **write()**: Sends a message ("Hello, reader!") through the FIFO.
- **close()**: Closes the FIFO after writing.

### Third Code Block (Pipe Example)
The third block of code shows how to create a pipe between a parent and child process using `pipe()` and `fork()`.

#### Code Breakdown (Pipe Example):
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pipefd[2]; // File descriptors for the pipe
    pid_t cpid;
    char buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) { // Create a pipe
        perror("pipe"); // Error handling if pipe creation fails
        exit(EXIT_FAILURE);
    }

    cpid = fork(); // Fork a child process
    if (cpid == -1) {
        perror("fork"); // Error handling for fork failure
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) { // Child process
        close(pipefd[1]); // Close unused write end
        while (read(pipefd[0], &buf, 1) > 0) { // Read from pipe
            write(STDOUT_FILENO, &buf, 1); // Write to stdout (console)
        }
        close(pipefd[0]); // Close read end after done
        _exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[0]); // Close unused read end
        write(pipefd[1], argv[1], strlen(argv[1])); // Write argument to pipe
        close(pipefd[1]); // Close write end
        wait(NULL); // Wait for child process to finish
        exit(EXIT_SUCCESS);
    }
}
```
- **pipe()**: Creates a unidirectional communication channel between the parent and child process.
- **fork()**: Forks a child process.
- **close()**: Closes unused ends of the pipe in both parent and child processes.
- **read()/write()**: The child reads from the pipe, and the parent writes to it.
- **`pipefd[0]` and `pipefd[1]`**: One for **reading** and one for **writing** in a pipe.


### System Calls: `poll()`, `pipe()`, `FIFO`
- **`poll()`**: Monitors multiple file descriptors to see if they are ready for I/O operations (e.g., reading or writing). It’s useful in network programming where a process may need to handle multiple connections simultaneously.
  
  **Usage Example (with sockets):**
  ```c
  struct pollfd fds[2];
  fds[0].fd = sock_fd;  // File descriptor for a socket
  fds[0].events = POLLIN; // Monitor for input data
  poll(fds, 2, -1);  // Wait indefinitely for events on sockets
  ```
  
  This waits for input on two sockets.

- **`pipe()`**: A system call that creates an anonymous pipe for communication between a parent and child process.

  **Example:**
  ```c
  int pipefd[2];
  pipe(pipefd); // Create pipe
  ```

### Summary of Concepts
- **FIFO**: Named pipes used for communication between unrelated processes.
- **pipe()**: Used for communication between related processes, usually parent-child.
- **poll()**: Monitors file descriptors for readiness to perform I/O operations, commonly used in network programming.

