# Assignment 02

## Stack and Queue

This assignment practices stack and circular queue operations using linked data and dynamic memory allocation in C.

## Tasks

* Implement a stack using linked nodes.
* Implement `push`, `pop`, and stack display operations.
* Implement a circular queue using an array of node pointers.
* Implement insertion, deletion, and queue display operations.
* Handle overflow, underflow, and allocation errors.

## Files

| File | Description |
| --- | --- |
| `stack.c` | Implements a linked-list stack and a circular queue. |
| `practice part/stack_linkedlist.cpp` | C++ linked-list stack practice. |
| `practice part/stack_practice.cpp` | Additional stack practice. |

## Compilation

Compile and run the main C program with GCC:

```powershell
gcc stack.c -o stack.exe
.\stack.exe
```

Compile the practice programs with a C++ compiler such as G++:

```powershell
g++ "practice part/stack_linkedlist.cpp" -o stack_linkedlist.exe
.\stack_linkedlist.exe
```