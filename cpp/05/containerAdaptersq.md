
# ContainerAdapters

## Overview

ContainerAdapters are abstractions that provide specific interfaces for underlying container types in C++. This document explains three commonly used container adapters: `stack`, `queue`, and `priority_queue`. These adapters use standard container types as their underlying storage while providing a customized interface to interact with them.

## Container Adapters

### 1. Stack

A `stack` is a container adapter that follows the Last In, First Out (LIFO) principle. It allows for inserting and removing elements from only one end, known as the top of the stack.

#### Operations:
- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the element from the top of the stack.
- **Top**: Retrieves the element at the top of the stack without removing it.
- **Empty**: Checks if the stack is empty.
- **Size**: Returns the number of elements in the stack.

#### Example:
```cpp
#include <stack>
#include <iostream>

int main() {
    std::stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    std::cout << "Top element: " << stk.top() << std::endl; // Output: 30

    stk.pop();
    std::cout << "Top element after pop: " << stk.top() << std::endl; // Output: 20

    return 0;
}
```

### 2. Queue

A `queue` is a container adapter that follows the First In, First Out (FIFO) principle. It allows for inserting elements at the back and removing elements from the front.

#### Operations:
- **Push**: Adds an element to the back of the queue.
- **Pop**: Removes the element from the front of the queue.
- **Front**: Retrieves the element at the front of the queue without removing it.
- **Back**: Retrieves the element at the back of the queue without removing it.
- **Empty**: Checks if the queue is empty.
- **Size**: Returns the number of elements in the queue.

#### Example:
```cpp
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << std::endl; // Output: 10

    q.pop();
    std::cout << "Front element after pop: " << q.front() << std::endl; // Output: 20

    return 0;
}
```

### 3. Priority Queue

A `priority_queue` is a container adapter that provides a way to retrieve the highest-priority element first. By default, it uses a max-heap, which ensures that the largest element is always at the top. Custom comparators can be used to define different priority criteria.

#### Operations:
- **Push**: Adds an element to the priority queue.
- **Pop**: Removes the highest-priority element from the priority queue.
- **Top**: Retrieves the highest-priority element without removing it.
- **Empty**: Checks if the priority queue is empty.
- **Size**: Returns the number of elements in the priority queue.

#### Example:
```cpp
#include <queue>
#include <iostream>

int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);

    std::cout << "Top element: " << pq.top() << std::endl; // Output: 30

    pq.pop();
    std::cout << "Top element after pop: " << pq.top() << std::endl; // Output: 20

    return 0;
}
```


