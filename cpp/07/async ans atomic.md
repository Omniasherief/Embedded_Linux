
### `std::async`

Think of `std::async` as a way to do some work in the background while your main program continues to run. Imagine you have a task that takes time, like downloading a file, and you don't want to wait for it to finish before moving on to other tasks.

Here’s a simple example:

```cpp
#include <iostream>
#include <future>
#include <chrono>

// A function that takes some time to complete
int long_running_task() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long task
    return 42;
}

int main() {
    // Start the long task asynchronously
    std::future<int> result = std::async(std::launch::async, long_running_task);

    // Continue with other work while the long task runs
    std::cout << "Doing other work..." << std::endl;

    // Wait for the result of the long task
    int value = result.get(); // This will block until the long task is complete

    std::cout << "Long task result: " << value << std::endl;

    return 0;
}
```

- `std::async` runs `long_running_task` in a separate thread.
- The `result.get()` call waits for the task to finish and retrieves the result.

### `std::atomic`

`std::atomic` is used to make sure that operations on a variable are safe when accessed from multiple threads. Imagine you have a counter that multiple threads might update at the same time. Using `std::atomic`, you can ensure that updates to the counter are done safely without corrupting the data.

Here’s a simple example:

```cpp
#include <iostream>
#include <atomic>
#include <thread>

// An atomic counter
std::atomic<int> counter(0);

// A function that increments the counter
void increment_counter() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1); // Atomically increment the counter
    }
}

int main() {
    // Start two threads that increment the counter
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Print the final value of the counter
    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
```

- `std::atomic<int> counter(0);` creates an atomic integer.
- `counter.fetch_add(1);` safely increments the counter, even if multiple threads are doing it simultaneously.

### Summary

- **`std::async`**: Runs tasks in the background and lets you get the result later.
- **`std::atomic`**: Ensures safe updates to variables when accessed by multiple threads.
