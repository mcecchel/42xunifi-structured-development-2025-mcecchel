#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

#include <stdlib.h>

struct Preferences
{
	char	*genre;
	int		min_rating;
	int		max_duration;
};

struct Movie
{
	char	*title;
	char	*genre;
	int		rating;
	int		duration;
};

struct MovieList
{
	struct Movie	*movies;
	int				count;
	int				capacity;
};

struct Plan
{
	struct Movie	*selected_movie;
	char			*start_time;
	char			*venue;
};

// Helper functions
struct Preferences	*get_user_preferences(void);
struct MovieList	*find_movies(struct Preferences *prefs);
struct Plan			*build_plan(struct MovieList *list);

// Main function
struct Plan			*create_movie_night_plan(void);

#endif