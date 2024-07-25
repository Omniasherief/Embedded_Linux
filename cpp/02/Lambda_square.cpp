#include <iostream>

int main()
{

 auto square =[](int x) { 
    /*auto --->  std::function<int(int)> */
     return x*x;
 };
 int num;
   std::cout <<"enter number: ";
   std::cin >> num ;
    std::cout << "The square of " << num << " is " << square(num) << std::endl;

}
