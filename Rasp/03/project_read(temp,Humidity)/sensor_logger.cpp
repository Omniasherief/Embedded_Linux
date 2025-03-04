#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>

void Blink_Led()
{
    std::cout << "LED BLINKS UPDATED IN CSV FILE";
}

std::string get_Timestamp()
{
    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);


}
int main() {
    std::ofstream file("sensor_data.csv", std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error opening CSV file!\n";
        return 1;
    }

    file << "Timestamp, Temperature (°C), Humidity (%)\n"; // CSV header

    while (true) {
        float temperature = 20 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 15)); // 20-35°C
        float humidity = 30 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 40));   // 30-70%

        file << get_Timestamp() << ", " << temperature << ", " << humidity << "\n";
        file.flush();  // Ensure data is written to the file

        Blink_Led();  // Simulate LED blink
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
