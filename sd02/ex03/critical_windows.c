#include "critical_windows.h"

static int	count_high_readings(const int *window)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (i < WINDOW_SIZE)
	{
		if (window[i] >= HIGH_THRESHOLD)
			count++;
		i++;
	}
	return (count);
}

static int	has_excessive_reading(const int *window)
{
	int	i;
	
	i = 0;
	while (i < WINDOW_SIZE)
	{
		if (window[i] > MAX_THRESHOLD)
			return 1;
		i++;
	}
	return (0);
}

static float	calculate_average(const int *window)
{
	int	sum;
	int	i;
	
	sum = 0;
	i = 0;
	while (i < WINDOW_SIZE)
	{
		sum += window[i];
		i++;
	}
	return (float)sum / WINDOW_SIZE;
}

static int	is_critical_window(const int *window)
{
	int		high_count;
	float	avg;
	
	high_count = count_high_readings(window);
	if (high_count < 3)
		return (0);
	if (has_excessive_reading(window))
		return (0);
	avg = calculate_average(window);
	if (avg < AVG_THRESHOLD)
		return (0);
	return (1);
}

int	count_critical_windows(const int *readings, int size)
{
	int	count;
	int	i;
	
	if (!readings || size < WINDOW_SIZE)
		return 0;
	count = 0;
	i = 0;
	while (i <= size - WINDOW_SIZE)
	{
		if (is_critical_window(&readings[i]))
			count++;
		i++;
	}
	return (count);
}

int main(void)
{
	int readings[] = {80, 85, 90, 95, 100, 110, 120, 130, 140, 150, 160};
	int size = sizeof(readings) / sizeof(readings[0]);
	int result = count_critical_windows(readings, size);
	
	if (result == 0)
		printf("No critical windows found\n");
	else
		printf("Found %d critical windows\n", result);
	return (0);
}