#ifndef MOVIE_WATCHLIST_H
#define MOVIE_WATCHLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVIES 1000
#define MAX_FIELD_LEN 256
#define DATE_FORMAT "YYYY-MM-DD"
#define DATE_LEN 11

// Struct per la data
typedef struct
{
	int		year;
	int		month;
	int		day;
}			date_t;

// Struct principale del film
typedef struct
{
	int		id;
	char	title[MAX_FIELD_LEN];
	char	genre[MAX_FIELD_LEN];
	int		watched;// Dove 0 = non visto, 1 = visto
	int		rating;// Tra 1-10 se visto, 0 se non visto
	date_t	watch_date;// Da validare solo se watched = 1
}			movie_t;

// Gestione watchlist
typedef struct
{
	movie_t	movies[MAX_MOVIES];
	char	filename[MAX_FIELD_LEN];
	int		count;
	int		max_id;
}			watchlist_t;

// Statistiche per singolo genere
typedef struct s_stat_genre
{
	int		watched_count;
	int		unwatched_count;
	double	average_rating;
	char	genre[MAX_FIELD_LEN];
}			t_stat_genre;

// Statistiche generali
typedef struct s_stat
{
	int				total_movies;
	int				watched_count;
	int				unwatched_count;
	int				genre_count;
	double			avg_rating;
	t_stat_genre	genre_stats[50];
}					t_stat;

// Filtri di ricerca
typedef enum
{
	FILTER_ALL,
	FILTER_WATCHED,
	FILTER_UNWATCHED,
	FILTER_BY_TITLE,
	FILTER_BY_GENRE
}	filter_type_t;

// Main functions
watchlist_t		*wl_init(const char* filename);
int				wl_save_file(watchlist_t* wl);
int				wl_load_file(watchlist_t* wl);
void			wl_cleanup(watchlist_t* wl);

// Validation functions
int				validate_movie_id(int id, watchlist_t* wl);
int				validate_title(const char* title);
int				validate_genre(const char* genre);
int				validate_watched_flag(int watched);
int				validate_rating(int rating, int watched);
int				is_valid_date(int year, int month, int day);
int				validate_date(const char* date_str, date_t* date);

// Movie manage functions
int				add_movie(watchlist_t* wl, const char* title, const char* genre);
int				mark_watched(watchlist_t* wl, int id, int rating, const char* date_str);
int				update_movie(watchlist_t* wl, int id, const char* title, const char* genre);
int				delete_movie(watchlist_t* wl, int id);
movie_t			*find_by_id(watchlist_t* wl, int id);

// Search & filter 
int				filter_movies(watchlist_t* wl, filter_type_t filter, 
					 const char* query, movie_t results[], int max_results);
void			sort_by_id(movie_t movies[], int count);

// === STATISTICS ===
void			calculate_statistics(watchlist_t* wl, t_stat* stats);
void			display_statistics(const t_stat* stats);

// === DISPLAY FUNCTIONS ===
void			display_movie(const movie_t* movie);
void			display_movies(movie_t movies[], int count);
void			display_all(watchlist_t* wl);

// === UI FUNCTIONS ===
void			wl_main_menu(watchlist_t* wl);
int				wl_get_menu_choice(int min, int max);
char			*wl_get_user_input(const char* prompt, char* buffer, int size);

// Utils
char			*date_to_string(const date_t* date, char* buffer);
int				string_to_date(const char* str, date_t* date);
char			*trim_whitespace(char* str);
void			parse_csv_line(const char* line, char fields[][MAX_FIELD_LEN], int* count);

#endif