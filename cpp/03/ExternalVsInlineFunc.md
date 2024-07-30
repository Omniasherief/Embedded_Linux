## Inline vs. External Functions in C++

This table compares inline and external functions in C++:

| Feature | Inline Function | External Function |
|---|---|---|
| Definition | Function defined within a class or using the `inline` keyword | Function defined outside a class or without the `inline` keyword |
| Compilation | Expanded at the call site by the compiler | Compiled separately and linked to the main program |
| Function Call Overhead | Minimal or no function call overhead | Function call overhead exists |
| Code Size | Potentially larger code size due to expansion | Smaller code size |
| Performance | Can improve performance for small functions | Generally slower due to function call overhead |
| Complexity | Can increase code complexity if overused | Simpler code structure |
| Flexibility | Less flexible, as changes require recompilation | More flexible, changes can be made independently |
