#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array and returns the i of the pivot elmnt
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] < array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - Helper function for Quick Sort
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{

	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of int in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
