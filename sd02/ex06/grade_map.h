#ifndef GRADE_MAP_H
#define GRADE_MAP_H

#include <stdio.h>

typedef enum
{
	PLUSMINUS,
	PASSFAIL,
	STANDARD
}		GradeMapper;

void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
