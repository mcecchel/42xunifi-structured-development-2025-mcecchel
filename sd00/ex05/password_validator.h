#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

# include <stdio.h>

typedef enum e_pw_status
{
	IS_VALID = 0,
	IS_INVALID = 1
}			t_pw_status;

t_pw_status	validate_password(const char *new_pw, const char *curr_pw);

#endif
