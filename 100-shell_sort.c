#include "sort.h"

/**
 * swap - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, num1, num2;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (num1 = gap; num1 < size; num1++)
		{
			num2 = num1;
			while (num2 >= gap && array[num2 - gap] > array[num2])
			{
				swap(array + num2 - gap, array + num2);
				num2 -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}

