# CS50 C Practice — Data Structures

This folder contains small C programs created while studying the **Data Structures** section of CS50.

The goal of this practice block was to understand how basic data structures are built manually in C using `struct`, pointers, `malloc`, and linked nodes.

This topic was more difficult than previous C practice sections because it combines several concepts at once:

* custom data types;
* pointers;
* dynamic memory allocation;
* linked memory structures;
* manual traversal;
* manual memory cleanup.

## Context

These programs were written in standard C without using the CS50 library.

Working directory:

```bash
~/Projects/learning/cs50/practice/06-data-structures
```

Main topics practiced:

* `typedef struct`;
* structs and struct fields;
* arrays of structs;
* linked list nodes;
* pointers to structs;
* the `->` operator;
* dynamic memory allocation with `malloc`;
* memory cleanup with `free`;
* linked list traversal;
* inserting nodes at the front;
* searching linked lists;
* sorted linked list insertion.

## Files

### `student_struct.c`

Creates a single `student` struct, fills its fields, and prints the result.

Practiced:

* defining a custom struct type;
* using `typedef`;
* accessing struct fields with `.`;
* copying strings into a struct field with `strcpy`.

Example concept:

```c
typedef struct
{
    char name[100];
    int age;
}
student;
```

### `students_array.c`

Creates an array of `student` structs and prints each student with a loop.

Practiced:

* arrays of structs;
* accessing fields through array indexes;
* looping over structured data.

Example concept:

```c
student students[3];

strcpy(students[0].name, "Nikita");
students[0].age = 19;
```

### `node_create.c`

Creates a single linked list node with `malloc`.

Practiced:

* defining a `node` struct;
* allocating memory for one node;
* checking whether `malloc` returned `NULL`;
* accessing fields through a pointer with `->`;
* setting `next` to `NULL`;
* freeing allocated memory.

Example concept:

```c
node *n = malloc(sizeof(node));

n->number = 42;
n->next = NULL;

free(n);
```

### `linked_list_two_nodes.c`

Creates two nodes and connects them manually.

Final structure:

```text
first -> second -> NULL
```

Practiced:

* linking nodes with the `next` pointer;
* accessing the second node through `first->next`;
* freeing multiple manually allocated nodes.

Example concept:

```c
first->next = second;
second->next = NULL;
```

### `linked_list_insert_front.c`

Creates a linked list by inserting new nodes at the front.

Insertion order:

```text
10, 20, 30
```

Final list:

```text
30 -> 20 -> 10 -> NULL
```

Practiced:

* maintaining a `list` pointer;
* inserting nodes at the beginning of a linked list;
* traversing a linked list;
* freeing all nodes safely.

Key pattern:

```c
n->next = list;
list = n;
```

### `linked_list_print_free.c`

Moves linked list printing and memory cleanup into helper functions.

Functions:

```c
void print_list(node *list);
void free_list(node *list);
```

Practiced:

* passing a linked list to a function;
* traversing a linked list inside a function;
* freeing a linked list safely.

Important memory cleanup pattern:

```c
node *next = ptr->next;
free(ptr);
ptr = next;
```

The next pointer must be saved before freeing the current node.

### `linked_list_search.c`

Adds search functionality to a linked list.

Function:

```c
int search_list(node *list, int target);
```

Returns:

```text
1 if the target is found
0 if the target is not found
```

Practiced:

* linear search in a linked list;
* checking each node's value;
* returning a result from a helper function.

Example traversal:

```c
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
    if (ptr->number == target)
    {
        return 1;
    }
}

return 0;
```

### `linked_list_insert_sorted.c`

Inserts values into a linked list while keeping the list sorted.

Input values:

```c
int values[] = {5, 1, 9, 3};
```

Final output:

```text
1
3
5
9
```

Practiced:

* sorted linked list insertion;
* using `previous` and `current` pointers;
* inserting at the beginning;
* inserting in the middle;
* inserting at the end.

Key traversal:

```c
while (current != NULL && current->number < n->number)
{
    previous = current;
    current = current->next;
}
```

Key insertion:

```c
if (previous == NULL)
{
    n->next = list;
    list = n;
}
else
{
    previous->next = n;
    n->next = current;
}
```

## Key Concepts

### Structs

A `struct` groups related data into one custom type.

Example:

```c
typedef struct
{
    char name[100];
    int age;
}
student;
```

### Linked list node

A linked list node usually stores data and a pointer to the next node.

```c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```

### Pointer to struct

When working with a pointer to a struct, fields are accessed with `->`.

```c
n->number = 42;
n->next = NULL;
```

This is a shorter form of:

```c
(*n).number = 42;
(*n).next = NULL;
```

### Linked list head

A linked list usually starts with a pointer to the first node.

```c
node *list = NULL;
```

If the list is empty, `list` is `NULL`.

### Inserting at the front

To insert a node at the beginning:

```c
n->next = list;
list = n;
```

The new node points to the old first node, and `list` becomes the new first node.

### Traversing a linked list

To walk through all nodes:

```c
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
    printf("%i\n", ptr->number);
}
```

The loop stops when `ptr` becomes `NULL`.

### Freeing a linked list

To free a linked list safely:

```c
node *ptr = list;

while (ptr != NULL)
{
    node *next = ptr->next;
    free(ptr);
    ptr = next;
}
```

The next node must be saved before freeing the current node.

### Sorted insertion

Sorted insertion needs two pointers:

```c
node *previous = NULL;
node *current = list;
```

* `previous` tracks the node before the insertion point.
* `current` tracks the node after the insertion point.

The new node is inserted between them.

## Common Mistakes Practiced

* Trying to print a whole struct as an integer.
* Forgetting to call `free` correctly.
* Confusing `node *n` with the actual node data.
* Forgetting that `n->number` accesses a field through a pointer.
* Risking memory leaks when `malloc` fails.
* Losing part of a linked list by updating pointers in the wrong order.
* Forgetting that `NULL` marks the end of a linked list.
* Calling a search function twice instead of storing or directly checking the result.

## How to Compile and Run

Compile with `make`:

```bash
make student_struct
./student_struct
```

Other examples:

```bash
make linked_list_insert_front
./linked_list_insert_front
```

```bash
make linked_list_insert_sorted
./linked_list_insert_sorted
```

For stricter checks, compile with warnings enabled:

```bash
clang -Wall -Wextra -Werror linked_list_insert_sorted.c -o linked_list_insert_sorted
```

## Current Status

This folder covers the first practical step into C data structures.

Completed topics:

* structs;
* arrays of structs;
* linked list nodes;
* manual node creation;
* linking nodes;
* inserting nodes at the front;
* printing linked lists;
* freeing linked lists;
* searching linked lists;
* sorted linked list insertion.

## Possible Next Steps

Useful next practice topics:

1. `stack_array.c` — stack implemented with an array.
2. `stack_linked_list.c` — stack implemented with a linked list.
3. `queue_array_simple.c` — simple queue.
4. `queue_linked_list.c` — queue with `front` and `rear`.
5. `binary_tree_manual.c` — manually created binary tree.
6. `binary_tree_search.c` — search in a binary search tree.
7. `hash_function_demo.c` — simple hash function.
8. `hash_table_simple.c` — basic hash table with linked lists.
