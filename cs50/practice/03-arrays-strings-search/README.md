# 03 — Arrays, Strings, Search, and Caesar Cipher

C practice programs focused on arrays, strings, command-line arguments, linear search, and simple character transformations.

## Programs

* `scores.c` — stores three scores in an array and calculates the average
* `scores_dynamic.c` — lets the user choose how many scores to enter
* `string_length.c` — manually calculates the length of one word
* `string_length_fgets.c` — calculates the length of a full line read with `fgets`
* `uppercase.c` — converts lowercase letters to uppercase manually
* `greet_args.c` — uses command-line arguments with `argc` and `argv`
* `search_score.c` — searches for a number in an integer array
* `search_name.c` — searches for a name in an array of strings
* `caesar_simple.c` — implements a simple Caesar cipher

## Concepts practiced

* fixed-size arrays
* variable-length arrays
* array indexing
* loops over arrays
* strings as `char` arrays
* null terminator `'\0'`
* `scanf`
* `fgets`
* command-line arguments
* `argc` and `argv`
* linear search
* string comparison with `strcmp`
* arrays of strings
* character arithmetic
* modulo operator `%`
* Caesar cipher logic

## Build and run

Example:

```bash
make caesar_simple
./caesar_simple
```

Another example:

```bash
make greet_args
./greet_args Nikita
```

## Notes

These programs use standard C instead of CS50 helper functions.

This block connects CS50 Arrays concepts with local C practice, including manual string handling and basic search logic.
