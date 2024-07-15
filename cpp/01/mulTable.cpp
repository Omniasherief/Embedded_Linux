#include <iostream>
 int main()
 {
   int num, limit;
   std::cout <<"Enter Numer for the mul table: ";
   std::cin>>num;


   std::cout <<"Enter the limit: ";
   std::cin>>limit;
   std::cout << "Multiplication Table of " << num << std::endl;
// Loop from 1 to the entered limit
    for (int i = 1; i <= limit; ++i) {
        std::cout << num << " * " << i << " = " << num * i << std::endl;
    }
  return 0;

 }