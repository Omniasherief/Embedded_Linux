#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <array>

#define PORT_NUM  8090
/**
 * @class server_class
 * @brief A simple TCP server class to handle basic server operations.
 */

class server_class{
    private:
       int socket_info;              // Socket file descriptor for the server.
       int client_info;              // socket file descriptor for client connection
       std::array<char,1000> buffer; // Buffer to store data received from the client.
    

    public:


    //< Constructor to initialize the server class.
    server_class(): socket_info(-1),client_info(-1){
        // init file descriptors to -1 mrans they are not valid 
    }


    //< Destructor to close the server and client sockets.
    ~server_class() {
    // Clean up and close sockets if they are still open.
    if (socket_info != -1) {
        close(socket_info);
    }
    if (client_info != -1) {
        close(client_info);
    }
    }

    bool server_init(); //init the server socket and and binds it to a port
    bool server_listen(); //listens for incoming client connection
    bool server_acceptClient(); //Accepts an incoming client connection
    bool server_sendMsg(const std::string& message); //sends message to the connection client
    std::string server_read(); //reads a message from the connected client
    void close_listening_server(); //closes the server sockets
    void close_listening_client(); //closes the client sockets
    void server_close();           //closes the client connection socket and resets the client info 

    };


  inline bool server_class::server_init()
  {
    /*sockaddr_in is used to store the IP address and port information for the socket.
      socket() creates a TCP socket for communication.
      htons() ensures the port number is in network byte order.
      INADDR_ANY allows the server to bind to any available IP address on the machine.
      bind() associates the socket with the specified IP address and port so the server can listen for incoming connections.
    */
    sockaddr_in  socket_address;
    //create socket for TPv4 and TCP
    socket_info=socket(AF_INET,SOCK_STREAM,0);
    if(socket_info<0)
    {
        std::cerr <<"Cannot create a socket" <<std::endl;
        return false;

    }
    // set up the socket address structure
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT_NUM); // Port number to listen on.
    socket_address.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces.
    // bind the socket to the specified port and address
    if (bind(socket_info, (sockaddr*)&socket_address, sizeof(socket_address)) < 0) {
        std::cerr << "Cannot bind" << std::endl;
        return false;
    }

    return true;


  }
inline bool server_class::server_listen()
    {
      //set socket to listen for incoming connections
      if(listen(socket_info,3)<0)
      {
        std::cerr << "Cannot listen" << std::endl;
        return false;
      }

       return true;
    }
inline bool server_class::server_acceptClient()
    {
      sockaddr_in client;
      socklen_t client_size = sizeof(client);
      /*retrieves the client's address information*/
      client_info = accept(socket_info, (sockaddr*)&client, &client_size);

       if (client_info < 0) {
          std::cerr << "Problem with client connection" << std::endl;
          return false;
        }
       return true;


    }
inline   bool server_class:: server_sendMsg(const std::string& message)
    {
         // Send a message to the connected client.
         if (send(client_info, message.c_str(), message.size(), 0) < 0) {
          std::cerr << "Error sending message" << std::endl;
          return false;
          }
        return true;
    }
 inline   std::string server_class:: server_read(){

 ssize_t bytes_read = recv(client_info, buffer.data(), buffer.size() - 1, 0);

    // Handle different cases of data reception.
    if (bytes_read < 0) {
        std::cerr << "Error receiving data" << std::endl;
        return "Error receiving data";
    } else if (bytes_read == 0) {
        // Client closed the connection.
        return "Client closed connection";
    } else {
        // Null-terminate the buffer and return the received data.
        buffer[bytes_read] = '\0';
        std::string buffer_str(buffer.data(), bytes_read);
        std::cout << "Received message: " << buffer_str << std::endl;
        return buffer_str;
    }

    }
 inline void  server_class:: close_listening_server(){
       // Close the server socket. This should be called when the server is done listening.
       close(socket_info);
    }
 inline void  server_class::  close_listening_client(){

       // Close the client socket. This should be called when the server is done with the client.
         close(client_info);
    }
 inline  void  server_class:: server_close()
    {

    // Close the client socket and reset the client info.
    if (client_info != -1) {
        close(client_info);
        client_info = -1;
    }

    }


 #endif