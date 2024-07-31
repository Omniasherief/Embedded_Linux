#include <iostream>
int &f()
{

    static int x=0;
    std::cout<<x<<std::endl;
    return x;
}

int main()
{
   f() = 10; // Set x to 10 via the reference returned by f()
    f() = 5;  // Set x to 5 via the reference returned by f()
    f();      // Print the current value of x
}
//output is 0,10,5 