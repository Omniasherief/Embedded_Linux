
## FIRST PART
1. **Final**: In C++, the `final` specifier is used to indicate that a class cannot be inherited from, or a virtual method cannot be overridden in derived classes. This can be useful for enforcing design constraints and optimizing performance.

   ```cpp
   class Base final {
       // This class cannot be inherited
   };

   class Derived : public Base { // Error: Base is final
   };
   ```

   ```cpp
   class Base {
   public:
       virtual void foo() final; // This method cannot be overridden
   };
   ```

-----------------------------------------------------------------------------------------

2. **`std::bind`**: This is a utility from the `<functional>` header that allows you to bind arguments to a function or method, creating a new function object. It can be used to simplify function calls and work with function pointers.

   ```cpp
   #include <functional>
   #include <iostream>

   void print(int i, double d) {
       std::cout << i << " " << d << std::endl;
   }

   int main() {
       auto bound = std::bind(print, 10, std::placeholders::_1);
       bound(3.14); // Prints: 10 3.14
   }
   ```

**std::bind(print, 10, std::placeholders::_1):** This line creates a function object called bound. The std::bind function binds the first argument of the print function to the value 10. The second argument is represented by std::placeholders::_1, which acts as a placeholder. This means the actual value for the second argument will be provided when the bound function object is called.
**bound(3.14):** When the bound function object is called with the argument 3.14, it internally calls print(10, 3.14), printing 10 3.14 to the console


-------------------------------------------------------------------------------------------------------

3. **Template `hpp`**: Templates in C++ are typically defined in header files (`.hpp` or `.h`). Templates are a powerful feature for creating generic and reusable code... template header file:

   ```cpp
   // my_template.hpp
   #ifndef MY_TEMPLATE_HPP
   #define MY_TEMPLATE_HPP

   template <typename T>
   class MyTemplate {
   public:
       MyTemplate(T value);
       T getValue() const;
   private:
       T value;
   };

   template <typename T>
   MyTemplate<T>::MyTemplate(T value) : value(value) {}

   template <typename T>
   T MyTemplate<T>::getValue() const {
       return value;
   }

   #endif
   ```

**Example Usage:**


```cpp

#include "my_template.hpp"

int main() {
    MyTemplate<int> intTemplate(10);
    std::cout << intTemplate.getValue() << std::endl; // Prints: 10

    MyTemplate<std::string> stringTemplate("Hello");
    std::cout << stringTemplate.getValue() << std::endl; // Prints: Hello

    return 0;
}
```

-----------------------------------------------------------------------------------------

4. **`stringstream`**: Part of the `<sstream>` header, `std::stringstream` is a stream class that allows you to perform input and output operations on strings.

   ```cpp
   #include <sstream>
   #include <iostream>

   int main() {
       std::stringstream ss;
       ss << 123 << " " << 45.67;

       int i;
       double d;
       ss >> i >> d;

       std::cout << "Integer: " << i << ", Double: " << d << std::endl;
   }
   ```

### Key Concepts:

- **`std::stringstream`**:
  - `std::stringstream` is a flexible and powerful tool for string manipulation, allowing you to treat strings like streams. You can insert data into a string and then extract it in a controlled manner.
  - It’s particularly useful for converting between strings and other data types, such as integers and floating-point numbers.

- **Stream Operators**:
  - `<<` (insertion operator): Used to insert data into the stream.
  - `>>` (extraction operator): Used to extract data from the stream.

### Practical Use Cases:

- **String to Number Conversion**:
  - `std::stringstream` can be used to convert strings to numbers and vice versa. This is often needed when parsing input or reading data from text files.

- **Tokenizing Strings**:
  - You can use `std::stringstream` to tokenize a string by extracting elements one by one, similar to how you would parse data from a file.

- **Building Complex Strings**:
  - `std::stringstream` allows you to concatenate different data types into a single string stream, which can then be converted to a string or processed further.

