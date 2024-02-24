#include "sort.h"

/**
 * swap_quick - swap two elements in an array
 * @a: first element
 * @b: second element
 */
void swap_quick(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * key_founder - find the key for partitioning the array
 * @arr: the array to be sorted
 * @start: pointer to the start of array
 * @end: pointer to the end
 * @size: the size of array
 * Return: returns the key
 */
int key_founder(int *arr, int start, int end, size_t size)
{
	int pavor = arr[end], key = start - 1, counter;

	for (counter = start; counter < end; counter++)
	{
		if (arr[counter] < pavor)
		{
			key++;
			if (key != counter)
			{
				swap_quick(&arr[key], &arr[counter]);
				print_array(arr, size);
			}
		}
	}
	if (arr[end] < arr[key + 1])
	{
		swap_quick(&arr[key + 1], &arr[end]);
		print_array(arr, size);
	}

	return (key + 1);
}

/**
 * parts_sorting - sorts an array of integers in ascending order
 * @arr: the array to be sorted
 * @start: pointer to the start of array
 * @end: pointer to the end
 * @size: the size of array
 */
void parts_sorting(int *arr, int start, int end, size_t size)
{
	int key = 0;

	if (start < end)
	{
		key = key_founder(arr, start, end, size);
		parts_sorting(arr, key + 1, end, size);
		parts_sorting(arr, start, key - 1, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	parts_sorting(array, 0, size - 1, size);
}
