#include <iostream>
#include <cstring>

class Mystring{
    private:
    char * str;
    size_t length;
    public:
    //default constructor
    Mystring():
     str(nullptr),
     length(0){}
    //parameterizes constructor
    Mystring(const char * s){
        length=strlen(s);
        str= new char[length+1];
        strcpy(str,s);
        
    }
   // Function to get the length of the string
     size_t getLength() const {
        return length;
    }
    
     // Function to get the C-string
    const char* getCString() const {
        return str;
    }

   ~Mystring() {
        delete[] str;
    }
};


int main()
{

   std::cout <<"Enter a string: ";
   std::string input;
   std::getline(std::cin, input);

   Mystring mystr(input.c_str());
   std::cout <<"string: "<<mystr.getCString()<<std::endl;
   std::cout << "Length: " << mystr.getLength() << std::endl;


    return 0;
}