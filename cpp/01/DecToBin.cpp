

#include <iostream>
#include <bitset>
#include <string>

void decimalToBinary() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;
    std::bitset<32> binaryNumber(decimalNumber); // 32 bits for larger numbers
    std::cout << "Decimal: " << decimalNumber << " -> Binary: " << binaryNumber << std::endl;
}

void binaryToDecimal() {
    std::string binaryString;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryString;
    std::bitset<32> binaryNumber(binaryString);
    unsigned long decimalNumber = binaryNumber.to_ulong();
    std::cout << "Binary: " << binaryString << " -> Decimal: " << decimalNumber << std::endl;
}

int main() {
    int choice;
    std::cout << "Choose an option:\n";
    std::cout << "1. Convert Decimal to Binary\n";
    std::cout << "2. Convert Binary to Decimal\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            decimalToBinary();
            break;
        case 2:
            binaryToDecimal();
            break;
        default:
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
    }

    return 0;
}