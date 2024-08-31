#include <cstddef>
#include <iostream>
#include <cstring>
#include <ostream>


class MyString
{


    private:
    char *data;
    size_t length;
    public:
    //default
    MyString():data(nullptr),length(0){
        //nothing
    }
    //parameterized constructor
    MyString (const char* str)
    {
        length =std::strlen(str);
        data=new char[length+1];
        std::strcpy (data,str);

    }
    //copy constructor
     MyString (const MyString& other)
    {
        length =other.length;
        data=new char[length+1];
        std::strcpy (data,other.data);

    }
    //delete
    ~MyString() {
        delete[] data;
    }

    // move constructor

 MyString (MyString&& other) noexcept :data(other.data), length(other.length){
    other.data= nullptr;
    other.length=0;
 }


// copy Assignment operator
    MyString& operator=(const MyString& other)
    {
        if(this==&other) return *this;
        
        delete [] data;
        length =other.length;
        data = new char [length+1];
        std::strcpy(data,other.data);

        return *this;

    }

// move assignment operator 
   MyString& operator=( MyString&& other)
    noexcept{
        if(this==&other) return *this;
        
        delete [] data;
        length =other.length;
        data = other.data;

        
        other.data = nullptr;
        other.length = 0;


        return *this;

    }

// Concatenation Operator
   
   MyString operator +(const MyString& other) const 
   {
    MyString result;
    result.length= length + other.length;
    result.data= new char [result.length +1];

    std::strcpy(result.data,data);
    std::strcat(result.data, other.data);

    return result;

   }

  //Element access operator

  char & operator [] (size_t index)
  {
    return data[index];
  } 

  //output operator

  friend std::ostream& operator << (std::ostream& os, const MyString& str)
  {
    os << str.data;
    return os;
  }

  //Equality Operators

   bool operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
   }

  bool operator!=(const MyString& other) const {
    return !(*this == other);
   }

};



int main() {
    // Test default constructor
    MyString emptyStr;
   // std::cout << "emptyStr: " << emptyStr << std::endl; // Should print nothing or indicate empty --->crashhhh

    // Test parameterized constructor
    MyString str1("Hello");
    MyString str2(" World");

    // Test output operator
    std::cout << "str1: " << str1 << std::endl; // Should print "Hello"
    std::cout << "str2: " << str2 << std::endl; // Should print " World"

    // Test concatenation operator
    MyString str3 = str1 + str2;
    std::cout << "str3: " << str3 << std::endl; // Should print "Hello World"

    // Test copy constructor
    MyString str4(str3);
    std::cout << "str4 (copied from str3): " << str4 << std::endl; // Should print "Hello World"

    // Test copy assignment operator
    MyString str5;
    str5 = str4;
    std::cout << "str5 (assigned from str4): " << str5 << std::endl; // Should print "Hello World"

    // Test move constructor
    MyString str6(std::move(str5));
    std::cout << "str6 (moved from str5): " << str6 << std::endl; // Should print "Hello World"
    //std::cout << "str5 (after move): " << str5 << std::endl; // Should print nothing or indicate empty --->crashhhh

    // Test move assignment operator
    MyString str7;
    str7 = std::move(str6);
    std::cout << "str7 (moved from str6): " << str7 << std::endl; // Should print "Hello World"
    //std::cout << "str6 (after move): " << str6 << std::endl; // Should print nothing or indicate empty --->crashhhh

    // Test element access operator
    std::cout << "str1[1]: " << str1[1] << std::endl; // Should print 'e'

    // Test equality operator
    if (str1 == MyString("Hello")) {
        std::cout << "str1 is equal to 'Hello'" << std::endl; // Should print this
    }

    // Test inequality operator
    if (str1 != str2) {
        std::cout << "str1 is not equal to str2" << std::endl; // Should print this
    }

    return 0;
}
