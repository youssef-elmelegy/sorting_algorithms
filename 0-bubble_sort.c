#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending order
 *@array: the array to be sort
 *@size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
int temp = 0;
size_t i, j;

if (!array || !size || size < 2)
return;
i = 0;
while (i < size - 1)
{
for (j = 0; j < size - i; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
i++;
}
}
