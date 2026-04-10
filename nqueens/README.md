# N Queens

This project contains a Python program that solves the N Queens puzzle using a backtracking algorithm.

## Usage

    ./0-nqueens.py N

- `N` must be an integer greater than or equal to 4.
- The program prints every possible solution to the N Queens problem for a given N.
- Each solution is printed as a list of lists, where each inner list represents the row and column position of a queen.

## Example

```
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

## Requirements
- Python 3.4+
- Only the `sys` module is used
- PEP 8 style
- Executable file with shebang
