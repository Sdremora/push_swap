/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:55:53 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 14:01:12 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nondigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && !(i == 0 && (str[i] == '-' || str[i] == '+')))
			return (-1);
		i++;
	}
	return (0);
}

static int	check_overflow(char *str)
{
	int len;
	int sign;

	sign = (*str == '-') ? 1 : 0;
	len = ft_strlen(str) - sign;
	if (len < 10)
		return (0);
	if (len == 10 && sign == 0 && ft_strcmp("2147483647", str) >= 0)
		return (0);
	if (len == 10 && sign == 1 && ft_strcmp("-2147483648", str) >= 0)
		return (0);
	return (-1);
}

int			check_input(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (check_nondigit(argv[i]) < 0)
			return (-1);
		if (check_overflow(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
