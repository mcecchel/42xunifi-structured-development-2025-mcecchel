#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_EXPENSES 1000
#define MAX_FIELD_LENGTH 256
#define DATE_FORMAT_LENGTH 11  // anno-mese-giorno + \0

typedef struct  s_expense
{
    char                date[DATE_FORMAT_LENGTH];
    char                category[MAX_FIELD_LENGTH];
    char                description[MAX_FIELD_LENGTH];
    double              amount;
}                       t_expense;

typedef struct  s_expense_tracker
{
    t_expense           expenses[MAX_EXPENSES];
    int                 count;
}                       t_expense_tracker;

typedef struct  s_filter
{
    char                start_date[DATE_FORMAT_LENGTH];
    char                end_date[DATE_FORMAT_LENGTH];
    char                category_filter[MAX_FIELD_LENGTH];
    int                 filter_type; // 0=none, 1=category, 2=date_range
}                       t_filter;

typedef struct s_category_summary
{
    int                 count;
    char                category[MAX_FIELD_LENGTH];
    double              total_amount;
    double              percent;
}                       t_category_summary;

typedef struct s_expense_summary
{
    int                 total_records;
    double              total_amount;
    double              average_expense;
    t_category_summary  categories[MAX_EXPENSES];
    int                 category_count;
}                       t_expense_summary;

// Gestione tracker
t_expense_tracker   *tracker_init(void);
void                tracker_destroy(t_expense_tracker *tracker);

// Parsing
int                 load_expenses(const char *filename, t_expense_tracker *tracker);
int                 parse_expense_line(const char *line, t_expense *expense);

// Validazione
int                 validate_expense(const t_expense *expense);
int                 validate_date(const char *date);
int                 validate_amount(double amount);

// Gestione filtri
t_filter            *init_filter(void);
void                destroy_filter(t_filter *filter);
int                 apply_filter(const t_expense_tracker *tracker, const t_filter *filter, t_expense *filtered_results, int max_results);

// Statistiche
t_expense_summary   *calculate_summary(const t_expense *expenses, int count);
void                summary_destroy(t_expense_summary *summary);

// Utils per date
int                 compare_dates(const char *date1, const char *date2);
int                 is_date_in_range(const char *date, const char *start, const char *end);

// Interfaccia utente
void                display_main_menu(void);
int                 get_filter_choice(void);
t_filter            *configure_filter(void);
void                display_summary(const t_expense_summary *summary);

#endif