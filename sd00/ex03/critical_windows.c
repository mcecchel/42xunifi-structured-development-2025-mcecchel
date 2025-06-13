/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:01:44 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 13:30:23 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

// Conta valori  in una finestra di 5
static int	count_at_least(const int *arr, int threshold)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 5)
	{
		if (arr[i] >= threshold)
			count++;
		i++;
	}
	return (count);
}

// Check che nessuno dei 5 n. superi un dato valore massimo
static int	no_value_above(const int *arr, int max_value)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (arr[i] > max_value)
			return (0);
		i++;
	}
	return (1);
}

// Calcola la media di una finestra di 5 valori
static int	average(const int *arr, int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	if (!arr || size < 5)
		return (-1);
	while (i < 5)
	{
		sum += arr[i];
		i++;
	}
	return (sum / 5);
}

int	count_critical_windows(const int *readings, int size)
{
	int			i;
	int			cw_count;
	const int	*window;

	i = 0;
	cw_count = 0;
	while (i <= size - 5)
	{
		window = &readings[i];
		if (count_at_least(window, 70) >= 3 && no_value_above(window, 150)
			&& average(window, 5) >= 90)
			cw_count++;
		i++;
	}
	return (cw_count);
}
// int main(void)
// {
// 	int readings[] = {80, 90, 100, 70, 60, 150, 140, 130, 120, 110};
// 	int size = sizeof(readings) / sizeof(readings[0]);
// 	int critical_windows = count_critical_windows(readings, size);
// 	printf("Number of critical windows: %d\n", critical_windows);
// 	return (0);
// }
