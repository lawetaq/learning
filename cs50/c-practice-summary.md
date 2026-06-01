# C Practice Summary

## Date

2026-05-29

## Programs written

- `hello.c` — prints hello world
- `compare.c` — compares two integers
- `password.c` — simple password check using `strcmp`

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

## 2026-05-30 — Loops, validation, and functions

### Programs written

#### `counter.c`

A simple program that prints numbers from 1 to 10.

Practiced:

* `for` loops;
* loop counter variable;
* `i++`;
* loop start and stop conditions.

#### `meow.c`

A program that asks the user how many times to print `Meow!`.

Practiced:

* reading integer input with `scanf("%i", &n)`;
* printing repeated output with a `for` loop;
* validating positive input with a `do while` loop.

#### `password_attempts.c`

An improved password-checking program with up to 3 attempts.

Practiced:

* `char` arrays for simple strings;
* `scanf("%99s", ...)`;
* string comparison with `strcmp`;
* fixed number of attempts using a `for` loop;
* using `break` to exit the loop early;
* using a flag variable such as `int success = 0`;
* checking login failure after the loop.

#### `meow_function.c`

A version of the meow program using a custom function.

Practiced:

* defining a custom function with `void meow(void)`;
* calling a custom function with `meow();`;
* understanding `void` as “returns nothing” and “takes no arguments”;
* moving repeated behavior out of `main`.

### New concepts practiced

* `for` loops
* `do while` loops
* repeated input validation
* `break`
* flag variables
* custom functions
* `void` functions
* function calls
* common C syntax mistakes and fixes

### Important notes

* A `for` loop is useful when the number of repetitions is known.
* A `do while` loop is useful when input must be requested at least once.
* `break` can stop a loop early after a successful condition.
* A flag variable can store whether something happened during a loop.
* Custom functions make `main` cleaner and reduce repeated code.
* `scanf("%i", &n)` needs `&n` because `scanf` writes input into the variable.
* `scanf("%99s", array)` is safer than `%s` because it limits input size.
* `%s` is used for strings, while `%c` reads raw characters.

### Current practice status

I can now write, compile, and test small standard C programs using:

* variables;
* `printf`;
* `scanf`;
* `if / else`;
* `for`;
* `do while`;
* `break`;
* flag variables;
* `char` arrays;
* `strcmp`;
* custom functions.

### Next practice goals

* nested loops;
* vertical and horizontal rows of `#`;
* simple square grid;
* function prototypes;
* CS50-style Mario exercises.

