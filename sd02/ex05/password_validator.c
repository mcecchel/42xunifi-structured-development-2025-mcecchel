#include "password_validator.h"

static int	has_uppercase(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		i++;
	}
	return (0);
}

static int	has_lowercase(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (1);
		i++;
	}
	return (0);
}

static int	has_digit(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

static int	is_special_char(char c)
{
	const char	*specials = "@#$%^&*";
	int			i;
	
	i = 0;
	while (specials[i])
	{
		if (c == specials[i])
			return (1);
		i++;
	}
	return (0);
}

static int	has_special_char(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (is_special_char(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_different_password(const char *new_pw, const char *curr_pw)
{
	if (!curr_pw)
		return (1);
	 if (strcmp(new_pw, curr_pw) == 0)
		return (0);
	return (1);
}

static int	has_strength_requirements(const char *password)
{
	if (strlen(password) < MIN_LENGTH)
		return (0);
	if (!has_uppercase(password))
		return (0);
	if (!has_lowercase(password))
		return (0);
	if (!has_digit(password))
		return (0);
	if (!has_special_char(password))
		return (0);
	return (1);
}

PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	if (!new_pw)
		return INVALID;
	if (!has_strength_requirements(new_pw))
		return INVALID;
	if (!is_different_password(new_pw, curr_pw))
		return INVALID;
	return (VALID);
}

// int	main(void)
// {
// 	const char	*new_password = "Newpwd@123";
// 	const char	*current_password = "OldPassword";

// 	PwStatus status = validate_password(new_password, current_password);
// 	if (status == VALID)
// 		printf("Password is valid\n");
// 	else
// 		printf("Password is invalid\n");
// 	return (0);
// }