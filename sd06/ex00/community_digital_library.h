#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 1000
#define MAX_FIELD_LENGTH 256
#define MAX_LINE_LENGTH 1024

// Struttura per rappresentare un libro
typedef struct
{
    int     id;
    char    title[MAX_FIELD_LENGTH];
    char    author[MAX_FIELD_LENGTH];
}        t_book;

// Struttura per catalogo biblioteca
typedef struct
{
    t_book  books[MAX_BOOKS];
    int     count;
}           t_library;

// Enum per i tipi di ricerca
typedef enum
{
    SEARCH_BY_TITLE = 1,
    SEARCH_BY_AUTHOR = 2,
    EXIT_PROGRAM = 3
}   t_search_type;

// Inizializzazione e cleanup
t_library       *library_init(void);
void            library_destroy(t_library *lib);

// Parsing
int             load_catalog(const char *filename, t_library *lib);
int             parse_book_line(const char *line, t_book *book);
char            *trim_whitespace(char *str);

// Validazione
int             validate_book(const t_book *book);
int             is_valid_id(int id);

// Ricerca
int             search_books(const t_library *lib, const char *query, t_search_type type, t_book *results, int max_results);
int             match_title(const t_book *book, const char *query);
int             match_author(const t_book *book, const char *query);

// Utils per check stringhe
char            *to_lowercase(char *str);
int             case_insensitive_contains(const char *haystack, const char *needle);

// Interface utente
void            display_menu(void);
t_search_type   get_user_choice(void);
char            *get_search_query(void);
void            display_results(const t_book *results, int count);
void            display_book(const t_book *book);

// Gestione errori
void            print_error(const char *message);
void            print_warning(const char *message, int line_number);

#endif