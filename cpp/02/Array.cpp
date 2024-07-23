#include <iostream>


int FindMax(int arr[], int size)
{
    if (size==0)
      { 
       std::cout <<"Array is Empty";
       return -1;
      }
  int max=arr[0];
   for (int i=1;i<size;i++)
    {
       if(arr[i] > max)
        {
        max=arr[i];
        }
    }
   return max;
}
void searchNum(const int arr[], int size, int number) {
    // Check if the array is empty
    if (size <= 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }

    bool found = false;
    // Iterate through the array to search for the number
    for (int i = 0; i < size; ++i) {
        if (arr[i] == number) {
            // Number is found, output its index and position
            std::cout << "Number " << number << " is found at index " << i << "." << std::endl;
            std::cout << "It is the " << (i + 1) << " element in the array." << std::endl;
            found = true;
            break;
        }
    }

    // If the number was not found, inform the user
    if (!found) {
        std::cout << "Number " << number << " is not found in the array." << std::endl;
    }
}

int DeleteNumber(int arr[], int size, int number) {
    if (size <= 0) {
        std::cout << "Array is empty or size is invalid." << std::endl;
        return size;
    }

    int newSize = size;
    bool numberFound = false;

    for (int i = 0; i < newSize; ) {
        if (arr[i] == number) {
            // Number found; shift elements to the left
            for (int j = i; j < newSize - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            // Reduce the size of the array
            --newSize;
            numberFound = true;
        } else {
            // Move to the next element if no deletion occurred
            ++i;
        }
    }

   
    return newSize;
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    for (int i = 0; i < size1; ++i) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        merged[size1 + i] = arr2[i];
    }
}
void FindEvenorOdd(int arr[], int size)
{
    int even=0;
    int odd=0;
 for (int i = 0; i < size; ++i) {
       if(arr[i]%2==0)
       {even++;
        std::cout<<"number "<< arr[i]<<" is Even\n";
       }
       else 
       {
        odd++;
        std::cout<<"number "<< arr[i]<<" is ODD\n";
       }
    }
 std::cout <<"# Even:"<<even<<std::endl;
std::cout <<"# ODD:"<<odd;
}


int main()
{
 int Arr1[10],Arr2[10],merged[20],n1,n2,choice;
    std::cout << "Enter the Size of first array(max size 10): ";
    std::cin >> n1;
    if(n1<=10)
    {
        std::cout << "Enter the elements of the first array: ";
          for (int i = 0; i < n1; ++i)
            std::cin >> Arr1[i];

        std::cout << "Choose an option:\n";
        std::cout << "1. Find the maximum number in an array\n";
        std::cout << "2. Search for a number in the array\n";
        std::cout << "3. Delete a number from the array\n";
        std::cout << "4. Merge two arrays\n";
        std::cout << "5. Find even and odd numbers in the array\n";
        std::cin >> choice;

        switch (choice) {
                case 1: {
                    int maxNumber = FindMax(Arr1, n1);
                    std::cout << "Maximum number: " << maxNumber << std::endl;
                    break;
                }
                case 2: {
                    int numberToSearch;
                    std::cout << "Enter the number to search: ";
                    std::cin >> numberToSearch;
                    searchNum(Arr1, n1, numberToSearch);
                 
                    break;
                }
                case 3: {
                        int numberToDelete;
                        std::cout << "Enter the number to delete: ";
                        std::cin >> numberToDelete;
                        
                        // Call the deleteNumber function and update the size of the array
                        int newSize = DeleteNumber(Arr1, n1, numberToDelete);

                        if (newSize == n1) {
                            // If the size did not change, the number was not found
                            std::cout << "Number " << numberToDelete << " was not found in the array." << std::endl;
                        } else {
                            // Update the size of the array
                            n1 = newSize;

                            // Display the updated array
                            std::cout << "Array after deleting " << numberToDelete << ": ";
                            for (int i = 0; i < n1; ++i) {
                                std::cout << Arr1[i] << " ";
                            }
                            std::cout << std::endl;
                        }
                        break;
                }
                case 4: 
                {
                    std::cout << "Enter the number of elements in the second array: ";
                    std::cin >> n2;
                    std::cout << "Enter the elements of the second array: ";
                    for (int i = 0; i < n2; ++i) 
                        {
                           std::cin >> Arr2[i];
                        }

                    mergeArrays(Arr1, n1, Arr2, n2, merged);
                    std::cout << "Merged array: ";
                    for (int i = 0; i < n1 + n2; ++i) 
                        std::cout << merged[i] << " ";

                    std::cout << std::endl;
                    break;
                }
                case 5: {
                    FindEvenorOdd(Arr1, n1);
                
                    std::cout << std::endl;
                    break;
                }
                default:
                    std::cout << "Invalid option!" << std::endl;
                    break;
            }
    }       
    else 
    {
        std::cout<<"Not Available Size"<< std::endl;
    }

   

    return 0;
}


