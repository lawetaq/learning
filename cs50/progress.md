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
  * `mario_pyramid.c`
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

#### `mario_pyramid.c`

A CS50-style Mario pyramid program written in standard C.

The program asks the user for a height and prints a double pyramid:

```text
Enter height: 5
    #  #
   ##  ##
  ###  ###
 ####  ####
#####  #####
```

The program validates height and accepts only values from `1` to `8`.

Practiced:

* nested loops;
* input validation with `do while`;
* using `||` to reject values outside an allowed range;
* printing spaces before hashes;
* printing a fixed gap between pyramid halves;
* building each line step by step from left to right.

Important formulas:

```text
spaces = height - row - 1
hashes = row + 1
gap = 2 spaces
```

This program completed the current loops, functions, and simple shapes practice block.

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

* Improve input safety by checking the return value of `scanf`.
* Learn function prototypes so helper functions can be placed below `main`.
* Continue with arrays and strings after loop/function practice feels stable.

## 2026-06-06

### Current position

Video: CS50x 2026 full course
Watched from: 04:27:58
Watched to: 06:53:32
Topic: Arrays

### Completed so far

* Continued CS50x and watched the Arrays lecture section.
* Practiced the same concepts in standard C without using the CS50 library.
* Created a new practice block for arrays, strings, search, command-line arguments, and Caesar cipher.
* Wrote and tested several C programs:

  * `scores.c`
  * `scores_dynamic.c`
  * `string_length.c`
  * `string_length_fgets.c`
  * `uppercase.c`
  * `greet_args.c`
  * `search_score.c`
  * `search_name.c`
  * `caesar_simple.c`

### Topics practiced

* integer arrays;
* variable-length arrays;
* array indexing;
* loops over arrays;
* calculating sum and average;
* floating-point division;
* strings as `char` arrays;
* null terminator `'\0'`;
* reading strings with `scanf("%99s", text)`;
* reading full lines with `fgets`;
* difference between `scanf` and `fgets`;
* manual string length calculation;
* uppercase conversion using character arithmetic;
* command-line arguments with `argc` and `argv`;
* linear search;
* arrays of strings;
* string comparison with `strcmp`;
* simple Caesar cipher;
* modulo operator `%`;
* handling lowercase and uppercase letters separately.

### Programs written

#### `scores.c`

A program that stores three integer scores in an array and calculates their average.

Practiced:

* fixed-size integer arrays;
* array indexes starting at `0`;
* accessing elements with `scores[i]`;
* using `&scores[i]` with `scanf`;
* summing array elements;
* avoiding integer division with `3.0`;
* formatted floating-point output with `%.2f`.

#### `scores_dynamic.c`

A program where the user chooses how many scores to enter.

Practiced:

* asking the user for array size;
* validating that `n >= 1`;
* creating a variable-length array with `int scores[n]`;
* understanding that valid indexes are `0` to `n - 1`;
* using `(float) n` to force floating-point division.

#### `string_length.c`

A program that calculates the length of a word without using `strlen`.

Practiced:

* strings as `char` arrays;
* null terminator `'\0'`;
* manually walking through a string;
* understanding that `scanf("%s")` reads only one word and stops at spaces.

#### `string_length_fgets.c`

An improved string length program that reads a full line with spaces using `fgets`.

Practiced:

* reading full lines;
* handling the newline character `'\n'`;
* counting characters until `'\0'` or `'\n'`;
* understanding the difference between `scanf("%s")` and `fgets`.

#### `uppercase.c`

A program that reads a full line and prints it in uppercase.

Practiced:

* iterating through a `char` array;
* checking whether a character is between `'a'` and `'z'`;
* converting lowercase letters to uppercase manually;
* preserving spaces, punctuation, and already-uppercase letters.

#### `greet_args.c`

A program that uses command-line arguments.

Practiced:

* `int main(int argc, char *argv[])`;
* understanding `argc`;
* understanding `argv`;
* checking the correct number of arguments;
* using `argv[1]` as the first user-provided argument.

#### `search_score.c`

A program that searches for a number in an integer array.

Practiced:

* linear search;
* comparing each array element with a target;
* using a `found` flag;
* using `break` after finding the target;
* printing `Not found` only after checking the whole array.

#### `search_name.c`

A program that searches for a name in an array of strings.

Practiced:

* arrays of strings;
* basic understanding of `char *names[]`;
* reading a target name into `char target[100]`;
* comparing strings with `strcmp(names[i], target) == 0`.

#### `caesar_simple.c`

A simple Caesar cipher program.

Practiced:

* iterating through a string;
* checking lowercase and uppercase ranges;
* shifting letters using character arithmetic;
* using `% 26` to wrap around the alphabet;
* preserving spaces, punctuation, and symbols.

This was the strongest final exercise of this block because it combined arrays, strings, loops, character arithmetic, conditions, and formatted output.

### Important concepts learned

* Arrays store multiple values of the same type.
* Array indexes start at `0`.
* If an array has size `n`, the last valid index is `n - 1`.
* `scores[i]` accesses one element, while `scores` refers to the array.
* In C, strings are arrays of characters ending with `'\0'`.
* `scanf("%99s", text)` reads one word and stops at spaces.
* `fgets(text, sizeof(text), stdin)` reads a full line and may store `'\n'`.
* Strings cannot be compared with `==`; `strcmp(...) == 0` is needed.
* `argc` stores the number of command-line arguments.
* `argv` stores the argument strings.
* Linear search checks elements one by one until a match is found or the array ends.
* Caesar cipher logic uses character arithmetic and modulo.

### Common mistakes fixed

