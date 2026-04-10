
#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger sponge of a given level
 * @level: The level of the Menger sponge
 */
void menger(int level)
{
	int size, row, col, x, y, draw;

	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			x = row;
			y = col;
			draw = 1;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					draw = 0;
					break;
				}
				x /= 3;
				y /= 3;
			}
			putchar(draw ? '#' : ' ');
		}
		putchar('\n');
	}
}
