# 04 — Algorithms Basics

C practice programs focused on basic algorithm concepts from CS50, including binary search, sorting algorithms, and recursion.

## Programs

* `binary_search.c` — searches for a number in a sorted integer array using binary search
* `bubble_sort.c` — sorts an integer array using bubble sort
* `selection_sort.c` — sorts an integer array using selection sort
* `recursion_countdown.c` — demonstrates basic recursion with a countdown function

## Concepts practiced

* sorted arrays
* binary search
* left and right search boundaries
* middle index calculation
* linear shrinking of a search range
* bubble sort
* selection sort
* nested loops
* swapping values with a temporary variable
* helper functions for printing arrays
* recursion
* base case
* recursive case
* basic algorithm complexity ideas

## Build and run

Example:

```bash
make binary_search
./binary_search
```

Another example:

```bash
make selection_sort
./selection_sort
```

## Notes

Binary search only works correctly when the input array is sorted.

Bubble sort and selection sort are simple sorting algorithms that are useful for learning comparisons, loops, and swaps, but they are not efficient for large inputs.

Recursion requires a base case. Without a base case, a recursive function may call itself forever until the program crashes.

## Complexity notes

```text
Binary search      — O(log n)
Bubble sort        — O(n²)
Selection sort     — O(n²)
Merge sort         — O(n log n)
```

Important takeaways:

* `O(log n)` is very fast because the search space is divided roughly in half each step.
* `O(n²)` algorithms are simple but become slow on large inputs.
* `O(n log n)` sorting algorithms are generally much better than `O(n²)` algorithms for large datasets.
