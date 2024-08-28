In C++, `push_back` and `emplace_back` are both member functions of the `std::vector`, `std::deque`, and other standard containers that allow you to add elements to the end of the container. However, they differ in how they handle the elements being added.

### `push_back`

- **Purpose**: `push_back` is used to add a new element to the end of a container. 
- **Usage**: It requires an existing object to be passed to it. This object is then copied or moved into the container.
- **Syntax**: 
  ```cpp
  container.push_back(value);
  ```
- **Example**:
  ```cpp
  std::vector<int> v;
  int num = 10;
  v.push_back(num);  // Adds a copy of num to the end of the vector
  ```

- **Key Point**: `push_back` involves a copy (or move, if possible) of the object being added, which can be less efficient for complex types.

### `emplace_back`

- **Purpose**: `emplace_back` constructs the element in place at the end of the container, using the arguments provided to directly initialize the element.
- **Usage**: It allows you to pass the arguments needed to construct the object directly in the container, avoiding unnecessary copying or moving.
- **Syntax**:
  ```cpp
  container.emplace_back(args...);
  ```
- **Example**:
  ```cpp
  std::vector<std::pair<int, std::string>> v;
  v.emplace_back(1, "example");  // Constructs the pair<int, std::string> directly in the vector
  ```

- **Key Point**: `emplace_back` is generally more efficient than `push_back` for complex types because it avoids the extra step of creating a temporary object and then copying or moving it.

### Example Comparison

Consider a class `MyClass` that is expensive to copy:

```cpp
class MyClass {
public:
    MyClass(int x, double y) {
        // Some expensive construction
    }
};
```

#### Using `push_back`:
```cpp
std::vector<MyClass> v;
MyClass obj(1, 2.0);   // Object is created
v.push_back(obj);      // Copy constructor is called to add the object to the vector
```

#### Using `emplace_back`:
```cpp
std::vector<MyClass> v;
v.emplace_back(1, 2.0);  // Object is constructed directly in the vector, no copy is needed
```

### Summary

- **`push_back`**: Adds an existing object to the container, involving a copy or move.
- **`emplace_back`**: Constructs the object directly in the container, potentially more efficient, especially for complex types.

In general, if you're adding a simple type (like an `int` or `double`), the difference between `push_back` and `emplace_back` might be negligible. However, for more complex types or when performance is a concern, `emplace_back` can be the better choice.