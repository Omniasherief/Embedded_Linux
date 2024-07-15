#include <iostream>
int main()
{
  std::cout<<"ASCII TABLE\n";
  std::cout<<"-----------\n";
 
   for(int i=33;i<126;i++)
   {
      std::cout <<"| "<< (char)i <<  "  | " << i <<" |"<<  '\n';
   }
    return 0;
}
