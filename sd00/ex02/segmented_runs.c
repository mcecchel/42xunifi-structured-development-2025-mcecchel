/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:39 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 12:47:48 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int	count_segments(const int *arr, int size)
{
	int	seg_count;
	int	has_run;
	int	run_len;
	int	i;

	seg_count = 0;
	i = 0;
	while (i < size)
	{
		// Salta eventuali -1 iniziali
		while (i < size && arr[i] == -1)
			i++;
		has_run = 0;
		run_len = 1;
		while (i + 1 < size && arr[i + 1] != -1)
		{
			if (arr[i + 1] > arr[i])
				run_len++;
			else
				run_len = 1;
			if (run_len >= 3)
				has_run = 1;
			i++;
		}
		if (has_run)
			seg_count++;
		while (i < size && arr[i] != -1)
			i++;// Va al prossimo segmento
	}
	return (seg_count);
}
// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, -1, 4, 5, 6, -1, 7, 8, 9, -1};
// 	int	size = sizeof(arr) / sizeof(arr[0]);
// 	int	segments = count_segments(arr, size);
// 	printf("N. of segments: %d\n", segments);
// 	return (0);
// }
