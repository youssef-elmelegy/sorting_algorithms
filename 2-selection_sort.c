#include "sort.h"

/**
 *selection_sort - sorts an array of integers in ascending order
 *@array: the array to be sort
 *@size: size of the array
 */

void selection_sort(int *array, size_t size)
{
size_t i, smallest, key;
int temp;

if (!array || !size || !array[1])
return;

i = 0;
while (i < size - 1)         /*{19, 48, 99, 71, 13, 52, 96, 73, 86, 7}*/
{
for (key = i + 1, smallest = i; key < size; key++)
{
 if (array[key] < array[smallest])
{
smallest = key;
}
}

if (array[smallest] < array[i])
{
temp = array[smallest];
array[smallest] = array[i];
array[i] = temp;
print_array(array, size);
}
i++;
}
}
