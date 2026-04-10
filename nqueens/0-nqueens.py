#!/usr/bin/python3
"""N Queens Problem Solver"""
import sys

def print_solution(solution):
    print(solution)

def is_safe(row, col, solution):
    for r, c in solution:
        if c == col or r - c == row - col or r + c == row + col:
            return False
    return True

def solve_nqueens(n, row=0, solution=[]):
    if row == n:
        print_solution(solution)
        return
    for col in range(n):
        if is_safe(row, col, solution):
            solve_nqueens(n, row + 1, solution + [[row, col]])

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    solve_nqueens(n)

if __name__ == "__main__":
    main()
