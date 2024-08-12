# The Rule of Three, Rule of Five, and Rule of Zero in C++

In C++, managing resource ownership and preventing resource leaks is crucial. The **Rule of Three**, **Rule of Five**, and **Rule of Zero** are guidelines that help in handling resources safely and efficiently. This guide explains each rule with examples.

## Rule of Three

The Rule of Three states that if a class needs to define a destructor, copy constructor, or copy assignment operator, it should explicitly define all three. **This rule helps to manage resources correctly and avoid resource leaks or undefined behavior**.

### Explanation

- **Destructor**: Cleans up resources when an object is destroyed.
- **Copy Constructor**: Initializes a new object as a copy of an existing object.
- **Copy Assignment Operator**: Assigns the state of one object to another existing object.

### Example

Consider a class that manages a dynamically allocated array:

```cpp
#include <iostream>

class RuleOfThree {
private:
    int* data;
    size_t size;
public:
    // Constructor
    RuleOfThree(size_t s) : size(s), data(new int[s]) {}

    // Destructor
    ~RuleOfThree() {
        delete[] data;
    }

    // Copy Constructor
    RuleOfThree(const RuleOfThree& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
    }

    // Copy Assignment Operator
    RuleOfThree& operator=(const RuleOfThree& other) {
        if (this == &other) return *this; // self-assignment check

        delete[] data;

        size = other.size;
        data = new int[other.size];
        std::copy(other.data, other.data + other.size, data);

        return *this;
    }
};

int main() {
    RuleOfThree obj1(5);
    RuleOfThree obj2 = obj1; // Calls Copy Constructor
    RuleOfThree obj3(10);
    obj3 = obj1; // Calls Copy Assignment Operator
    return 0;
}
```
### Explanation

**Destructor:** Deletes the dynamically allocated array to avoid memory leaks.
**Copy Constructor:** Creates a deep copy of the array to prevent multiple objects from managing the same memory.
**Copy Assignment Operator:** Handles self-assignment, deletes the existing array, and creates a deep copy.

## Rule of Five

The Rule of Five extends the Rule of Three to include `move operations`. It states that if a class needs to define a destructor, copy constructor, or copy assignment operator, it should also explicitly define a move constructor and move assignment operator.
Explanation

**Move Constructor:** Transfers ownership of resources from a temporary object to a new object.
**Move Assignment Operator:** Transfers ownership of resources from a temporary object to an existing object.

### Example

Consider a class that needs to handle both copying and moving of a dynamically allocated array:

```cpp

#include <iostream>
#include <utility> // For std::move

class RuleOfFive {
private:
    int* data;
    size_t size;
public:
    // Constructor
    RuleOfFive(size_t s) : size(s), data(new int[s]) {}

    // Destructor
    ~RuleOfFive() {
        delete[] data;
    }

    // Copy Constructor
    RuleOfFive(const RuleOfFive& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
    }

    // Copy Assignment Operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this == &other) return *this; // self-assignment check

        delete[] data;

        size = other.size;
        data = new int[other.size];
        std::copy(other.data, other.data + other.size, data);

        return *this;
    }

    // Move Constructor
    RuleOfFive(RuleOfFive&& other) noexcept : size(other.size), data(other.data) 
    {//The && denotes an rvalue reference that can bind to a temporary object. It indicates that the object being moved from (other) is temporary
        other.size = 0;
        other.data = nullptr;
    }

    // Move Assignment Operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this == &other) return *this; // self-assignment check

        delete[] data;

        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;

        return *this;
    }
};

int main() {
    RuleOfFive obj1(5);
    RuleOfFive obj2 = std::move(obj1); // Calls Move Constructor
    RuleOfFive obj3(10);
    obj3 = std::move(obj2); // Calls Move Assignment Operator
    return 0;
}
```
### Explanation

**Move Constructor:** Takes ownership of the resource from other and leaves other in a valid but empty state.
**Move Assignment Operator:** Transfers ownership of the resource from other and ensures proper cleanup of existing resources.

## Rule of Zero

The Rule of Zero suggests that you should avoid explicitly defining destructors, copy constructors, copy assignment operators, move constructors, and move assignment operators by using smart pointers and other RAII techniques. By relying on the standard library’s resource management facilities, you can minimize the need for manual resource management.
### Explanation

The Rule of Zero promotes the use of `RAII` (Resource Acquisition Is Initialization) principles where resource management is handled by standard library classes like std::unique_ptr, std::shared_ptr, and std::vector. By using these classes, you avoid the need to manually define special member functions.
### Example

Here’s how you can use std::unique_ptr to manage a dynamically allocated array without defining special member functions:

```cpp

#include <iostream>
#include <memory>

class RuleOfZero {
private:
    std::unique_ptr<int[]> data;
    size_t size;
public:
    // Constructor
    RuleOfZero(size_t s) : size(s), data(std::make_unique<int[]>(s)) {}

    // No need for Destructor, Copy Constructor, Copy Assignment Operator,
    // Move Constructor, or Move Assignment Operator

    // Example of a method to access elements
    int& operator[](size_t index) {
        return data[index];
    }
};

int main() {
    RuleOfZero obj1(5);
    obj1[0] = 10;
    std::cout << "obj1[0] = " << obj1[0] << std::endl;
    return 0;
}
```
### Explanation

`std::unique_ptr` automatically handles resource cleanup, so you don’t need to define special member functions for managing the resource.
`RAII principles` ensure that resources are properly acquired and released without manual intervention.



Rule of Three: Define a destructor, copy constructor, and copy assignment operator if you manage resources manually.
Rule of Five: Extend the Rule of Three by also defining a move constructor and move assignment operator if your class manages resources.
Rule of Zero: Avoid defining special member functions by using standard library facilities (like smart pointers) to handle resource management.

Following these rules helps in writing safer and more maintainable C++ code, especially when dealing with resource management and object ownership.