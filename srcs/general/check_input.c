/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:55:53 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 11:05:58 by sdremora         ###   ########.fr       */
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

static int	check_duplicates(char *arg, t_stack *stack)
{
	int		value;
	t_elem	*elem;

	value = ft_atoi(arg);
	elem = stack->head;
	while (elem != NULL)
	{
		if (value == elem->value)
			return (-1);
		elem = elem->prev;
	}
	return (0);
}

int			check_input(char *arg, t_stack *stack)
{

	if (check_nondigit(arg) < 0)
		return (-1);
	if (check_overflow(arg) < 0)
		return (-1);
	if (check_duplicates(arg, stack) < 0)
		return (-1);
	return (0);
}
