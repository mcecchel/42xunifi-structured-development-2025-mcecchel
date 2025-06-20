#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_FIELD_LEN 256
#define TEMP_FILE_SUFFIX ".tmp"

// Struct principale del contatto
typedef struct
{
	int		id;
	char	name[MAX_FIELD_LEN];
	char	phone[MAX_FIELD_LEN];
	char	email[MAX_FIELD_LEN];
	char	city[MAX_FIELD_LEN];
	char	address[MAX_FIELD_LEN];
}			contact_t;

// Gestore contatti
typedef struct
{
	int			count;
	int			max_id;
	contact_t	contacts[MAX_CONTACTS];
	char		filename[MAX_FIELD_LEN];
}				contact_manager_t;

// Enum per i tipi di ricerca
typedef enum {
	SEARCH_BY_NAME,
	SEARCH_BY_CITY
} search_type_t;

// Inizializzazione e cleanup
contact_manager_t*	cm_init(const char* filename);
void				cm_cleanup(contact_manager_t* cm);
int					cm_load_file(contact_manager_t* cm);
int					cm_save_file(contact_manager_t* cm);

// Validation functions
int					validate_id(int id, contact_manager_t* cm);
int					validate_name(const char* name);
int					validate_phone(const char* phone);
int					validate_email(const char* email);
int					validate_city(const char* city);

// Operations on contacts
int			cm_add_contact(contact_manager_t* cm, const char* name, 
				   const char* phone, const char* email, 
				   const char* city, const char* address);
int			cm_update_contact(contact_manager_t* cm, int id, 
					  const char* name, const char* phone, 
					  const char* email, const char* city, 
					  const char* address);
int			cm_delete_contact(contact_manager_t* cm, int id);
contact_t*	cm_find_by_id(contact_manager_t* cm, int id);

// Search operation
int			cm_search(contact_manager_t* cm, search_type_t type, 
			  const char* query, contact_t results[], int max_results);

// Display functions
void		cm_display_contact(const contact_t* contact);
void		cm_display_all(contact_manager_t* cm);
void		cm_display_search_results(contact_t results[], int count);

// UI functions
void		cm_main_menu(contact_manager_t* cm);
int			get_menu_choice(int min, int max);
char		*get_user_input(const char* prompt, char* buffer, int size);
int			confirm_action(const char* message);

// Utils
char		*trim_whitespaces(char* str);
void		parse_csv_line(const char* line, char fields[][MAX_FIELD_LEN], int* field_count);

#endif