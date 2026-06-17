# CS50 Memory Practice

Small C programs written to practice pointers, memory addresses, dynamic allocation, and common memory-related mistakes.

## Topics Covered

- Addresses (`&`, `%p`, `(void *)`)
- Basic pointers (`int *p`)
- Dereferencing (`*p`)
- Modifying variables through pointers
- Passing pointers to functions
- `swap_bad` vs `swap_good`
- Strings as pointers and arrays
- Pointer arithmetic
- String copying
- `malloc` and `free`
- Dynamic integer arrays
- Out-of-bounds access
- NULL pointers

## Files

- `01_addresses.c`
- `02_pointer_basics.c`
- `03_dereference.c`
- `04_change_through_pointer.c`
- `05_pointer_function.c`
- `06_swap_bad.c`
- `07_swap_good.c`
- `08_string_pointer.c`
- `09_string_array.c`
- `10_pointer_arithmetic.c`
- `11_copy_string_bad.c`
- `12_copy_string_malloc.c`
- `13_dynamic_int_array.c`
- `14_out_of_bounds.c`
- `15_null_pointer.c`

## Key Lessons

- A pointer stores an address.
- `*p` accesses the value stored at that address.
- Functions receive copies of variables unless pointers are used.
- `char *t = s` copies an address, not a string.
- `malloc` allocates memory dynamically and must be paired with `free`.
- Accessing memory outside array bounds causes undefined behavior.
- Always check pointers against `NULL` before dereferencing them.
