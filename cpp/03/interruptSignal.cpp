#include<iostream>
#include<csignal> //For signal handling functions.

void handleSignal(int signal)
{   //The signal number for SIGINT is typically 2 on most Unix-like systems
    std::cout<< "\n Interrupt Signal : "<< signal <<"  received \n";
    exit(signal);
}
int main()
{
   std::signal(SIGINT,handleSignal);
    std::cout << "Press Ctrl+C to trigger the signal handler...\n";

    // Infinite loop to keep the program running and to test signal handling
    while (true) {
        // You can perform other tasks here
        
    }

}