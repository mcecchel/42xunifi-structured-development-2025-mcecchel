/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:36:02 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/11 13:50:03 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

static int	is_special(char c)
{
	int			i;
	const char	*specials;

	i = 0;
	specials = "(@#$%ˆ&*";
	while (specials[i])
	{
		if (c == specials[i])
			return (1);
		i++;
	}
	return (0);
}

t_pw_status	validate_password(const char *new_pw, const char *curr_pw)
{
	int	i;
	int	len;
	int	has_upper;
	int	has_lower;
	int	has_digit;
	int	has_special;

	i = 0;
	len = 0;
	has_upper = 0;
	has_lower = 0;
	has_digit = 0;
	has_special = 0;
	if (!new_pw || !curr_pw)
		return (IS_INVALID);
	while (new_pw[len])
		len++;
	if (len < 8)
		return (IS_INVALID);
	while (new_pw[i])
	{
		if (new_pw[i] >= 'A' && new_pw[i] <= 'Z')
			has_upper = 1;
		else if (new_pw[i] >= 'a' && new_pw[i] <= 'z')
			has_lower = 1;
		else if (new_pw[i] >= '0' && new_pw[i] <= '9')
			has_digit = 1;
		else if (is_special(new_pw[i]))
			has_special = 1;
		i++;
	}
	if (!has_upper || !has_lower || !has_digit || !has_special)
		return (IS_INVALID);
	i = 0;
	while (new_pw[i] && curr_pw[i] && new_pw[i] == curr_pw[i])
		i++;
	if (new_pw[i] == curr_pw[i])
		return (IS_INVALID);
	return (IS_VALID);
}
// int	main(void)
// {
// 	const char *new_pw = "Password123$";
// 	const char *curr_pw = "CurrentPass@1";
// 	t_pw_status status = validate_password(new_pw, curr_pw);
// 	if (status == IS_VALID)
// 		printf("Password is valid\n");
// 	else
// 		printf("Password is invalid\n");
// 	return (0);
// }
