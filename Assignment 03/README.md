# Assignment 03

## Linked List Implementations

This assignment focuses on implementing and understanding linear linked-list data structures in C++.

It includes two programs:

- Single linked list implementation
- Double linked list implementation

Both programs support core list operations such as insertion, updating, deletion, retrieval, and traversal while managing dynamic memory safely.

## Files

| File | Description |
| --- | --- |
| `single_linked_list.cpp` | Implements a singly linked list with `insert`, `update`, `deleteNode`, `retrieve`, and `printSingleList` operations. |
| `double_linked_list.cpp` | Implements a doubly linked list with `insertDouble`, `updateDouble`, `deleteDouble`, `retrieveDouble`, and `printDoubleList` operations. |

## Implemented Operations

### Single Linked List
- Insert a new record by `id` and `name`
- Prevent duplicate IDs
- Update an existing record by `id`
- Delete a record by `id`
- Retrieve a name by `id`
- Print all list elements

### Double Linked List
- Insert a new record by `id` and `name`
- Prevent duplicate IDs
- Update an existing record by `id`
- Delete a record by `id`
- Retrieve a name by `id`
- Print all list elements in forward order
- Maintain `prev` and `next` pointers correctly

## Compilation

Compile the single linked list program:

```powershell
g++ single_linked_list.cpp -o single_linked_list.exe
.\single_linked_list.exe
```

Compile the double linked list program:

```powershell
g++ double_linked_list.cpp -o double_linked_list.exe
.\double_linked_list.exe
```

## Learning Objectives

- Understand node-based dynamic memory allocation
- Compare singly and doubly linked list behavior
- Practice pointer manipulation and list traversal
- Implement common CRUD operations on linked structures

## Author

- Ali Zulfiqar
- Student ID: 2026199005
- Email: zulfiqar@chungbuk.ac.kr
