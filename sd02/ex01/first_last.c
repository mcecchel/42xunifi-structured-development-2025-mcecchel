#include "first_last.h"

static void	initialize_results(int *first, int *last)
{
	*first = -1;
	*last = -1;
}

static void	update_occurrence(int index, int *first, int *last)
{
	if (*first == -1)
		*first = index;
	*last = index;
}

void	first_last(int arr[], int size, int target, int *first, int *last)
{
	int i;
	
	if (!arr || !first || !last || size <= 0)
		return;
	
	initialize_results(first, last);
	
	i = 0;
	while (i < size)
	{
		if (arr[i] == target)
			update_occurrence(i, first, last);
		i++;
	}
}

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 2, 5, 2};
	int first;
	int last;
	
	first_last(arr, sizeof(arr) / sizeof(arr[0]), 2, &first, &last);
	if (first != -1 && last != -1)
		printf("First occurrence: %d, Last occurrence: %d\n", first, last);
	else
		printf("Target not found.\n");
	return (0);
}