// movie_watchlist.h

#ifndef MOVIE_WATCHLIST_H
#define MOVIE_WATCHLIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_MOVIES 1000
#define MAX_FIELD_LENGTH 256
#define DATE_FORMAT_LENGTH 11

typedef struct s_movie
{
    int             id;
    int             watched;        // 0 or 1
    int             rating;         // 1-10 se visto, 0 se non
    char            title[MAX_FIELD_LENGTH];
    char            genre[MAX_FIELD_LENGTH];
    char            date_watched[DATE_FORMAT_LENGTH]; // YYYY-MM-DD or empty
}                   t_movie;

typedef struct s_watchlist
{
    int             count;
    int             max_id;
    char            filename[MAX_FIELD_LENGTH];
    t_movie         movies[MAX_MOVIES];
}                   t_watchlist;

typedef struct s_genre_stat
{
    int             total_count;
    int             watched_count;
    int             unwatched_count;
    char            genre[MAX_FIELD_LENGTH];
    double          average_rating;
    double          total_rating;
}                   t_genre_stat;

typedef struct s_watchlist_stat
{
    int             total_movies;
    int             watched_count;
    int             unwatched_count;
    int             genre_count;
    double          overall_average_rating;
    t_genre_stat    genre_breakdown[MAX_MOVIES];
} t_watchlist_stat;

typedef enum
{
    MENU_LIST_ALL = 1,
    MENU_SEARCH_TITLE,
    MENU_SEARCH_GENRE,
    MENU_FILTER_WATCHED,
    MENU_FILTER_UNWATCHED,
    MENU_ADD_MOVIE,
    MENU_MARK_WATCHED,
    MENU_UPDATE_MOVIE,
    MENU_DELETE_MOVIE,
    MENU_SHOW_STATS,
    MENU_SAVE_EXIT
}   t_menu_option;

// Gestione watchlist
t_watchlist         *watchlist_init(const char *filename);
void                watchlist_destroy(t_watchlist *watchlist);

// Parsing
int                 load_watchlist(t_watchlist *watchlist);
int                 save_watchlist(t_watchlist *watchlist);
int                 parse_movie_line(const char *line, t_movie *movie);

// Operazioni sul film
int                 add_movie(t_watchlist *watchlist, const t_movie *movie);
int                 update_movie(t_watchlist *watchlist, int id, const t_movie *updated);
int                 delete_movie(t_watchlist *watchlist, int id);
int                 mark_as_watched(t_watchlist *watchlist, int id, int rating, const char *date);
t_movie             *find_movie_by_id(t_watchlist *watchlist, int id);

// Ricerca e filtri
int                 search_movies(const t_watchlist *watchlist, const char *query,
                        int (*match_function)(const t_movie *, const char *), t_movie *results, int max_results);
int                 filter_by_watched_status(const t_watchlist *watchlist, int watched_status,
                            t_movie *results, int max_results);
int                 match_by_title(const t_movie *movie, const char *query);
int                 match_by_genre(const t_movie *movie, const char *query);

// Statistiche
t_watchlist_stat    *calculate_stats(const t_watchlist *watchlist);
void                stats_destroy(t_watchlist_stat *stats);

// Validazione
int                 validate_movie(const t_movie *movie);
int                 validate_rating(int rating, int watched);
int                 validate_watched_date(const char *date, int watched);

// UI
void                display_menu(void);
t_menu_option       get_menu_choice(void);
t_movie             *input_movie_data(int id);
void                display_movie(const t_movie *movie);
void                display_movies_list(const t_movie *movies, int count);
void                display_stats(const t_watchlist_stat *stats);

// Utils
int                 generate_next_movie_id(const t_watchlist *watchlist);
void                sort_movies_by_id(t_movie *movies, int count);

#endif