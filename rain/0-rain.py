#!/usr/bin/python3

"""
0-rain
Calculates how much water will be retained after it rains
given a list of wall heights.
"""


def rain(walls):
    """
    Calculate the total amount of rainwater retained.
    Args:
        walls (list): List of non-negative integers representing wall heights.
    Returns:
        int: Total units of water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left = 0
    right = n - 1
    left_max = 0
    right_max = 0
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]
            right -= 1
    return water
