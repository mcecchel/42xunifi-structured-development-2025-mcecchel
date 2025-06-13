/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:44:46 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 12:45:47 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float	average(const int *arr, int size)
{
	int	sum;
	int	count;
	int	i;

	i = 0;
	sum = 0;
	count = 0;
	while (i < size)
	{
		sum += arr[i];
		count++;
		i++;
	}
	if (count == 0)
		return (0.0f);
	return ((float)sum / count);
}
// int main(void)
// {
// 	int arr[] = {1, 2, 3, 4, 5};
// 	float res1 = average(arr, 5);
// 	printf("Average: %.2f\n", res1);
// 	float res2 = average(arr, 0);
// 	printf("Average: %.2f\n", res2);
// 	float res3 = average(NULL, 0);
// 	printf("Average: %.2f\n", res3);
// 	return (0);
// }
