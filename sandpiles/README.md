# Sandpiles

This project implements an algorithm to compute the sum of two sandpiles and stabilize the result through toppling.

## Problem Description

A sandpile is a 3x3 grid of integers representing grains of sand. A sandpile is considered **stable** when none of its cells contains more than 3 grains.

When two sandpiles are added together, the result may be unstable. An unstable sandpile must undergo **toppling** rounds until it becomes stable:

### Toppling Rules:
- If a cell contains more than 3 grains, it "topples"
- The cell loses 4 grains
- Each of its 4 neighbors (up, down, left, right) gains 1 grain
- If a neighbor is outside the grid, those grains are lost
- All unstable cells topple simultaneously in each round
- The grid is printed before each toppling round

## Algorithm

1. Add grid2 to grid1 element-wise
2. Check if grid1 is stable
3. If unstable:
   - Print current state of grid1
   - Perform one toppling round (all cells with >3 grains topple simultaneously)
   - Repeat until stable

## Files

- `sandpiles.h` - Header file with function prototype
- `0-sandpiles.c` - Implementation of sandpiles_sum function

## Usage

```c
#include "sandpiles.h"

int grid1[3][3] = {
    {3, 3, 3},
    {3, 3, 3},
    {3, 3, 3}
};
int grid2[3][3] = {
    {1, 3, 1},
    {3, 3, 3},
    {1, 3, 1}
};

sandpiles_sum(grid1, grid2);
// grid1 now contains the stable result
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4
- Betty style compliance
- No dynamic memory allocation
- Maximum 5 functions per file
