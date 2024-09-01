#include <iostream>



//1-Basic template single argument

template<typename T> T division (T x ,T y) 
{
    return x/y;
}
// 2- Basic tremplate multi arguments

template <typename T, typename U> auto division(T x, U y)
{
    return x/y;
}

//3- class template

template <typename T> class container {

    public:
    T value;
    container( T val):value (val){}
    void print()
    {
        std::cout <<"Iam in class template my value is  :"<< value<< std::endl;
    }
};



//4- class template with standalone function

template <typename T> class container2
{
    public:
    T value;
    container2 (T val): value(val){}
    template <typename U> void add(U val){value +=val;}
    void print()
    {
        std::cout <<"Iam in class template with standalone functionmy value is  :"<< value<< std::endl;
    }
};







// 5- explicit specialization
template <> class container<float> {
public:
  float value;
  container(float val) : value(val + 1) {
    std::cout << "Specialized constructor" << std::endl;
  }
};


//6- partial specialization
template <typename T,typename U> struct array{
    //primary template
    array(T t , U u ) {std::cout <<"Primary template "<< std::endl;}
};

template<typename T> struct array <T,T> 
{   
    array(T t, T u){std::cout << "partial specialization" << std::endl;}
};


//7- default template arguments

template <typename T, typename U =int> class A{
    public:
   
    T t;
    U u;
    A(T t ,U u):t(t),u(u){}


};

//8- const template expression 
template <typename T, int size> class MyArray
{
    public:
    T data[size];
    MyArray() {
    for (int i = 0; i < size; i++) {
      data[i] = i;
    }
    }
};


int main()
{
  
//1 
std::cout <<"Division (int)"<< division(10,2)<<std::endl;
std::cout <<"Division (double)"<< division(10.5,2.5)<<std::endl;

//2

std::cout <<"Division (int,double)"<< division(10,2.5)<<std::endl;
std::cout <<"Division (double,int)"<< division(10.5,2)<<std::endl;


//3
container<int> containerr(100);
containerr.print();

container<std::string> stringcontainer("Hello");
stringcontainer.print();

//4
container2<int> containerr2(100);
containerr2.add(50);
containerr2.print();

container2<std::string> stringContainer2("omnia");
stringContainer2.add(" sherief");
stringContainer2.print();


//5
 container<float> floatContainer(3.5f);
    std::cout << "Float container value: " << floatContainer.value << std::endl;


//6
array<int, double > primaryArray(1,2.5);
array<int,int> partialArray(3,4);



//7
 A<double> defaultTemplateArgs(3.14, 42);
    std::cout << "A<double, int>: t = " << defaultTemplateArgs.t << ", u = " << defaultTemplateArgs.u << std::endl;


//8
MyArray<int,5> myarray;
std::cout <<"MyArray<int,5>: ";
for (int i=0;i<5;i++)
{
    std::cout <<myarray.data[i]<<" ";
}
std::cout<<std::endl;

return 0;
}