* Confused the whole array with one array element.
* Used `scores` where `scores[i]` was needed.
* Tried to use `scores[n]` as if it were the last element.
* Forgot that the last valid index is `n - 1`.
* Used `&target` incorrectly with `char target[100]`.
* Tried to compare strings without `strcmp`.
* Declared an array of strings incorrectly.
* Put `Not found` inside the search loop too early.
* Used `=` instead of `==`.
* Forgot that `scanf("%s")` reads only one word.
* Saw floating-point output like `59.333332` and learned to format it with `%.2f`.

### Why this matters for DevOps

* Arrays and loops are useful for processing lists of values, logs, files, arguments, and script input.
* Command-line arguments are important because many DevOps tools are CLI-based.
* Search logic helps with troubleshooting, parsing output, and understanding how programs process data.
* String handling is important for Bash, Python, configs, logs, environment variables, and automation.
* Caesar cipher practice builds confidence with character processing and transformations.

### Current status

I can now write small standard C programs using:

* fixed-size arrays;
* variable-length arrays;
* loops over arrays;
* `char` arrays;
* `fgets`;
* `scanf`;
* manual string length calculation;
* string search with `strcmp`;
* arrays of strings;
* command-line arguments;
* linear search;
* simple Caesar cipher logic.

### Next

* Practice debugging with compiler flags:

  * `-Wall`
  * `-Wextra`
  * `-Werror`
* Learn to read compiler warnings and errors more confidently.
* Improve input safety by checking the return value of `scanf`.
* Refactor some programs into helper functions.
* Continue with the next CS50 topic after debugging practice.

## 2026-06-09

### Current position

Topic: CS50 Algorithms basics
Practice approach: learned the core ideas through small standard C programs before watching the full lecture section.

### Completed so far

* Started practicing the CS50 Algorithms topic.
* Focused on understanding the main algorithm ideas through code.
* Created a new practice block:

  * `cs50/practice/04-algorithms/`
* Wrote and tested several C programs:

  * `binary_search.c`
  * `bubble_sort.c`
  * `selection_sort.c`
  * `recursion_countdown.c`

### Topics practiced

* binary search;
* sorted arrays;
* left and right search boundaries;
* middle index calculation;
* bubble sort;
* selection sort;
* swapping array elements with a temporary variable;
* nested loops;
* recursion;
* base case;
* recursive case;
* basic algorithm complexity ideas:

  * `O(log n)`
  * `O(n²)`
  * `O(n log n)`

### Programs written

#### `binary_search.c`

A program that searches for a target number in a sorted integer array using binary search.

Practiced:

* binary search on sorted data;
* tracking the search area with `left` and `right`;
* calculating the middle index;
* moving the right boundary when the middle value is too large;
* moving the left boundary when the middle value is too small;
* using a `found` flag;
* printing `Not found` only after the loop finishes.

Important mistakes fixed:

* incorrect array length;
* moving the wrong boundary;
* accidentally writing `if (found == 0);`, which makes the condition useless.

#### `bubble_sort.c`

A program that sorts an integer array using bubble sort.

Practiced:

* nested loops;
* comparing neighboring elements;
* swapping two values with a temporary variable;
* understanding that after each outer loop pass, the largest unsorted value moves to the right;
* using a helper function to print an array.

Important mistakes fixed:

* typos in `length`;
* using commas instead of semicolons in a `for` loop;
* missing quotation marks in `printf("\n")`;
* passing function arguments with `;` instead of `,`.

#### `selection_sort.c`

A program that sorts an integer array using selection sort.

Practiced:

* finding the minimum element in the unsorted part of an array;
* storing the index of the current minimum;
* checking the rest of the array;
* updating `min_index` when a smaller value is found;
* doing one swap after the inner loop finishes.

Important mistakes fixed:

* forgetting to declare `min_index`;
* placing the swap inside the inner loop too early;
* using `min_index = 1` instead of `min_index = i`.

#### `recursion_countdown.c`

A simple recursive countdown program.

Practiced:

* recursion;
* function prototypes;
* base case;
* recursive case;
* using `return` to stop recursion;
* understanding repeated function calls.

### Algorithm complexity notes

Basic takeaways:

```text
Binary search      — O(log n)
Bubble sort        — O(n²)
Selection sort     — O(n²)
Merge sort         — O(n log n)
```

Important understanding:

* `O(n²)` algorithms are simple but become slow on large inputs.
* `O(log n)` is very fast, but binary search requires sorted data.
* `O(n log n)` is generally much better than `O(n²)` for large sorting tasks.
* Merge sort is faster than bubble sort and selection sort on large arrays, but it is conceptually more complex.
* Bubble sort and selection sort are still useful for learning because they make comparisons, loops, and swaps very clear.

### Current status

I can now write small C programs that demonstrate:

* binary search;
* bubble sort;
* selection sort;
* recursive countdown;
* array printing with helper functions;
* swapping values;
* nested loops;
* search boundaries;
* base case and recursive case.

### Why this matters for DevOps

* Algorithms improve general problem-solving skills.
* Search logic is useful for working with logs, lists, files, and command output.
* Sorting and comparison logic helps with data processing.
* Recursion helps understand how problems can be broken into smaller versions of the same problem.
* Complexity thinking helps avoid inefficient scripts and tools later.

### Next

* Write `merge_sorted_arrays_demo.c`.
* Later write `merge_sort_demo.c`.
* Practice compiler warning flags:

  * `-Wall`
  * `-Wextra`
  * `-Werror`
* Practice tracing how `left`, `right`, `middle`, `i`, `j`, and `min_index` change during algorithm execution.
