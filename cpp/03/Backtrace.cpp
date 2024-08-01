#include <iostream>
#include <stack>
#include <string>

class Backtrace
{
  private:
    std::stack<std::string> stack;
  public:
  void EnterFunc(const std::string & FuncName)
  {
    stack.push(FuncName); // Correct usage
    std::cout << "Enter to " <<FuncName<<" \n";

  }
  void ExitFunc()
  {
    if(!stack.empty())
    {
          std::cout << "Exit From [" << stack.top() << "]" << std::endl;
            stack.pop();
    }

  
  }

 void printBacktace()
  {
      std::cout << "Backtrace as follows:" << std::endl;
         std::stack<std::string> tempStack = stack;//Copy the Stack
   // Use a temporary stack to reverse the order
    std::stack<std::string> reverseStack;
    while (!tempStack.empty())
    {
        reverseStack.push(tempStack.top());
        tempStack.pop();
    }

    // Print elements from the reversed stack
    int index = 0;
    while (!reverseStack.empty())
    {
        std::cout << index++ << "- " << reverseStack.top() << std::endl;
        reverseStack.pop();
    }
  }


};
// Function declarations
void func1(Backtrace &bt);
void func2(Backtrace &bt);
void func3(Backtrace &bt);


void func1(Backtrace &bt)
{
    bt.EnterFunc(("FUNC1"));
    func2(bt);
    bt.ExitFunc();
}
void func2(Backtrace &bt)
{
    bt.EnterFunc(("FUNC2"));
    func3(bt);
    bt.ExitFunc();
}
void func3(Backtrace &bt)
{
    bt.EnterFunc(("FUNC3"));
    bt.printBacktace();
    bt.ExitFunc();
}

int main()
{

     Backtrace bt;
    bt.EnterFunc("main");
    func1(bt);
    bt.ExitFunc();
    return 0;
}