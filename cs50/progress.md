# CS50 Progress

## 2026-05-25

### Current position

Video: CS50x 2026 full course  
Link: https://www.youtube.com/watch?v=gmuTjeQUbTM  
Current timestamp: 1:57:40  
Current topic: before C introduction

### Completed so far

- Course introduction
- Basic idea of computer science
- Problem solving
- Algorithms
- Abstraction
- Representation of information
- Binary basics
- ASCII / Unicode basics
- RGB / image representation basics
- Scratch basics
- Events, conditions, loops, variables, functions

### What I understood

- Computer science is mostly about problem solving, not just writing code.
- Algorithms are step-by-step instructions for solving a problem.
- Computers represent data using bits.
- Higher-level tools like Scratch help understand programming logic without syntax pain.

### What was hard / unclear

- Nothing yet

### Why this matters for DevOps

- DevOps requires understanding how programs work at a basic level.
- Scripts, automation, CI/CD pipelines, and infrastructure tools all rely on programming logic.
- Conditions, loops, variables, and functions will appear later in Bash, Python, YAML templates, and automation tools.

### Next

- Continue from C introduction
- Learn variables, types, conditions, loops, functions in C
- Write short notes after the C section

## 2026-05-29

### Current position

Video: CS50x 2026 full course  
Link: https://www.youtube.com/watch?v=gmuTjeQUbTM  
Current timestamp: 3:10:29  
Current topic: C basics

### Completed so far

- Continued learning C basics.
- Practiced small C programs locally without the CS50 library.
- Wrote and tested `hello.c`, `name.c`, `compare.c`, and `password.c`.

### What I understood

- C programs start from `main`.
- `scanf` can be used for basic input.
- Strings in standard C can be represented as `char` arrays.
- `strcmp` is needed for string comparison.

### What was hard / unclear

- Standard C string handling is less convenient than CS50's `string` and `get_string`.

### Why this matters for DevOps

- Basic programming logic helps with Bash, Python, automation scripts, and debugging.

### Next

- Learn loops.
- Improve the password program with limited attempts.

## 2026-05-30

### Current position

Video: CS50x 2026 full course
Current timestamp: 4:27:58
Current topic: C basics, loops, input validation, and custom functions

### Completed so far

* Continued the C section of CS50x.
* Practiced writing small programs in standard C without using the CS50 library.
* Wrote and tested several C programs:

  * `counter.c`
  * `meow.c`
  * `password_attempts.c`
  * `meow_function.c`
* Practiced compiling programs with `make`.
* Continued using VS Code and the terminal for C practice.

### Topics practiced

* `for` loops
* `do while` loops
* repeated input validation
* `scanf`
* integer variables
* character arrays as simple strings
* string comparison with `strcmp`
* `break`
* flag variables
* custom functions
* `void` return type
* `void` function parameters
* the difference between `=` and `==`
* the difference between `#include` and incorrect `#import` usage in standard C

### What I understood

* A `for` loop is useful when the number of repetitions is known in advance.
* A `do while` loop is useful when an action must happen at least once before checking the condition.
* Input validation can be done by repeatedly asking the user until the value is valid.
* `break` can be used to exit a loop early.
* A flag variable such as `int success = 0` can track whether something happened during a loop.
* Strings in standard C are represented with `char` arrays.
* `strcmp(...) == 0` means two strings are equal.
* `scanf("%i", &n)` uses `&n` because `scanf` needs the memory address of the variable to write user input into it.
* `printf("%i\n", n)` does not need `&` because it only reads the value.
* `scanf("%99s", password)` reads a word safely into a `char password[100]` array.
* `%99s` leaves space for the null terminator `'\0'`.
* `%s` reads a string, while `%c` reads raw characters.
* Custom functions help keep `main` cleaner by moving repeated behavior into separate reusable blocks.

### Programs written

#### `counter.c`

A simple program that prints numbers from 1 to 10 using a `for` loop.

Practiced:

* declaring a loop variable inside a `for` loop;
* using `i++`;
* understanding loop start and stop conditions.

#### `meow.c`

A program that asks the user how many times to print `Meow!`.

Practiced:

* reading an integer with `scanf`;
* printing repeated output with a `for` loop;
* validating input with a `do while` loop.

#### `password_attempts.c`

An improved password-checking program with up to 3 login attempts.

Practiced:

* `char` arrays;
* `scanf("%99s", ...)`;
* `strcmp`;
* fixed attempt count with a `for` loop;
* `break`;
* flag variable logic;
* checking failed login after the loop.

#### `meow_function.c`

A version of the meow program using a custom function.

Practiced:

* creating a function with `void meow(void)`;
* calling a custom function;
* understanding `void` as “returns nothing” and “takes no arguments”;
* placing a function above `main` so the compiler knows about it before it is called.

### Common mistakes fixed

* Used commas instead of semicolons inside a `for` loop header.
* Forgot to declare the loop variable `i`.
* Used `#import` instead of `#include`.
* Wrote `int success == 0;` instead of `int success = 0;`.
* Forgot semicolons after statements.
* Wrote `if (success = 0)` instead of `if (success == 0)`.
* Forgot to save the file in VS Code before compiling with `make`.

### Security note

The password programs are only learning exercises.

Important real-world password concepts briefly discussed:

* real services should not store passwords as plain text;
* passwords are usually hashed, not encrypted;
* hashing is one-way;
* salts help protect against identical password hashes;
* password transmission should be protected with HTTPS/TLS;
* real systems use password-hashing algorithms such as Argon2id, bcrypt, scrypt, or PBKDF2.

### Why this matters for DevOps

