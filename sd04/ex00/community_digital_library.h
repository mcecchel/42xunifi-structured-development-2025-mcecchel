#ifndef COMMUNITY_DIGITAL_LIBRARY_H
#define COMMUNITY_DIGITAL_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 1000
#define MAX_FIELD_LENGTH 256
#define MAX_LINE_LENGTH 1024

// Struct principale libro
typedef struct
{
	int		id;
	char	title[MAX_FIELD_LENGTH];
	char	author[MAX_FIELD_LENGTH];
}			Book;

// Struttura per il catalogo
typedef struct
{
	Book	books[MAX_BOOKS];
	int		count;
	int		max_id;
}			Library;

// Enumerazione per i tipi di ricerca
typedef enum
{
	SEARCH_BY_TITLE = 1,
	SEARCH_BY_AUTHOR = 2,
	EXIT_PROGRAM = 3
}			SearchType;

// Struttura per i risultati di ricerca
typedef struct
{
	Book	*books[MAX_BOOKS];
	int		count;
}			SearchResults;


// Data Loading & Parsing func
int				load_library_catalog(const char* filename, Library* library);
int				parse_csv_line(const char* line, Book* book);
char			*trim_whitespace(char* str);
int				validate_book_entry(const Book* book, const Library* library);
int				is_duplicate_id(const Library* library, int id);

// Search Operations func
SearchResults	search_books_by_title(const Library* library, const char* query);
SearchResults	search_books_by_author(const Library* library, const char* query);
int				case_insensitive_substring_match(const char* text, const char* query);

// UI func
SearchType		prompt_search_type(void);
char			*prompt_search_query(void);
void			display_search_results(const SearchResults* results);
void			display_single_book(const Book* book);
void			display_welcome_message(void);

// Error Handling & Utilities func
void			log_error(const char* message);
void			log_warning(const char* message);
void			cleanup_resources(Library* library);
int				safe_string_copy(char* dest, const char* src, size_t dest_size);

// Input Validation func
int				is_valid_search_input(const char* input);
void			clear_input_buffer(void);

#endif