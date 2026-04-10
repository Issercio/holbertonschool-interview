#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers like 2048 game
 * @line: Pointer to array of integers
 * @size: Number of elements in @line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, last;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /* Slide non-zero values to the left */
        last = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != last)
                {
                    line[last] = line[i];
                    line[i] = 0;
                }
                last++;
            }
        }
        /* Merge values */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }
        /* Slide again after merge */
        last = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != last)
                {
                    line[last] = line[i];
                    line[i] = 0;
                }
                last++;
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        last = size - 1;
        for (i = size; i-- > 0; )
        {
            if (line[i] != 0)
            {
                if (i != last)
                {
                    line[last] = line[i];
                    line[i] = 0;
                }
                last--;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }
        last = size - 1;
        for (i = size; i-- > 0; )
        {
            if (line[i] != 0)
            {
                if (i != last)
                {
                    line[last] = line[i];
                    line[i] = 0;
                }
                last--;
            }
        }
    }
    return (1);
}
