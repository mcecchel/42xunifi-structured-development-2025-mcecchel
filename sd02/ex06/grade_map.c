#include "grade_map.h"

static const char	*get_plusminus_grade(int score)
{
	if (score >= 97)
		return ("A+");
	if (score >= 93)
		return ("A");
	if (score >= 90)
		return ("A-");
	if (score >= 87)
		return ("B+");
	if (score >= 83)
		return ("B");
	if (score >= 80)
		return ("B-");
	if (score >= 77)
		return ("C+");
	if (score >= 73)
		return ("C");
	if (score >= 70)
		return ("C-");
	if (score >= 67)
		return ("D+");
	if (score >= 63)
		return ("D");
	if (score >= 60)
		return ("D-");
	return ("F");
}

static const char	*get_passfail_grade(int score)
{
	if (score >= 60)
		return ("P");
	return ("F");
}

static const char	*get_standard_grade(int score)
{
	if (score >= 90)
		return ("A");
	if (score >= 80)
		return ("B");
	if (score >= 70)
		return ("C");
	if (score >= 60)
		return ("D");
	return ("F");
}

static const char	*get_grade_by_mapper(int score, GradeMapper mapper)
{
	if (mapper == PLUSMINUS)
		return (get_plusminus_grade(score));
	if (mapper == PASSFAIL)
		return (get_passfail_grade(score));
	if (mapper == STANDARD)
		return (get_standard_grade(score));
	return ("F");
}

void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	int	i;
	
	if (!scores || !mapped_grades || size <= 0)
		return;
	i = 0;
	while (i < size)
	{
		mapped_grades[i] = get_grade_by_mapper(scores[i], mapper);
		i++;
	}
}

// int main()
// {
// 	int scores[] = {95, 85, 75, 65, 55};
// 	const char *mapped_grades[5];
// 	int i = 0;

// 	map_scores(scores, 5, PLUSMINUS, mapped_grades);
// 	while (i < 5)
// 	{
// 		printf("Score: %d, Grade: %s\n", scores[i], mapped_grades[i]);
// 		i++;
// 	}
// 	return (0);
// }