### Example Usage:

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::string input = "42 3.14";
    std::stringstream ss(input);

    int i;
    double d;
    ss >> i >> d;

    std::cout << "Integer: " << i << ", Double: " << d << std::endl;
    return 0;
}
```

- In this example, the string `"42 3.14"` is passed to `std::stringstream`, and then the integer and double are extracted. The output will be `Integer: 42, Double: 3.14`.

`std::stringstream` is a versatile tool that can simplify many tasks involving string manipulation, making your code more concise and readable.

------------------------------------------------------------------------------------------------------

5. **`chrono` Timers**: The `<chrono>` header provides facilities for measuring time and managing time durations. You can use `std::chrono` to create timers or measure the duration of code execution.

   ```cpp
   #include <chrono>
   #include <iostream>

   int main() {
       auto start = std::chrono::high_resolution_clock::now();
       // Code to measure
       auto end = std::chrono::high_resolution_clock::now();
       
       std::chrono::duration<double> elapsed = end - start;
       std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
   }
   ```

6. **Random Numbers**: The `<random>` header provides facilities for generating random numbers in C++. It includes engines and distributions to generate random numbers in a controlled manner.

   ```cpp
   #include <random>
   #include <iostream>

   int main() {
       std::random_device rd; // Obtain a random number from hardware
       std::mt19937 gen(rd()); // Seed the generator
       std::uniform_int_distribution<> distr(1, 6); // Define the range

       std::cout << "Random number: " << distr(gen) << std::endl;
   }
   ```


**std::random_device:** Provides a non-deterministic random seed, if available.
**std::mt19937:** A random number engine that generates random numbers based on the Mersenne Twister algorithm. It needs to be seeded to produce a different sequence of numbers each time.
**std::uniform_int_distribution:** Defines a distribution that generates integers uniformly over a specified range.
**distr(gen):** Generates a random number using the specified distribution and random number engine.


-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------


## SECOND PART
C++17 introduced several useful features that are part of the standard library. Here's a brief overview of `std::variant`, `std::optional`, and `std::any`:

1. **`std::variant`**: This is a type-safe union that can hold one of several types. It’s a way to create a type that can be one of many types, with automatic management of type safety and visitor patterns.

   ```cpp
   #include <variant>
   #include <iostream>
   #include <string>

   int main() {
       std::variant<int, float, std::string> v;

       v = 42;
       std::cout << std::get<int>(v) << std::endl;

       v = 3.14f;
       std::cout << std::get<float>(v) << std::endl;

       v = "Hello";
       std::cout << std::get<std::string>(v) << std::endl;

       // Using std::visit to handle the variant
       std::visit([](auto&& arg) { std::cout << arg << std::endl; }, v);
   }
   ```

   In this example, `std::variant` is used to hold an `int`, `float`, or `std::string`. The `std::visit` function is used to apply a visitor to the held value, allowing you to handle different types in a type-safe manner.

-----------------------------------------------------------------------------------------

2. **`std::optional`**: This is a utility that represents an optional value that may or may not be present. It can be useful when you want to represent a value that may be absent or to handle error conditions in a clean way.

   ```cpp
   #include <optional>
   #include <iostream>

   std::optional<int> divide(int numerator, int denominator) {
       if (denominator == 0) {
           return std::nullopt; // No value, division by zero
       }
       return numerator / denominator;
   }

   int main() {
       auto result = divide(10, 2);
       if (result) {
           std::cout << "Result: " << *result << std::endl;
       } else {
           std::cout << "Division by zero" << std::endl;
       }
   }
   ```

   Here, `std::optional` is used to return a result that might not be valid (e.g., division by zero). It allows checking if a value is present before using it.

-----------------------------------------------------------------------------------------------------------

3. **`std::any`**: This is a type-safe container for single values of any type. It can hold any type of value and provides type-safe access through `std::any_cast`.

   ```cpp
   #include <any>
   #include <iostream>
   #include <string>

   int main() {
       std::any a = 10; // can hold an int
       std::cout << std::any_cast<int>(a) << std::endl;

       a = std::string("Hello");
       std::cout << std::any_cast<std::string>(a) << std::endl;

       try {
           std::cout << std::any_cast<int>(a) << std::endl; // Will throw std::bad_any_cast
       } catch (const std::bad_any_cast& e) {
           std::cout << "Caught exception: " << e.what() << std::endl;
       }
   }
   ```

   `std::any` allows storing a value of any type, but you must use `std::any_cast` to retrieve the value and specify the correct type. If the type does not match, `std::bad_any_cast` will be thrown.

