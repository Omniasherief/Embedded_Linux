#include <iostream>

bool isAnyEven(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    // Dynamically allocate memory for the array
    int *arr = new int[size];

    std::cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    if (isAnyEven(arr, size)) {
        std::cout << "There is at least one even element." << std::endl;
    } else {
        std::cout << "There are no even elements." << std::endl;
    }

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}



/*#include <iostream>
#include <vector>
//Automatic Memory Management: std::vector automatically handles memory allocation and deallocation.
bool isAnyEven(const std::vector<int>& arr) {
    for (int num : arr) {
        if (num % 2 == 0) {
            return true;
        }
    }
    return false;
}
int main()
{
int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    // Using std::vector for dynamic array management
    std::vector<int> arr(size);

    std::cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    if (isAnyEven(arr)) {
        std::cout << "There is at least one even element." << std::endl;
    } else {
        std::cout << "There are no even elements." << std::endl;
    }

    return 0;
    }
    */







/*

//static
#include <iostream>

bool isAnyEven(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 3, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isAnyEven(arr, size)) {
        std::cout << "There is at least one even element." << std::endl;
    } else {
        std::cout << "There are no even elements." << std::endl;
    }

    return 0;
}*/

