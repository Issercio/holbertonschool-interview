# Find the Loop

## Description

This project contains a function to detect a loop in a singly linked list and return the starting node of the loop if one exists.

## Files

- `lists.h` - header file containing the `listint_t` structure and function prototypes.
- `0-find_loop.c` - implementation of `find_listint_loop`.

## Requirements

- C compiler: `gcc 4.8.4`
- Compiler flags: `-Wall -Werror -Wextra -pedantic`
- No global variables.
- No standard library functions used.
- Header files are include guarded.

## Compilation

To compile the implementation with a test file, use:

```sh
gcc -Wall -Werror -Wextra -pedantic 0-find_loop.c lib.c -o main
```

## Function

- `listint_t *find_listint_loop(listint_t *head);`

Returns the address of the node where the loop begins, or `NULL` if the list is linear.
