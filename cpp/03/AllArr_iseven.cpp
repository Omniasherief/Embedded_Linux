#include <iostream>

bool isEven(int arr[], int size)
{
  for(int i=0; i<size; i++)
  {
    if(arr[i]%2!=0)
    {return false;}
  }
 return true;

}

int main()
{
    int arr[20],n;
    std::cout<<"enter the size of array (max ->20)";
    std:: cin >> n;
    if(n<=20)
    {
        for(int i=0; i<n; i++)
          {std::cin >>arr[i];}
        if(isEven(arr,n))
        {std::cout <<"All elements are even\n ";}
        else 
        {
          std::cout <<"Not All elements are even\n ";
        }
    }
    else {
     std::cout<<"Invalid input !";

    }
}