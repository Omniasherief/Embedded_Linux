
#include <iostream>


int main() {
    int num1, num2, num3;

    std::cout << "Enter three numbers separated by spaces: ";
    std::cin >> num1 >> num2 >> num3;

    // Find the maximum using a single conditional expression
    int max_value = (num1 > num2) ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);

    std::cout << "Max is: " << max_value << std::endl;

    return 0;
}