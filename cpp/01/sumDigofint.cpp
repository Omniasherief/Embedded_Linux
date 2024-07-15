#include<iostream>

int sumOfDigit(int num)
{ int sum=0;
    while(num!=0)
    {
    sum+=num%10;
    num=num/10;
    }
    return sum;
}
int main()
{
 int number;
 std::cout <<" Enter number ";
 std::cin>> number;
 std::cout << "Sum of Digits= "<< sumOfDigit(number)<<std::endl;

return 0;

}