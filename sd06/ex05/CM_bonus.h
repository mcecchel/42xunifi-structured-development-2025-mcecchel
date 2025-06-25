// cm_bonus.h

#ifndef cm_BONUS_H
#define cm_BONUS_H

#include "contact_manager.h"

#define MAX_GROUP_LENGTH 100
#define MAX_FIELD_LENGTH 256
#define BIRTHDAY_FORMAT_LENGTH 11

// Struttura contact bonus
typedef struct s_contact_bonus
{
    int             id;
    char            name[MAX_FIELD_LENGTH];
    char            phone[MAX_FIELD_LENGTH];
    char            email[MAX_FIELD_LENGTH];
    char            city[MAX_FIELD_LENGTH];
    char            address[MAX_FIELD_LENGTH];
    char            group[MAX_GROUP_LENGTH];
    char            birthday[BIRTHDAY_FORMAT_LENGTH];
}                   t_contact_bonus;

// Manager bonus
typedef struct
{
    t_contact_bonus contacts[MAX_CONTACTS];
    int             count;
    int             max_id;
    char            filename[MAX_FIELD_LENGTH];
} t_cm_bonus;

typedef struct s_group_summary
{
    char            group_name[MAX_GROUP_LENGTH];
    int             contact_count;
}                   t_group_summary;

typedef struct s_upcoming_birthday
{
    t_contact_bonus contact;
    int             days_until_birthday;
}                   t_upcoming_birthday;

typedef enum
{
    MENU_LIST_ALL_EXT = 1,
    MENU_SEARCH_NAME_EXT,
    MENU_SEARCH_CITY_EXT,
    MENU_LIST_BY_GROUP,
    MENU_ADD_CONTACT_EXT,
    MENU_UPDATE_CONTACT_EXT,
    MENU_ASSIGN_GROUP,
    MENU_DELETE_CONTACT_EXT,
    MENU_UPCOMING_BIRTHDAYS,
    MENU_SAVE_EXIT_EXT
}   t_menu_option_bonus;

// Gestione manager
t_cm_bonus          *manager_bonus_init(const char *filename);
void                manager_bonus_destroy(t_cm_bonus *manager);

// Gestione contatti con backward compatibility
int                 load_contacts_bonus(t_cm_bonus *manager);
int                 parse_contact_line_bonus(const char *line, t_contact_bonus *contact, int *is_legacy_format);
int                 save_contacts_bonus(t_cm_bonus *manager);

// Gestione gruppi
int                 get_all_groups(const t_cm_bonus *manager, t_group_summary *groups, int max_groups);
int                 list_contacts_by_group(const t_cm_bonus *manager, const char *group_name,
                                  t_contact_bonus *results, int max_results);
int                 assign_contact_to_group(t_cm_bonus *manager, int contact_id, const char *group_name);

// Gestione compleanni
int                 get_upcoming_birthdays(const t_cm_bonus *manager, int days_ahead,
                                  t_upcoming_birthday *results, int max_results);
int                 calculate_days_until_birthday(const char *birthday);
int                 is_valid_birthday(const char *birthday);

// Operazioni sui contatti implementate
int                 add_contact_bonus(t_cm_bonus *manager, const t_contact_bonus *contact);
int                 update_contact_bonus(t_cm_bonus *manager, int id, const t_contact_bonus *updated);

// Validazione
int                 validate_contact_bonus(const t_contact_bonus *contact);
int                 validate_group_name(const char *group);

// UI
t_menu_option_bonus get_menu_choice_bonus(void);
t_contact_bonus     *input_contact_data_bonus(int id);
void                display_menu_bonus(void);
void                display_contact_bonus(const t_contact_bonus *contact);
void                display_groups_summary(const t_group_summary *groups, int count);
void                display_upcoming_birthdays(const t_upcoming_birthday *birthdays, int count);

// Utility per migrazione
int                 convert_legacy_contact(const t_contact *legacy, t_contact_bonus *extended);

#endif