# Linked List Palindrome

This project implements a function to check if a singly linked list is a palindrome.

## Problem Description

Write a function that checks if a singly linked list is a palindrome.

A palindrome is a sequence that reads the same forwards and backwards. For example:
- `[1, 2, 3, 2, 1]` is a palindrome
- `[1, 2, 3, 4, 5]` is not a palindrome
- An empty list is considered a palindrome

## Algorithm

The solution uses the following approach:

1. **Find the middle** of the linked list using the slow/fast pointer technique:
   - `slow` pointer moves one step at a time
   - `fast` pointer moves two steps at a time
   - When `fast` reaches the end, `slow` is at the middle

2. **Handle odd-length lists**: If the list has odd length, skip the middle element

3. **Reverse the second half** of the list

4. **Compare** the first half with the reversed second half:
   - If all corresponding elements match, it's a palindrome
   - If any element doesn't match, it's not a palindrome

### Time Complexity: O(n)
### Space Complexity: O(1)

## Files

- `lists.h` - Header file with structure definition and function prototypes
- `0-is_palindrome.c` - Implementation of the is_palindrome function

## Functions

### is_palindrome
```c
int is_palindrome(listint_t **head);
```
Checks if a singly linked list is a palindrome.

**Parameters:**
- `head`: double pointer to the head of the list

**Return:** 
- `1` if the list is a palindrome
- `0` if the list is not a palindrome

### reverse_list (helper)
```c
listint_t *reverse_list(listint_t *head);
```
Reverses a singly linked list.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Usage Example

```c
listint_t *head = NULL;
add_nodeint_end(&head, 1);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 972);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 1);

if (is_palindrome(&head) == 1)
    printf("Linked list is a palindrome\n");
else
    printf("Linked list is not a palindrome\n");
```

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4
- Betty style compliance
- No global variables
- Maximum 5 functions per file
