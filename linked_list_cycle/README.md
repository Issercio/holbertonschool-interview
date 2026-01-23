# Linked List Cycle

This project implements Floyd's cycle detection algorithm to check if a singly linked list contains a cycle.

## Problem Description

Write a function that checks if a singly linked list has a cycle in it.

A cycle occurs when a node's `next` pointer points back to a previous node in the list, creating a loop.

## Algorithm: Floyd's Cycle Detection (Tortoise and Hare)

The solution uses two pointers moving at different speeds:

1. **Slow pointer**: moves one step at a time
2. **Fast pointer**: moves two steps at a time

### How it works:
- If there's no cycle, the fast pointer will reach the end (NULL)
- If there's a cycle, the fast pointer will eventually catch up to the slow pointer inside the cycle

### Why it works:
- If there's a cycle, both pointers will eventually be inside the cycle
- Since the fast pointer moves 2x faster, it gains 1 position on the slow pointer each iteration
- Eventually, the fast pointer will "lap" the slow pointer and they will meet

### Time Complexity: O(n)
- In the worst case, we traverse the list once

### Space Complexity: O(1)
- Only two pointers are used, no additional data structures

## Files

- `lists.h` - Header file with structure definition and function prototypes
- `0-check_cycle.c` - Implementation of the check_cycle function

## Function

### check_cycle
```c
int check_cycle(listint_t *list);
```

Checks if a singly linked list has a cycle.

**Parameters:**
- `list`: pointer to the head of the list

**Return:**
- `0` if there is no cycle
- `1` if there is a cycle

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Usage Example

```c
listint_t *head = NULL;
add_nodeint(&head, 1);
add_nodeint(&head, 2);
add_nodeint(&head, 3);

if (check_cycle(head) == 0)
    printf("Linked list has no cycle\n");
else
    printf("Linked list has a cycle\n");
```

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4
- Betty style compliance
- No global variables
- Maximum 5 functions per file
- Only allowed functions: write, printf, putchar, puts, malloc, free
- No extra memory allocation (O(1) space complexity)

## Edge Cases Handled

- Empty list (NULL)
- Single node list
- List with only two nodes
- Cycle at any position in the list
