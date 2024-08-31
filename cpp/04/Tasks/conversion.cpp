#include <iostream>
#include <string>

class Complex {
private:
    int real;
    float img;
    std::string string;
public:
   Complex()=default;
   Complex(int real,float img):real(real),img(img){}

   void print()
   {
    std::cout <<"Real is " <<real <<"Img is " <<img << std::endl;
   }

   //NO vuable conversion from 'Complex' to std::string (aka 'basic_string<char>')
   //so we do operator here
   operator std::string(){
    string=std::to_string(real)+"+"+ std::to_string(img)+"j";
    return string;
   }
};

int main() {
    Complex comp(2,6.7);
    std::string result=comp;
    std::cout <<result <<std::endl;
    return 0;
}
