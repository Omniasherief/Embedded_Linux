import socket
import threading #will be used to handle multiple client connections concurrently.

def handle_client(client_socket, client_adress):
    print(f"Accepted connection from {client_adress}")

    while True:
        #recieve data and send it back
        data=client_socket.recv(1024)
        if not data:  
            # If no data is received (i.e., data is empty), it means the connection has been closed by the client,
            break
        client_socket.send(data)#sends the received data back to the client, essentially creating an echo effect.

def main():
    '''
    socket.AF_INET: 
        
    This specifies the address family, which is IPv4 in this case.
    socket.SOCK_STREAM: 
    This specifies the socket type, which is SOCK_STREAM for TCP (Transmission Control Protocol) connections. TCP provides a reliable, stream-oriented connection.
    '''
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_address = ('',8999)  # IP->('') is an empty string, which indicates that the server will listen on all available network interfaces (usually the default network adapter)
    server_socket.bind(server_address)
    # Listen for incoming connections (up to 5 clients)
    server_socket.listen(5)
    print("Server is listening for incoming connections...")
    while True:
        client_socket,client_address=server_socket.accept()
        #new thread
        client_thread=threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()


if __name__ == "__main__":

  main()