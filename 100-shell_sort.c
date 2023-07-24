#include "sort.h"

/**
* shell_sort - Function sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: The array of integers
* @size: Size of the array
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, j, i;
	int tmp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && tmp <= array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
