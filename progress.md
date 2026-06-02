# Progress Log

## 2026-05-28

### Done
- Created GitHub account
- Created devops-learning repository

### Practiced
- Basic GitHub repository setup

### Problems
- None yet

### Next
- Install and configure Git locally
- Learn basic Git commands
- Add first CS50 notes

## 2026-05-28

### Done
- Set up GitHub account
- Created learning repository
- Generated SSH key
- Connected local PC to GitHub via SSH
- Cloned repository to local machine

### Next
- Practice basic Git workflow: edit, add, commit, push

## 2026-06-02

### Done

- Continued CS50 C practice.
- Practiced loops, nested loops, helper functions, and simple shape drawing.
- Wrote and tested several C programs:
  - `column.c`
  - `row.c`
  - `square.c`
  - `square_function.c`
  - `rectangle.c`
  - `rectangle_function.c`
  - `mario_stairs.c`
  - `better_mario_stairs.c`

### Practiced

- `for` loops
- `do while` loops
- nested loops
- function parameters
- simple input validation
- character input with `scanf(" %c", &dir)`
- logical operators `||` and `&&`

### Problems

- Confused incorrect OR logic like `dir == 'l' || 'L'`.
- Observed that `scanf("%i", &value)` can behave badly when letters are entered instead of numbers.

### Solved / Understood

- Correct OR logic requires repeating the full comparison: `dir == 'l' || dir == 'L'`.
- A right staircase uses both spaces and hashes:
  - `spaces = height - row - 1`
  - `hashes = row + 1`
- Functions do not automatically see variables from `main`; values must be passed as parameters.

### Next

- Practice a full CS50-style Mario pyramid.
- Add height validation from `1` to `8`.
- Learn function prototypes.
- Continue toward arrays and strings.
