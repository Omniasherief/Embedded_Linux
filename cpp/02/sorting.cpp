#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> numbers;
  int size,num,i=0;

  std::cout<<"enter the number of elements : ";
  std::cin>>size;

 
  std::cout<<"enter the Elements : ";
 while(i<size)
 {
    std::cin >>num;
    numbers.push_back(num);
    i++;
 }

std::sort(numbers.begin(),numbers.end(),[](int a, int b){return a<b;});
std::cout <<"Sorting in ascending order : ";
for (int num:numbers)
{
    std::cout << num <<' ';
}
std::cout <<std::endl;


std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    std::cout << "Sorted in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;

}