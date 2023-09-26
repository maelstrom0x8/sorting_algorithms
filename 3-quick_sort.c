#include <stdio.h>

#include "sort.h"



/**
 * qs_swap - Swaps two integer values.
 * @a: Pointer to the first integer value.
 * @b: Pointer to the second integer value.
 *
 * This function swaps the values of the two integers pointed to by 'a' and 'b'.
 */
void qs_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the first element of the integer array.
 * @size: Size of the array.
 * @low: Index of the first element of the partition.
 * @high: Index of the last element of the partition.
 *
 * This function takes an integer array and partitions it in-place using the Lomuto
 * partition scheme, selecting the last element as the pivot. It rearranges the elements
 * of the array such that all elements less than or equal to the pivot are on the left side,
 * and all elements greater than the pivot are on the right side of the partition.
 *
 * @return: The index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int j;
    int pivot = array[high];
    int i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            qs_swap(&array[i], &array[j]);
            /* print_array(array, size); */
        }
    }

    qs_swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return i + 1;
}


/**
 * quick_sort_recursive - Recursively sorts an array using the Quick Sort algorithm.
 * @array: Pointer to the first element of the integer array.
 * @size: Size of the array.
 * @low: Index of the first element of the partition.
 * @high: Index of the last element of the partition.
 *
 * This function is a recursive implementation of the Quick Sort algorithm. It takes
 * an integer array and sorts it in ascending order by recursively partitioning the
 * array and sorting the subarrays on both sides of the pivot element. It modifies
 * the input array in-place.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int partition_index = lomuto_partition(array, size, low, high);

        quick_sort_recursive(array, size, low, partition_index - 1);
        quick_sort_recursive(array, size, partition_index + 1, high);
    }
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm.
 * @array: Pointer to the first element of the integer array.
 * @size: Size of the array.
 *
 * This function sorts the given integer array in ascending order using the Quick Sort
 * algorithm. It modifies the input array in-place.
 */
void quick_sort(int *array, size_t size)
{
    int low, high;
    if (array == NULL || size <= 1)
    {
        return;
    }

    low = 0;
    high = size - 1;

    quick_sort_recursive(array, size, low, high);
}
