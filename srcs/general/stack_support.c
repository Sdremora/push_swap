/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:45:19 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 12:47:26 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

t_stack *new_stack_elem(int value)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->value = value;
	elem->prev = NULL;
	return (elem);
}

void	clear_stack(t_stack *stack)
{
	t_stack *cur_elem;
	t_stack	*temp;

	cur_elem = stack;
	while (cur_elem != NULL)
	{
		temp = cur_elem->prev;
		free(cur_elem);
		cur_elem = temp;
	}
}

t_stack	*stack_ini(int argc, char **argv)
{
	int i;
	t_stack	*top_elem;
	t_stack	*cur_elem;
	t_stack	*next_elem;

	i = 1;
	top_elem = new_stack_elem(ft_atoi(argv[i++]));
	if (top_elem == NULL)
		return (NULL);
	next_elem = top_elem;
	while (i < argc)
	{
		cur_elem = new_stack_elem(ft_atoi(argv[i]));
		if (cur_elem == NULL)
		{
			clear_stack(top_elem);
			return (NULL);
		}
		next_elem->prev = cur_elem;
		cur_elem = next_elem;
		i++;
	}
	return (top_elem);
}
