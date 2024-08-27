# Understanding Vtables and Dynamic Binding in C++
## What is a Vtable?

## Virtual Table (Vtable)

A Vtable is a mechanism used by C++ to support dynamic dispatch of virtual functions. When a class contains virtual functions, the compiler creates a Vtable for that class. This table holds pointers to the virtual functions that can be called on objects of the class.


## Vtable Structure

**Class-Specific :** Each class with virtual functions has its own Vtable.
**Static Table :** The Vtable is typically a static table associated with a class and it holds pointers to the virtual functions of that class.
**Virtual Function Pointer :** The entries in the Vtable are pointers to the virtual functions, which are used during dynamic dispatch.

## How Dynamic Binding Works

### Virtual Function

A method in a base class is declared as virtual, signaling to the compiler that the method can be overridden in derived classes. The exact method to call should be determined at runtime, depending on the object's actual type.


### Object Layout

Each object of a class with virtual functions contains a pointer to the Vtable of its class. This pointer is usually the first member of the object’s memory layout, though this is not guaranteed.

### Dynamic Dispatch

When a virtual function is called on an object, the compiler uses the Vtable pointer of the object to find the correct function implementation. This enables the program to decide at runtime which function to execute based on the actual object type.

## Example 1: Basic Inheritance

```cpp

#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // Calls Derived's show function due to dynamic binding
    delete obj;
    return 0;
}
```
### Explanation

- The show function in the `Base` class is declared as virtual.
- `Derived` overrides the `show`function.
- The function call `obj->show()` at runtime decides which show function to call based on the object's actual type `(Derived)`.

## Example 2: Using Pure Virtual Functions

```cpp

#include <iostream>

class AbstractBase {
public:
    virtual void show() = 0;  // Pure virtual function
    virtual ~AbstractBase() {}
};

class ConcreteDerived : public AbstractBase {
public:
    void show() override {
        std::cout << "ConcreteDerived class show function" << std::endl;
    }
};

int main() {
    AbstractBase* obj = new ConcreteDerived();
    obj->show();  // Calls ConcreteDerived's show function
    delete obj;
    return 0;
}
```
### Explanation

- The `show` function in AbstractBase is a `pure` virtual function, making AbstractBase an abstract class.
- `ConcreteDerived` provides the implementation for the `show` function.
- At runtime, the correct function is called based on the actual type of the object `(ConcreteDerived)`.

## Example 3: Virtual Destructors

``` cpp

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base class destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived class destructor" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Derived's destructor first, then Base's destructor
    return 0;
}
```
### Explanation

- The `~Base()` destructor is virtual, ensuring that the destructor of Derived is called first when deleting a `Derived object  via a Base pointer.
- Proper cleanup of derived class objects is achieved through this mechanism.

## Key Points

**Virtual Destructors:** Always declare destructors as virtual in base classes when using inheritance to ensure proper cleanup of derived class objects.
**Pure Virtual Functions:** Declaring a function as virtual void show() = 0; makes the class abstract, meaning you cannot instantiate it directly.
**Polymorphism:** Dynamic binding through Vtables enables polymorphic behavior in C++, allowing derived classes to override base class methods and ensuring the correct method is called based on the actual object type at runtime.

## Conclusion

Vtables and dynamic binding are fundamental in achieving runtime polymorphism in C++. Understanding how they work allows for more flexible and maintainable code, especially when working with complex inheritance hierarchies.