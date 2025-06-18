#include "average.h"

static int	is_valid_score(int score)
{
	if (score < 0 || score > 100)
		return (0);
	return (1);
}

float	average(const int *arr, int size)
{
	int		i;
	int		sum;
	int		valid_count;

	if (!arr || size <= 0)
		return (0.0f);
	i = 0;
	sum = 0;
	valid_count = 0;
	while (i < size)
	{
		if (is_valid_score(arr[i]))
		{
			sum += arr[i];
			valid_count++;
		}
		i++;
	}
	if (valid_count == 0)
		return (0.0f);
	return ((float)sum / valid_count);
}

// int main()
// {
// 	int scores[] = {85, 90, 78, -5, 110, 95};
// 	int size = sizeof(scores) / sizeof(scores[0]);
// 	float avge = average(scores, size);
// 	printf("Average score: %.2f\n", avge);
// 	return 0;
// }