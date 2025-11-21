# Heap Insert

This project implements a Max Binary Heap with insertion functionality.

## Files

- `binary_trees.h`: Header file containing data structures and function prototypes
- `0-binary_tree_node.c`: Creates a binary tree node
- `1-heap_insert.c`: Inserts a value into a Max Binary Heap respecting heap ordering

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
```

## Usage

The `heap_insert()` function inserts a value into the heap while maintaining max heap property (parent >= children). It returns a pointer to the inserted node.
