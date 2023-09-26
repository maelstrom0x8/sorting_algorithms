#include <stdio.h>

#include "sort.h"


/**
 * ss_swap - Swaps two integer values.
 * @a: Pointer to the first integer value.
 * @b: Pointer to the second integer value
 */
void ss_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection Sort algorithm.
 * @array: Pointer to the first element of the integer array.
 * @size: Size of the array.
 *
 * This function sorts the given integer array in ascending order using
 * the Selection Sort algorithm. It modifies the input array in-place.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
	{
		return;
	}

	for (i = 0; i < size - 2; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			ss_swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
