# C++ Sanitizers

Sanitizers are tools in C++ that help detect various kinds of programming errors at runtime. They are invaluable for debugging and ensuring code quality. This document explains the most commonly used sanitizers and how to apply them in your C++ projects.

## 1. AddressSanitizer (ASan)

**Purpose:** Detects memory-related errors.

**What it catches:**
- Use-after-free
- Use-after-return
- Buffer overflows (stack and heap)
- Memory leaks

**Usage:** Add `-fsanitize=address` to your compilation flags.

**Example:**
```cpp
int* p = new int[10];
delete[] p;
p[0] = 42; // ASan will detect this use-after-free.
```

## 2. UndefinedBehaviorSanitizer (UBSan)

**Purpose:** Detects undefined behavior.

**What it catches:**

   - Integer overflow
   - Division by zero
   - Invalid downcasting
   - Dereferencing null pointers

**Usage:** Add `-fsanitize=undefined` to your compilation flags.

**Example:**

```cpp

int x = INT_MAX;
x += 1; // UBSan will detect this overflow.
```
## 3. ThreadSanitizer (TSan)

**Purpose:** Detects data races in multi-threaded programs.

**What it catches:**

  - Race conditions
  - Deadlocks

**Usage:** Add `-fsanitize=thread` to your compilation flags.

**Example:**
```cpp

int counter = 0;
std::thread t1([&]() { counter++; });
std::thread t2([&]() { counter--; });
t1.join();
t2.join(); // TSan will detect the data race on counter.
```
## 4. MemorySanitizer (MSan)

**Purpose:** Detects uninitialized memory reads.

**What it catches:**

    Using memory that hasn't been initialized

**Usage:** Add `-fsanitize=memory` to your compilation flags.

**Example:**

```cpp

int x;
if (x == 0) { // MSan will detect the use of uninitialized variable 'x'.
    //...
}
```
## 5. LeakSanitizer (LSan)

**Purpose:** Detects memory leaks.

**What it catches:**

    Allocated memory that is not freed before program termination

**Usage:** Often used in combination with AddressSanitizer: `-fsanitize=address` or `-fsanitize=leak`.

**Example:**

```cpp

int* p = new int[10];
// Forgot to delete[] p; LSan will report a memory leak.
```
## How to Use Sanitizers

To use a sanitizer, add the corresponding flag (e.g., `-fsanitize=address`) when compiling your code with a compiler like g++ or clang++.
Example Compilation Command

``` bash

g++ -fsanitize=address -o my_program   my_program.cpp
```
This command compiles my_program.cpp with AddressSanitizer enabled, allowing you to catch memory-related errors at runtime.

# Comparing `clang++` and `g++` with Sanitizers


| Feature/Aspect                   | `clang++`                                      | `g++`                                         |
|----------------------------------|------------------------------------------------|-----------------------------------------------|
| **Ecosystem**                    | Part of the LLVM project; fast compilation; strong tooling support (e.g., Clang Static Analyzer, Clang-Tidy). | Part of the GNU Compiler Collection; widely used in Linux distributions; stable and standards-compliant. |
| **Sanitizer Support**            | Supports AddressSanitizer, UndefinedBehaviorSanitizer, ThreadSanitizer, MemorySanitizer (Clang only), LeakSanitizer. | Supports AddressSanitizer, UndefinedBehaviorSanitizer, ThreadSanitizer, and LeakSanitizer. |
| **MemorySanitizer (MSan)**       | **Available.** Tracks uninitialized memory reads. | **Not available.** No equivalent support.    |
| **Diagnostic Quality**           | Very detailed and user-friendly; better stack traces and error messages. | Solid diagnostics but less detailed than `clang++`. |
| **Runtime Overhead**             | Slightly higher due to more comprehensive checks, especially with MSan. | Generally lower but might miss certain issues detected by `clang++`. |
| **Compile-time Performance**     | Often faster, especially in large codebases. Provides early error detection. | Good performance, but can be slower in some cases compared to `clang++`. |
| **Tooling Integration**          | Strong integration with LLVM tools like `clang-tidy`, `clang-format`; more customization options (e.g., `-fsanitize-blacklist`). | Well-integrated with GNU tools; strong support with `gdb` but fewer advanced customization options. |
| **Cross-platform Support**       | Excellent support across platforms (macOS, Linux, Windows); default on macOS (Xcode). | Strong on Linux; good support through MinGW on Windows, but Clang is generally stronger on Windows. |
| **Community and Documentation**  | Extensive documentation; frequently updated with new features; strong community support for sanitizers. | Comprehensive documentation focused on stability; new features may be introduced more slowly. |

## Summary

- **`clang++`**: Ideal for projects requiring detailed diagnostics, cutting-edge sanitizer features, and strong cross-platform support. It excels in environments where advanced debugging and tooling integration are important.
- **`g++`**: A great choice for projects emphasizing stability, wide compatibility, and integration with the GNU ecosystem. It is widely used in Linux environments and provides reliable sanitizer support.



