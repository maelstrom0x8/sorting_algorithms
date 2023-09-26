#include "sort.h"

/**
 * bs_swap - Swaps two integer values.
 * @a: Pointer to the first integer value.
 * @b: Pointer to the second integer value.
 *
 * This function swaps the values of the two integers
 * pointed to by 'a' and 'b'.
 */
void bs_swap(int *a, int *b)
{
    iint tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble Sort algorithm.
 * @ar: Pointer to the first element of the integer array.
 * @size: Size of the array.
 *
 * This function sorts the given integer array in ascending
 * order using the Bubble Sort algorithm. It modifies the input array in-place.
 */
void bubble_sort(int *ar, size_t size)
{
    size_t i, j;

    for (j = 0; j < size; ++j)
    {
        for (i = 0; i < size - 1; ++i)
        {
            if (ar[i] > ar[i + 1])
            {
                bs_swap(&ar[i], &ar[i + 1]);
                print_array(ar, size);
            }
        }
    }
}
