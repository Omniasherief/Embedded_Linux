#include <iostream>
#include<vector>
#include<string>
#include <sstream>

class LOG{
    
  public:
    enum class LogLevel
    {
      WARN,ERROR,INFO
    };


  private:
    struct LogMessage{
        LogLevel level;
        std::string message;
    };
   static std::vector<LogMessage> BUFFER ;
 

     static std::string Prefix(LogLevel level) {
        switch (level) {
            case LogLevel::INFO: return "[INFO] ";
            case LogLevel::WARN: return "[WARN] ";
            case LogLevel::ERROR: return "[ERROR] ";
            default: return "[UNKNOWN] ";
    }
    } 
  public:
   
    class Logger
    {
      LogLevel logLevel;
      std::ostringstream stream;
      public: 
        Logger(LogLevel level) : logLevel(level) {}

        Logger& operator <<(const std::string& msg)
        {
            stream << msg;
            return *this;
        }
        ~Logger()
        {
            BUFFER.push_back({logLevel,stream.str()});
        }

      
        
    };


     LOG()=delete;

    static Logger Log(LogLevel level) {
        return Logger(level);
    }
     static void Dump() {
        for (const auto& logMsg : BUFFER) {
            std::cout << Prefix(logMsg.level) << logMsg.message << std::endl;
        }
    }

    static void Clear() {
        BUFFER.clear();
    }
    
  
};


// Initialize static member
std::vector<LOG::LogMessage> LOG::BUFFER;



int main() {
    // Log messages with different levels
    LOG::Log(LOG::LogLevel::INFO) << "This is an info message.";
    LOG::Log(LOG::LogLevel::WARN) << "This is a warning message.";
    LOG::Log(LOG::LogLevel::ERROR) << "This is an error message.";

    // Dump the log messages
    LOG::Dump(); 
    // Clear the log buffer
    LOG::Clear();

/*
   LOG::Log(LOG::LogLevel::WARN) << " forget to close file ";
    LOG::Dump();  // Output: [WARN] forget to close file
    LOG::Clear();
    */
    return 0;
}