#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8

typedef enum
{
	VALID = 0,
	INVALID = 1
}		PwStatus;

PwStatus	validate_password(const char *new_pw, const char *curr_pw);

#endif
