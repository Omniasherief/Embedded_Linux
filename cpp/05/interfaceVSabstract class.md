

# Comparing Interface Classes and Abstract Classes in C++

In C++, both interface classes and abstract classes are used to define abstract behavior and enforce contracts for derived classes. Understanding their differences and use cases is crucial for designing robust and maintainable object-oriented systems. This document provides a comparison of interface classes and abstract classes in C++.

## Interface Class

### Definition
An interface class in C++ is a class that contains only pure virtual functions. It defines a contract that derived classes must adhere to without providing any implementation details.

### Characteristics
1. **Pure Virtual Functions Only**:
   - All member functions are pure virtual (`= 0`).
   - **Example**:
     ```cpp
     class IShape {
     public:
         virtual void draw() const = 0; // Pure virtual function
         virtual double area() const = 0; // Pure virtual function
     };
     ```

2. **No Data Members**:
   - Interfaces typically do not contain data members. They are focused on defining behavior.

3. **Multiple Inheritance**:
   - A class can implement multiple interfaces, allowing for multiple inheritance.

4. **Implementation**:
   - Derived classes must implement all pure virtual functions to be instantiated.

5. **Polymorphism**:
   - Interfaces facilitate polymorphism, enabling different classes to be used interchangeably if they implement the same interface.

### Example
```cpp
class IShape {
public:
    virtual void draw() const = 0;
    virtual double area() const = 0;
};
```

## Abstract Class

### Definition
An abstract class in C++ is a class that contains at least one pure virtual function but can also include concrete methods, data members, and constructors. It provides a partial implementation or shared behavior.

### Characteristics
1. **Pure Virtual and Concrete Functions**:
   - Can contain both pure virtual functions and concrete methods.
   - **Example**:
     ```cpp
     class Shape {
     public:
         virtual void draw() const = 0; // Pure virtual function
         void printInfo() const { std::cout << "Shape information" << std::endl; } // Concrete method
     };
     ```

2. **Can Have Data Members**:
   - Abstract classes can have data members that derived classes can inherit and use.

3. **Single Inheritance**:
   - Abstract classes typically support single inheritance but can be part of a complex class hierarchy.

4. **Implementation**:
   - Derived classes must implement all pure virtual functions to become concrete classes. They can also use or override concrete methods provided by the abstract class.

5. **Polymorphism**:
   - Abstract classes also support polymorphism, allowing derived classes to be used interchangeably based on the abstract base class.

### Example
```cpp
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
    void printInfo() const { std::cout << "Shape information" << std::endl; } // Concrete method
};
```

## Comparison

| Feature             | Interface Class                        | Abstract Class                           |
|---------------------|----------------------------------------|------------------------------------------|
| **Purpose**         | Defines a contract with no implementation details | Defines a contract and can provide partial implementation |
| **Members**         | No data members or concrete methods    | Can have data members and concrete methods |
| **Inheritance**     | Supports multiple inheritance          | Typically used in single inheritance, but can be part of complex hierarchies |
| **Flexibility**     | Ideal for defining APIs and ensuring conformance to a contract | Useful for providing common functionality and shared code |

## When to Use Each

- **Use an Interface Class** when you want to define a contract for multiple classes to implement, especially when those classes do not share a common base or when you need multiple inheritance.

- **Use an Abstract Class** when you need a base class with some common functionality and shared code, and you want to enforce that derived classes provide specific implementations for certain methods.


