#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences	*prefs;
	
	// Ottenere le preferenze dell'utente
	prefs = get_user_preferences();
	if (!prefs)
		return (NULL);
	// Trova i film che corrispondono alle preferenze
	struct MovieList *movies = find_movies(prefs);
	if (!movies)
	{
		free(prefs);
		return (NULL);
	}
	// Costruisci il piano finale della serata
	struct Plan *plan = build_plan(movies);
	free(prefs);
	free(movies);
	return (plan);
}
