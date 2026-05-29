# C Practice Summary

## Date

2026-05-29

## Programs written

### compare

A simple program that asks for two integers and compares them.

Practiced:

- `int` variables
- `scanf("%i", &x)`
- `if / else if / else`
- `<`, `>`, `==`
- `return 0`

### password

A simple password check program.

Practiced:

- `char password[100]`
- `scanf("%99s", password)`
- `#include <string.h>`
- `strcmp(password, attempt) == 0`
- basic string comparison

## Important notes

- Standard C does not have CS50's `string` type.
- `char` arrays can be used for simple strings.
- `strcmp(...) == 0` means strings are equal.
- `scanf("%99s", ...)` reads one word only.
- This password program is only for learning, not real security.

## Next topic

Loops:

- `for`
- `while`
- repeated attempts
- simple repeated input
