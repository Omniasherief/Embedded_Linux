#include <iostream>

int main() {
    int size;

    // Get the size of the array from the user
    std::cout << "Enter the number of elements: ";
    std::cin >> size;
int *arr=new int[size];

std::cout << "Enter the elements \n" ;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
        // Accumulate the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // Output the result
    std::cout << "The sum of the array elements is: " << sum << std::endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;




}