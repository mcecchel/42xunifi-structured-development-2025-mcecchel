#include "segmented_runs.h"

static int	has_increasing_sequence(const int *segment, int seg_size)
{
	int consec_count;
	int i;
	
	if (seg_size < 3)
		return (0);
	consec_count = 1;
	i = 1;
	while (i < seg_size)
	{
		if (segment[i] == segment[i - 1] + 1)
		{
			consec_count++;
			if (consec_count >= 3)
				return (1);
		}
		else
			consec_count = 1;
		i++;
	}
	return (0);
}

static int	find_next_separator(const int *arr, int start, int size)
{
	int	i;
	
	i = start;
	while (i < size && arr[i] != -1)
		i++;
	return (i);
}

int	count_segments(const int *arr, int size)
{
	int	seg_count;
	int	start;
	int	end;

	if (!arr || size <= 0)
		return (0);
	seg_count = 0;
	start = 0;
	while (start < size)
	{
		end = find_next_separator(arr, start, size);
		if (end - start >= 3 && has_increasing_sequence(&arr[start], end - start))
			seg_count++;
		start = end + 1; // Move to the next segment after the separator
	}
	return (seg_count);
}

// int main(void)
// {
// 	int arr[] = {1, 2, 3, -1, 4, 5, 6, -1, 7, 8, 9};
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	int result = count_segments(arr, size);
	
// 	printf("Number of segments: %d\n", result);
// 	return (0);
// }