#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <cstdlib>
#include <string>

class command 
{
    public:
    command(){};
    std::string open_terminal();        ///< Opens the terminal application.
    std::string open_calculator();      ///< Opens the calculator application.
    std::string open_firefox();         ///< Opens the Firefox browser.
    std::string open_text_editor();     ///< Opens a text editor (gedit).
    std::string open_file_manager();    ///< Opens the file manager (Nautilus).
    std::string open_music_player();    ///< Opens the music player (Rhythmbox).
    std::string open_vscode();          ///< Opens Visual Studio Code.
    std::string open_document_viewer(); ///< Opens the document viewer (Evince).
    std::string open_custom_app(const std::string& app_name); ///< Opens a custom application.
};

inline std::string command::open_terminal()
{
    int result =system("gnome-terminal &");
    return (result==0)? "Terminal opened successfully":"failed to open terminal";

}

inline std::string command::open_calculator() {
    int result = system("gnome-calculator &");
    return (result == 0) ? "Calculator opened successfully" : "Failed to open calculator";
}

inline std::string command::open_firefox() {
    int result = system("firefox &");
    return (result == 0) ? "Firefox opened successfully" : "Failed to open Firefox";
}

inline std::string command::open_text_editor() {
    int result = system("gedit &");
    return (result == 0) ? "Text editor opened successfully" : "Failed to open text editor";
}

inline std::string command::open_file_manager() {
    int result = system("nautilus &");
    return (result == 0) ? "File manager opened successfully" : "Failed to open file manager";
}

inline std::string command::open_music_player() {
    int result = system("rhythmbox &");
    return (result == 0) ? "Music player opened successfully" : "Failed to open music player";
}


inline std::string command::open_custom_app(const std::string& app_name) {
    std::string command_str = app_name + " &";  // Construct the command string
    //cmd.open_custom_app("libreoffice");
    int result = system(command_str.c_str());   // Execute the system command
    return (result == 0) ? (app_name + " opened successfully") : ("Failed to open " + app_name);
}


inline std::string command::open_vscode() {
    int result = system("code &");
    return (result == 0) ? "VSCode opened successfully" : "Failed to open VSCode";
}

inline std::string command::open_document_viewer() {
    int result = system("evince &");
    return (result == 0) ? "Document viewer opened successfully" : "Failed to open document viewer";
}




#endif // COMMAND_HPP