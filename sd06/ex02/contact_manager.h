// contact_manager.h

#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_FIELD_LENGTH 256

typedef struct s_contact
{
    int         id;
    char        name[MAX_FIELD_LENGTH];
    char        phone[MAX_FIELD_LENGTH];
    char        email[MAX_FIELD_LENGTH];
    char        city[MAX_FIELD_LENGTH];
    char        address[MAX_FIELD_LENGTH];
}               t_contact;

typedef struct s_contact_manager
{
    t_contact   contacts[MAX_CONTACTS];
    char        filename[MAX_FIELD_LENGTH];
    int         count;
    int         max_id;
}               t_contact_manager;

typedef enum
{
    MENU_LIST_ALL = 1,
    MENU_SEARCH_NAME,
    MENU_SEARCH_CITY,
    MENU_ADD_CONTACT,
    MENU_UPDATE_CONTACT,
    MENU_DELETE_CONTACT,
    MENU_SAVE_EXIT
}   t_menu_option;

// Gestione manager
t_contact_manager   *manager_init(const char *filename);
void                manager_destroy(t_contact_manager *manager);

// Parsing
int                 load_contacts(t_contact_manager *manager);
int                 save_contacts(t_contact_manager *manager);
int                 parse_contact_line(const char *line, t_contact *contact);

// Gestione contatti
int                 add_contact(t_contact_manager *manager, const t_contact *contact);
int                 update_contact(t_contact_manager *manager, int id, const t_contact *updated);
int                 delete_contact(t_contact_manager *manager, int id);
t_contact           *find_contact_by_id(t_contact_manager *manager, int id);

// Ricerca
int                 search_contacts(const t_contact_manager *manager, const char *query,
                        int (*match_function)(const t_contact *, const char *),
                        t_contact *results, int max_results);
int                 match_by_name(const t_contact *contact, const char *query);
int                 match_by_city(const t_contact *contact, const char *query);

// Validazione
int                 validate_contact(const t_contact *contact);
int                 validate_email(const char *email);
int                 validate_phone(const char *phone);
int                 is_unique_id(const t_contact_manager *manager, int id);

// Interfaccia utente
void                display_menu(void);
t_menu_option       get_menu_choice(void);
t_contact           *input_contact_data(int id);
void                display_contact(const t_contact *contact);
void                display_contacts_list(const t_contact *contacts, int count);

// Utils
int                 generate_next_id(const t_contact_manager *manager);
char                *create_temp_filename(const char *original);

#endif