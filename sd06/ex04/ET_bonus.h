#ifndef EXPENSE_TRACKER_BONUS_H
#define EXPENSE_TRACKER_BONUS_H

#include "expense_tracker.h"

// Estensione della struttura expense per includere ID
typedef struct s_expense
{
    int         id;
    char        date[DATE_FORMAT_LENGTH];
    char        category[MAX_FIELD_LENGTH];
    char        description[MAX_FIELD_LENGTH];
    double      amount;
}               t_expense;

// Estensione del tracker
typedef struct s_expense_tracker
{
    t_expense   expenses[MAX_EXPENSES];
    int         count;
    int         max_id;
    char        filename[MAX_FIELD_LENGTH];
}               t_expense_tracker;

typedef enum
{
    MENU_LIST_ALL = 1,
    MENU_SEARCH_CATEGORY,
    MENU_FILTER_DATE_RANGE,
    MENU_ADD_EXPENSE,
    MENU_EDIT_EXPENSE,
    MENU_DELETE_EXPENSE,
    MENU_SHOW_SUMMARY,
    MENU_SAVE_EXIT
}   t_menu_option;

// Gestione tracker
t_expense_tracker  *et_init(const char *filename);
void               et_destroy(t_expense_tracker *tracker);

// File I/O con backward compatibility
int                 load_expenses(t_expense_tracker *tracker);
int                 parse_expense_line(const char *line, t_expense *expense, int *is_legacy_format);
int                 save_expenses(t_expense_tracker *tracker);

// Operazioni
int                 add_expense(t_expense_tracker *tracker, const t_expense *expense);
int                 update_expense(t_expense_tracker *tracker, int id, const t_expense *updated);
int                 delete_expense(t_expense_tracker *tracker, int id);
t_expense           *find_expense_by_id(t_expense_tracker *tracker, int id);

// Utils per migrazione
int                 convert_legacy_expense(const t_expense *legacy, t_expense *extended, int new_id);
int                 generate_next_expense_id(const t_expense_tracker *tracker);

// UI
void                display_menu(void);
t_menu_option       get_expense_menu_choice(void);
t_expense           *input_expense_data(int id);
void                display_expense(const t_expense *expense);

#endif