* Loops and conditions are core concepts for Bash, Python, automation scripts, CI/CD workflows, and infrastructure tooling.
* Input validation and control flow are useful for writing safer scripts.
* Understanding functions helps with structuring automation code.
* Basic C practice improves general programming logic and makes later scripting easier.

### Current status

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

I also understand the difference between CS50 conveniences and standard C equivalents:

CS50 library:

```text
get_int(...)
get_string(...)
string
```

Standard C used locally:

```text
scanf("%i", &n)
char array[100]
scanf("%99s", array)
strcmp(...)
```

### Next

* Practice nested loops.
* Write a program that prints a vertical column of `#`.
* Write a program that prints a horizontal row of `#`.
* Write a program that prints a simple square grid.
* Learn function prototypes so custom functions can be placed below `main`.
* Continue toward CS50-style Mario exercises.

## 2026-06-01 — 2026-06-02

### Current position

Continued practicing C after the early C section of CS50x.
Main focus: loops, functions, nested loops, input validation, and simple terminal-based shapes.

### Completed so far

* Practiced more standard C without using the CS50 library.
* Wrote and tested several small C programs:

  * `column.c`
  * `row.c`
  * `square.c`
  * `square_function.c`
  * `rectangle.c`
  * `rectangle_function.c`
  * `mario_stairs.c`
  * `better_mario_stairs.c`
* Practiced compiling and running programs with `make`.
* Continued using VS Code, terminal, and the GitHub learning repository.

### Topics practiced

* `for` loops
* `do while` loops
* nested loops
* integer input with `scanf("%i", &variable)`
* character input with `scanf(" %c", &character)`
* `if / else if / else`
* logical OR: `||`
* logical AND: `&&`
* helper functions
* function parameters
* local variables and scope
* simple input validation
* drawing shapes in the terminal

### Programs written

#### `column.c`

A program that asks for a height and prints a vertical column of `#`.

Practiced:

* validating positive integer input;
* using a `for` loop to print one line per iteration.

#### `row.c`

A program that asks for a width and prints one horizontal row of `#`.

Practiced:

* printing characters without `\n` inside the loop;
* printing one final newline after the row is complete.

#### `square.c`

A program that asks for a size and prints a square.

Practiced:

* nested loops;
* outer loop for rows;
* inner loop for columns.

#### `square_function.c`

A rewritten square program using a helper function:

```c
void print_row(int width)
```

Practiced:

* creating a custom function with a parameter;
* passing a value from `main` into another function;
* keeping `main` cleaner.

#### `rectangle.c`

A program that asks for height and width separately and prints a rectangle.

Practiced:

* using separate variables for rows and columns;
* nested loops with different limits.

#### `rectangle_function.c`

A rewritten rectangle program using a helper function to print each row.

Practiced:

* separating program responsibilities;
* using `main` for input and flow control;
* using a helper function for repeated row printing.

#### `mario_stairs.c`

A Mario-style staircase program where the user chooses left or right direction.

Practiced:

* reading a character with `scanf(" %c", &dir)`;
* using a space before `%c` to skip leftover whitespace;
* handling lowercase and uppercase input;
* drawing left and right staircases with nested loops.

#### `better_mario_stairs.c`

An improved staircase program using separate helper functions:

```c
void print_left_stairs(int height)
void print_right_stairs(int height)
```

Practiced:

* validating character input with a `do while` loop;
* using `&&` to reject invalid choices;
* using `||` to accept multiple valid choices;
* moving larger logic into helper functions.

### Important logic learned

For a left staircase, each row prints:

```text
hashes = row + 1
```

For a right staircase, each row prints spaces first, then hashes:

```text
spaces = height - row - 1
hashes = row + 1
```

This creates a right-aligned staircase with a consistent total width.

### Mistakes fixed

* Forgot `&` in `scanf("%i", &height)`.
* Wrote `int main` instead of `int main(void)`.
* Forgot semicolons after statements.
* Confused `=` with `==`.
* Used incorrect OR logic:

```c
dir == 'l' || 'L'
```

Correct version:

```c
dir == 'l' || dir == 'L'
```

* Incremented the wrong variable inside a nested loop.
* Tried to use a variable inside a function where it was not in scope.
* Misunderstood that function parameters are local to the function.
* Observed that `scanf("%i", &size)` can behave badly when the user enters letters instead of numbers.

### What I understood

* Nested loops are useful for drawing two-dimensional shapes.
* The outer loop usually controls rows.
* The inner loop usually controls columns.
* Functions do not automatically see variables from other functions.
* Values must be passed into functions as arguments.
* Helper functions make larger programs easier to read.
* `scanf(" %c", &dir)` is useful for character input because the space before `%c` skips leftover whitespace.
* Simple `scanf` input validation works for normal input, but invalid types like letters can require safer handling later.

### Why this matters for DevOps

* Loops and functions are core building blocks for Bash and Python automation.
* Input validation is useful for writing safer scripts.
* Understanding scope and parameters helps with reading and writing structured automation tools.
* Breaking programs into helper functions builds habits that will matter later in scripts, backend basics, and infrastructure tooling.

### Current status

I can now write small standard C programs using:

* variables;
* integer input;
* character input;
* `printf`;
* `scanf`;
* `if / else`;
* `for`;
* `do while`;
* nested loops;
* helper functions;
* function parameters;
* simple input validation;
* terminal-based shape drawing.

### Next

* Create a full CS50-style Mario pyramid.
* Add a height limit, for example accepting only values from `1` to `8`.
* Improve input safety by checking the return value of `scanf`.
* Learn function prototypes so helper functions can be placed below `main`.
* Continue with arrays and strings after loop/function practice feels stable.
