#include<iostream>
#include <cctype>

int main()
{
char var;
std::cout <<"Enter character : ";
std::cin>> var;
if(isdigit(var))
{
    std::cout << var <<" is a digit \n";
}
else 
{
    std::cout << var <<" is not a digit \n";
}

}