#include <stdio.h>
#include "search_algos.h"

int main(void)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value = 7;

    int idx = advanced_binary(array, size, value);
    if (idx != -1)
        printf("Found %d at index: %d\n", value, idx);
    else
        printf("%d not found\n", value);

    return 0;
}
