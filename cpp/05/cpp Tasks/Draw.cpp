#include <iostream>
#include <limits>
//interface class
class Drawable
{
    public:
    virtual void draw() const = 0; //pure virtual func
};
// base class
class shape{

    public:
    virtual ~shape()=default;
};


//derived class

class circle:public shape,public Drawable{

    public:
      void draw() const override{
        std::cout <<"Drawing a circle"<< std::endl;
        std::cout << "   ***   " << std::endl;
        std::cout << " *     * " << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << " *     * " << std::endl;
        std::cout << "   ***   " << std::endl;

      }
};

class Rectangle:public shape,public Drawable{

    public:
      void draw() const override{
        std::cout <<"Drawing a Rectangle"<< std::endl;
        std::cout << "*********" << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << "*********" << std::endl;

      }
};


class Triangle:public shape,public Drawable{

    public:
      void draw() const override{
        std::cout <<"Drawing a Triangle"<< std::endl;
        std::cout << "   *   " << std::endl;
        std::cout << "  ***  " << std::endl;
        std::cout << " ***** " << std::endl;
        std::cout << "*******" << std::endl;

      }
};

int main()
{
  
  
  /*  
  //objs
  circle cir;
  Rectangle rec;
  Triangle  tri;

  //pointers to drawable interface
  Drawable *draw1=&cir;
  Drawable *draw2=&rec;
  Drawable *draw3=&tri;

  //calling draw() through interface pointers
  draw1->draw();
    draw2->draw();
      draw3->draw();

      return 0;
*/
    circle cir;
    Rectangle rec;
    Triangle tri;

    Drawable* drawable = nullptr;

    int choice;

    do {
        std::cout << "Choose a shape to draw:\n";
        std::cout << "1. Circle\n";
        std::cout << "2. Rectangle\n";
        std::cout << "3. Triangle\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
      
          // Input handling
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            choice = 0; // Set choice to an invalid option to trigger the default case
        }
      
        switch (choice) {
            case 1:
                drawable = &cir;
                break;
            case 2:
                drawable = &rec;
                break;
            case 3:
                drawable = &tri;
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
            drawable=nullptr;
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

            if(drawable != nullptr && choice != 4) {
                drawable->draw();
                std::cout << std::endl;
            }
          
       } while (choice != 4);
 

 
    return 0;

}