# Heap Insert - Binary Trees

This project implements functions related to binary trees and heaps.

## Files

- `binary_trees.h` - Header file with data structures and function prototypes
- `0-binary_tree_node.c` - Function to create a new binary tree node

## Data Structures

### Binary Tree Node
```c
struct binary_tree_s
{
    int n;                          /* Integer stored in the node */
    struct binary_tree_s *parent;   /* Pointer to the parent node */
    struct binary_tree_s *left;     /* Pointer to the left child node */
    struct binary_tree_s *right;    /* Pointer to the right child node */
};
```

### Type Definitions
- `binary_tree_t` - Generic binary tree node
- `heap_t` - Max binary heap (same structure as binary_tree_t)

## Functions

### binary_tree_node
Creates a new binary tree node with the given parent and value.

**Prototype:** `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`

**Parameters:**
- `parent`: pointer to the parent node of the node to create
- `value`: the value to put in the new node

**Return:** pointer to the new node, or NULL on failure
