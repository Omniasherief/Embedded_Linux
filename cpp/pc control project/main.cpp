#include <iostream>
#include "server.hpp"  // Server header
#include "commands.hpp" // Command handling header


int main()
{
    server_class server; //server object
    command cmd;          // Create a command handler object

     // Initialize the server
    if (!server.server_init()) {
        std::cerr << "Server initialization failed" << std::endl;
        return -1;
    }

    // Listen for incoming connections
    if (!server.server_listen()) {
        std::cerr << "Server failed to listen" << std::endl;
        return -1;
    }

    std::cout << "Server is listening for connections..." << std::endl;
    // Accept client connections
    while (server.server_acceptClient()) {
        std::cout << "Client connected!" << std::endl;

        // Process commands from the client
        std::string client_msg;
        while (!(client_msg = server.server_read()).empty()) {
            std::cout << "Received command: " << client_msg << std::endl;

            std::string response;
            
            // Command handling based on client input
            if (client_msg == "open_terminal") {
                response = cmd.open_terminal();
            }
            else if(client_msg == "exit")
            {
                server.server_sendMsg("Exiting the server...\n");
                    server.server_close();

            } else if (client_msg == "open_calculator") {
                response = cmd.open_calculator();
            } else if (client_msg == "open_firefox") {
                response = cmd.open_firefox();
            } else if (client_msg == "open_text_editor") {
                response = cmd.open_text_editor();
            } else if (client_msg == "open_file_manager") {
                response = cmd.open_file_manager();
            } else if (client_msg == "open_music_player") {
                response = cmd.open_music_player();
            } else if (client_msg == "open_vscode") {
                response = cmd.open_vscode();
            } else if (client_msg == "open_document_viewer") {
                response = cmd.open_document_viewer();
            }
            else if (client_msg.rfind("open_custom_app", 0) == 0) 
            {
            std::string app_name = client_msg.substr(15);  // Extract app name from command
            response = cmd.open_custom_app(app_name);      // Open the custom app
            } else {
                response = "Unknown command: " + client_msg;
            }

            // Send the response back to the client
            server.server_sendMsg(response);
        }
         // Close client connection after handling all commands
        server.close_listening_client();
        std::cout << "Client disconnected." << std::endl;
    }

    // Close the server
    server.close_listening_server();
    std::cout << "Server shutdown." << std::endl;

}
