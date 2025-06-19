#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000
#define MAX_FIELD_LENGTH 256
#define DATE_FORMAT_LENGTH 11  // anno-mese-giorno + \0
#define MIN_AMOUNT 0.01
#define MAX_AMOUNT 999999.99

// Struttura per una spesa
typedef struct
{
	char	date[DATE_FORMAT_LENGTH];
	double	amount;
	char	category[MAX_FIELD_LENGTH];
	char	description[MAX_FIELD_LENGTH];
}			Expense;

// Struttura per il tracker
typedef struct
{
	Expense	expenses[MAX_EXPENSES];
	int		count;
}			ExpenseTracker;

// Struttura per le statistiche per categoria
typedef struct
{
	char	category[MAX_FIELD_LENGTH];
	double	total_amount;
	int		expense_count;
	double	percentage;
}			CategoryStatistics;

// Struttura per il sommario completo
typedef struct
{
	int					total_records;
	double				total_amount;
	double				average_expense;
	CategoryStatistics	categories[MAX_EXPENSES];
	int					unique_categories;
}						ExpenseAnalysis;

// Enumerazione per i tipi di filtro
typedef enum
{
	FILTER_BY_CATEGORY = 1,
	FILTER_BY_DATE_RANGE = 2,
	FILTER_SHOW_ALL = 3,
	FILTER_EXIT = 4
}	FilterType;

// Struttura per i criteri di filtro
typedef struct
{
	FilterType	type;
	char		category_query[MAX_FIELD_LENGTH];
	char		start_date[DATE_FORMAT_LENGTH];
	char		end_date[DATE_FORMAT_LENGTH];
}				FilterCriteria;

// Data Loading & Parsing func
int				load_expense_data(const char* filename, ExpenseTracker* tracker);
int				parse_expense_csv_line(const char* line, Expense* expense);
int				validate_expense_entry(const Expense* expense);
int				validate_date_format(const char* date);
int				validate_amount_range(double amount);
int				is_valid_date_value(int year, int month, int day);

// Filtering Operations func
int				apply_expense_filter(const ExpenseTracker* source, 
						const FilterCriteria* criteria, 
						ExpenseTracker* filtered_result);
int				expense_matches_category(const Expense* expense, const char* query);
int				expense_in_date_range(const Expense* expense, 
						 const char* start_date, 
						 const char* end_date);

// Analysis & Statistics func
ExpenseAnalysis	generate_expense_analysis(const ExpenseTracker* tracker);
void			calculate_category_breakdown(const ExpenseTracker* tracker, 
								 CategoryStatistics categories[], 
								 int* category_count);
void			calculate_category_percentages(CategoryStatistics categories[], 
								   int category_count, 
								   double total_amount);
double			calculate_average_expense(const ExpenseTracker* tracker);

// UI func
FilterType		prompt_filter_selection(void);
FilterCriteria	collect_filter_criteria(FilterType type);
char			*prompt_category_search(void);
void			prompt_date_range(char* start_date, char* end_date);
void			display_expense_summary(const ExpenseAnalysis* analysis);
void			display_category_breakdown(const CategoryStatistics categories[], 
							   int category_count);
void			display_filtered_results(const ExpenseTracker* filtered);

// String and Date Utilities func
char			*normalize_category_name(char* category);
int				compare_dates_lexicographic(const char* date1, const char* date2);
char			*format_currency_amount(double amount, char* buffer, size_t buffer_size);
void			convert_to_lowercase(char* str);

// Memory Management func
void			cleanup_expense_tracker(ExpenseTracker* tracker);
void			initialize_expense_tracker(ExpenseTracker* tracker);

#endif