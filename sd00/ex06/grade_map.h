#ifndef GRADE_MAP_H
# define GRADE_MAP_H

# include <stdio.h>

typedef void	(*GradeMapper)(int score, char *grade);

void	ft_strcpy(char *dest, const char *src);
void	plus_minus_mapper(int score, char *grade);
void	pass_fail_mapper(int score, char *grade);
void	standard_mapper(int score, char *grade);
void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
