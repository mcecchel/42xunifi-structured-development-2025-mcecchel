/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:47:43 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 15:04:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void	plus_minus_mapper(int score, char *grade)
{
	if (score >= 97 && score <= 100)
		ft_strcpy(grade, "A+");
	else if (score >= 93)
		ft_strcpy(grade, "A");
	else if (score >= 90)
		ft_strcpy(grade, "A-");
	else if (score >= 87)
		ft_strcpy(grade, "B+");
	else if (score >= 83)
		ft_strcpy(grade, "B");
	else if (score >= 80)
		ft_strcpy(grade, "B-");
	else if (score >= 77)
		ft_strcpy(grade, "C+");
	else if (score >= 73)
		ft_strcpy(grade, "C");
	else if (score >= 70)
		ft_strcpy(grade, "C-");
	else if (score >= 67)
		ft_strcpy(grade, "D+");
	else if (score >= 63)
		ft_strcpy(grade, "D");
	else if (score >= 60)
		ft_strcpy(grade, "D-");
	else
		ft_strcpy(grade, "F");
}

void	pass_fail_mapper(int score, char *grade)
{
	if (score >= 60 && score <= 100)
		ft_strcpy(grade, "P");
	else
		ft_strcpy(grade, "F");
}

void	standard_mapper(int score, char *grade)
{
	if (score >= 90 && score <= 100)
		ft_strcpy(grade, "A");
	else if (score >= 80)
		ft_strcpy(grade, "B");
	else if (score >= 70)
		ft_strcpy(grade, "C");
	else if (score >= 60)
		ft_strcpy(grade, "D");
	else
		ft_strcpy(grade, "F");
}

void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mapper(scores[i], (char *)mapped_grades[i]);
		i++;
	}
}

// int main(void)
// {
// 	const int scores[] = {95, 85, 75, 65, 55};
// 	const int size = sizeof(scores) / sizeof(scores[0]);
// 	const char *mapped_grades[size];
// 	char grades[size][3];// 3 perche' max grade e' composto ca 1 lettera + 1 segno eventuale + '\0'
// 	int i = 0;

// 	while (i < size)
// 	{
// 		mapped_grades[i] = grades[i];
// 		i++;
// 	}
// 	map_scores(scores, size, plus_minus_mapper, mapped_grades);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("Score: %d, Grade: %s\n", scores[i], mapped_grades[i]);
// 		i++;
// 	}
// 	return (0);
// }