# Minimum Operations

This project implements an algorithm to calculate the minimum number of operations needed to achieve exactly n 'H' characters in a text file, starting with a single 'H', using only two operations: Copy All and Paste.

## Problem Description

Given a text file with a single character 'H', and a text editor that can only execute two operations:
- **Copy All**: Copies all characters currently in the file to the clipboard
- **Paste**: Pastes the contents of the clipboard into the file

Write a method that calculates the fewest number of operations needed to result in exactly n 'H' characters.

## Algorithm

The solution is based on prime factorization. To reach n characters from 1, the minimum number of operations equals the sum of all prime factors of n.

### Why this works:
- To go from k characters to k×p characters, we need exactly p operations (1 Copy All + (p-1) Pastes)
- The optimal strategy is to factorize n and perform operations for each factor
- Sum of prime factors gives the minimum total operations

### Examples:
- n = 9 = 3 × 3: operations = 3 + 3 = 6
  - H → Copy All → Paste → Paste → HHH (3 ops) → Copy All → Paste → Paste → HHHHHHHHH (3 ops)
- n = 12 = 2 × 2 × 3: operations = 2 + 2 + 3 = 7
- n = 4 = 2 × 2: operations = 2 + 2 = 4

## Files

- `0-minoperations.py` - Implementation of the minOperations function

## Usage

```python
minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
# Output: Min number of operations to reach 4 characters: 4

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
# Output: Min number of operations to reach 12 characters: 7
```

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style (version 1.7.x)
