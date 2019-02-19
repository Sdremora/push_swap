/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_handle_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:52:31 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 11:23:09 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	double_com(char com, t_stack *a, t_stack *b)
{
	if (com == 's')
	{
		stack_swap(a);
		stack_swap(b);
	}
		else if (com == 'r')
	{
		stack_rotate(a);
		stack_rotate(b);
	}
		else if (com == 'w')
	{
		stack_rev_rotate(a);
		stack_rev_rotate(b);
	}
}

static int	check_and_make(char *com, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(com, "pa"))
		stack_push(a, b);
	else if (!ft_strcmp(com, "pb"))
		stack_push(b, a);
	else if (!ft_strcmp(com, "sa"))
		stack_swap(a);
	else if (!ft_strcmp(com, "sb"))
		stack_swap(b);
	else if (!ft_strcmp(com, "ss"))
		double_com('s', a, b);
	else if (!ft_strcmp(com, "ra"))
		stack_rotate(a);
	else if (!ft_strcmp(com, "rb"))
		stack_rotate(b);
	else if (!ft_strcmp(com, "rr"))
		double_com('r', a, b);
	else if (!ft_strcmp(com, "rra"))
		stack_rev_rotate(a);
	else if (!ft_strcmp(com, "rrb"))
		stack_rev_rotate(b);
	else if (!ft_strcmp(com, "rrr"))
		double_com('w', a, b);
	else
		return (-1);
	return (0);
}

int			handle_commands(t_stack *a, t_stack *b, char *flags)
{
	char	*com;

	if (flags[0] == 'v')
		stack_write(a, b, "ini");
	while (get_next_line(0, &com))
	{
		if (check_and_make(com, a, b))
			return (-1);
		if (flags[0] == 'v')
			stack_write(a, b, com);
	}
	return (0);
}
