import socket

# Server's IP address and port
server_address = ('localhost',8999)

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect(server_address)
print(f"Connected to {server_address}")

try:
    # Send data to the server
    message = "Hello, server!"
    '''encode(). It transforms the string into a sequence of bytes, which are essentially numerical values 
    representing the characters.
      Different encoding schemes exist (like UTF-8, ASCII),
        each with rules for mapping characters to bytes.'''
    client_socket.sendall(message.encode())

    # Receive data from the server
    data = client_socket.recv(1024)
    print(f"Received from server: {data.decode()}")

finally:
    # Close the socket connection
    print("Closing connection to the server.")
    client_socket.close()

'''
Port number
9999 is often not assigned any particular meaning or protocol.
It's generally used as a custom port number for user-defined applications or services. In your code, it's likely chosen arbitrarily for the server to listen on.
You can choose any port number within a valid range (typically between 1024 and 49151) as long as it's not already in use by another program on the same machine
'''