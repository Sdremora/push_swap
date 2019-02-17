/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_buble_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 15:28:21 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	1 	->	forward
**	-1	->	backward
*/

static int	check_direction(t_stack *stack, int value)
{
	int		forward;
	int		backward;
	t_elem	*elem;

	forward = 0;
	backward = 0;
	elem = stack->head;
	while (elem->value != value)
	{
		elem = elem->next;
		forward++;
	}
	backward = stack->size - forward;
	return (forward <= backward ? 'f' : 'b');
}

t_resolve	*ps_buble_sort(t_stack *a, t_stack *b, int *goal)
{
	t_resolve	*res;
	int			direction;
	int			i;

	res = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (res == NULL)
		memory_error();
	res->index = '0';
	i = 0;
	while (stack_is_sort(a))
	{
		direction = check_direction(a, goal[i]);
		while (a->head->value != goal[i])
		{
			if (direction == 'f')
				ps_rev_rotate(a, res);
			else
				ps_rotate(a, res);
		}
		if (stack_is_sort(a))
			ps_push(b, a, res);
		i++;
	}
	while (b->size > 0)
		ps_push(a, b, res);
	return (res);
}
