# CS50 C Practice — Memory

This folder contains small C programs created while studying the **Memory** section of CS50.

The goal of this practice block was to understand how memory works in C at a basic level: addresses, pointers, dereferencing, strings as character arrays/pointers, and dynamic memory allocation.

## Context

These programs were written in standard C without using the CS50 library.

Main topics practiced:

* memory addresses;
* the address-of operator `&`;
* pointers;
* dereferencing with `*`;
* passing addresses to functions;
* strings as pointers to characters;
* pointer arithmetic;
* copying addresses vs copying actual data;
* dynamic memory allocation with `malloc`;
* releasing memory with `free`.

## Files

### `address_demo.c`

Demonstrates the difference between a variable's value and its memory address.

Practiced:

* printing normal values;
* printing addresses with `%p`;
* using `(void *)` when printing addresses;
* understanding that each variable has a location in memory.

Example concepts:

```c
int n = 50;
printf("%i\n", n);
printf("%p\n", (void *) &n);
```

### `pointer_demo.c`

Introduces pointers.

Practiced:

* creating a pointer with `int *p`;
* storing the address of a variable in a pointer;
* printing the pointer value;
* printing the address of the pointer itself;
* dereferencing a pointer with `*p`;
* changing a variable through a pointer.

Example concepts:

```c
int n = 50;
int *p = &n;

printf("%i\n", *p);

*p = 100;
```

### `pointer_function.c`

Shows why pointers are useful when passing variables to functions.

Practiced:

* passing a variable address to a function;
* receiving that address as a pointer parameter;
* changing the original variable from another function.

Example concepts:

```c
void change(int *p)
{
    *p = 100;
}
```

This demonstrates that C functions normally receive copies of values, but pointers allow a function to modify the original variable.

### `string_pointer.c`

Demonstrates that strings in C are closely related to memory addresses.

Practiced:

* using `char *s`;
* printing a string;
* printing the address of the first character;
* accessing characters with `s[i]`;
* accessing the same characters with pointer arithmetic: `*(s + i)`.

Example concepts:

```c
char *s = "HI!";

printf("%c\n", s[0]);
printf("%c\n", *(s + 0));
```

This helped show that `s[i]` and `*(s + i)` can refer to the same character.

### `copy_string_bad.c`

Demonstrates a common mistake when copying strings.

Practiced:

* assigning one string pointer to another;
* seeing that `char *t = s` copies the address, not the string data;
* understanding that two pointers can refer to the same memory.

Example concept:

```c
char s[] = "hello";
char *t = s;

t[0] = 'H';
```

After changing `t[0]`, both `s` and `t` show the modified string because they point to the same memory.

### `copy_string_good.c`

Demonstrates how to create an independent copy of a string.

Practiced:

* using `malloc`;
* checking whether `malloc` returned `NULL`;
* copying characters manually;
* copying the null terminator `'\0'`;
* using `free` to release allocated memory.

Example concepts:

```c
char *t = malloc(strlen(s) + 1);

if (t == NULL)
{
    return 1;
}

for (int i = 0; i <= strlen(s); i++)
{
    t[i] = s[i];
}

free(t);
```

This shows that an independent string copy requires separate memory and actual data copying.

## Key Takeaways

### Values and addresses

A variable has both a value and an address.

```c
int n = 50;
```

* `n` is the value.
* `&n` is the address of `n`.

### Pointers

A pointer stores an address.

```c
int *p = &n;
```

* `p` stores the address of `n`.
* `*p` accesses the value stored at that address.

### Passing variables to functions

C functions receive copies of values by default.

To let a function change an original variable, pass its address:

```c
change(&n);
```

and receive it as a pointer:

```c
void change(int *p)
```

### Strings and pointers

A string is stored as characters in memory ending with `'\0'`.

```c
char *s = "HI!";
```

The pointer `s` stores the address of the first character.

### Copying pointers is not copying data

This copies only an address:

```c
char *t = s;
```

To create an independent copy, allocate new memory and copy the characters.

### malloc and free

Memory allocated with `malloc` should be released with `free`.

```c
char *t = malloc(size);

free(t);
```

Basic rule:

```text
malloc -> free
```

## Common Mistakes Practiced

* Confusing a value with an address.
* Confusing a pointer's value with the pointer's own address.
* Forgetting that `*p` means "value at the address stored in `p`".
* Thinking that `char *t = s` copies a string.
* Forgetting to allocate space for the null terminator `'\0'`.
* Forgetting that memory allocated with `malloc` should be freed.

## How to Compile and Run

Compile a file with `make`:

```bash
make address_demo
./address_demo
```

Other examples:

```bash
make pointer_demo
./pointer_demo
```

```bash
make copy_string_good
./copy_string_good
```

## Current Status

This folder covers the first practical step into C memory concepts.

The next useful practice topics are:

* more pointer exercises;
* swapping two variables through pointers;
* dynamic arrays with `malloc`;
* memory leaks;
* invalid memory access;
* using tools such as `valgrind`.
