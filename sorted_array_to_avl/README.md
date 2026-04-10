# Sorted Array to AVL Tree

This project contains a C function to build an AVL tree from a sorted array.

## Usage

- The main function to use is `sorted_array_to_avl` defined in `0-sorted_array_to_avl.c`.
- The header file `binary_trees.h` contains the required data structures and function prototypes.

## Compilation Example

```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Example

Given the array:
```
int array[] = {1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98};
size_t n = sizeof(array) / sizeof(array[0]);
avl_t *tree = sorted_array_to_avl(array, n);
```

The resulting AVL tree will be balanced and can be visualized using a helper print function.

## Requirements
- GCC 4.8.4
- Betty style
- No global variables
- No more than 5 functions per file
- All prototypes in `binary_trees.h`
- All header files are include guarded
