#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

#include <stdlib.h>

struct Preferences;
struct MovieList;
struct Plan;

struct Preferences	*get_user_preferences(void);
struct MovieList	*find_movies(struct Preferences *prefs);
struct Plan			*build_plan(struct MovieList *list);

// funzione principale
struct Plan			*create_movie_night_plan(void);

#endif
