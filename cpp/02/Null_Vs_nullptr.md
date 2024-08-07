# Null vs nullptr in C++

This document explains the difference between null and nullptr when representing null pointers in C++.

## What is a Null Pointer?

A  `null` pointer is a special value assigned to a pointer variable to indicate that it doesn't point to any valid memory location. It essentially means the pointer is "empty" and doesn't hold a memory address.

## null vs nullptr

**There are two ways to represent a null pointer in C++:**

    - `null `: This comes from C and is typically defined as a macro that evaluates to 0.
    - `nullptr`: Introduced in C++11, it's a dedicated keyword for a null pointer value.


# Comparison of `null` and `nullptr`

## Features

A comparison table between `null` and `nullptr`:

| Feature      | `null`                          | `nullptr`                       |
|--------------|---------------------------------|---------------------------------|
| **Origin**   | C macro (often evaluates to 0)  | C++11 keyword                   |
| **Type**     | Integer literal (usually 0)     | `std::nullptr_t` (distinct null pointer type) |
| **Clarity**  | Less clear about pointer type   | Clear indication of a null pointer |
| **Type Safety** | Can be ambiguous and lead to conversion errors | Enforces type safety, preventing accidental conversions |
| **Templates** | May cause issues with some template types | Works seamlessly with templates |

             
**Why Use nullptr?**



    Clarity: It explicitly denotes a null pointer, improving code readability.
    Type Safety: The compiler can enforce type safety, preventing conversions from integer to pointer.
    Template Compatibility: It works consistently with templates due to its distinct type.

**Examples:**


**Potential Ambiguity with null:**

```cpp
// This might be interpreted as assigning the integer value 0 to the pointer
int* ptr = null;  // Can be error-prone

// This is clearer and safer
int* ptr = nullptr;

```

In the first example, the compiler might interpret null as an integer and convert it to an int* pointer, potentially leading to errors.

**Template Compatibility:**
``` cpp

template <typename T>
void print_value(T* ptr) {
  if (ptr == null) {  // Can cause issues with some template types
    std::cout << "Pointer is null." << std::endl;
  } else {
    std::cout << "Value: " << *ptr << << std::endl;
  }
}

int main() {
  int* int_ptr = nullptr;
  print_value(int_ptr);  // Works well with nullptr
  return 0;
}

```


The print_value template might have issues with null depending on the pointer type T. nullptr has a clear type (std::nullptr_t) that works consistently with templates.

**Clarity and Type Safety:**

```cpp
void check_pointer(void* ptr) {
  if (ptr == null) {  // Less clear about pointer type
    std::cout << "Pointer is null." << std::endl;
  } else {
    // ... (Do something with the pointer)
  }
}

void check_pointer(void* ptr) {
  if (ptr == nullptr) {  // Clearer and type-safe
    std::cout << "Pointer is null." << std::endl;
  } else {
    // ... (Do something with the pointer)
  }
}
```


Using **nullptr** explicitly clarifies the **null** pointer check and avoids potential type conversion issues.

