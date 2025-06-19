#include "movie_planner.h"

struct Plan	*create_movie_night_plan()
{
	struct Preferences	*prefs;
	struct MovieList	*movies;
	struct Plan			*plan;
	
	prefs = NULL;
	movies = NULL;
	plan = NULL;
	prefs = get_user_preferences();
	if (!prefs)
		return (NULL);
	movies = find_movies(prefs);
	if (!movies) {
		free(prefs);
		return (NULL);
	}
	plan = build_plan(movies);
	free(prefs);
	free(movies);
	return (plan);
}