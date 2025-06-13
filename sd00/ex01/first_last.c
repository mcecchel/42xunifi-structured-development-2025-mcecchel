/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:31:50 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 12:53:01 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void	first_last(int arr[], int size, int target, int *first, int *last)
{
	int	i;

	i = 0;
	*first = -1;
	*last = -1;
	while (i < size)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		i++;
	}
}
// int main(void)
// {
// 	int arr[] = {1, 2, 3, 4, 5, 3, 6, 3};
// 	int	first = -1;
// 	int	last = -1;
// 	first_last(arr, 8, 3, &first, &last);
// 	printf("First occurrence: %d\n", first);
// 	printf("Last occurrence: %d\n", last);
// 	return (0);
// }
