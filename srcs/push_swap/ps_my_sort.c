/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/17 15:59:45 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	1 	->	forward
**	-1	->	backward
*/

static int	check_direction(t_stack *stack, int value, int *count)
{
	int 	forward;
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
	if (count)
		*count = forward <= backward ? forward : backward;
	return (forward <= backward ? 1 : -1);
}

static void	push_value(t_stack *a, t_stack *b, int value, t_resolve *res)
{
	int	direction;

	direction = check_direction(a, value, NULL);
	while (a->head->value != value)
	{
		if (direction == 1)
			ps_rev_rotate(a, res);
		else
			ps_rotate(a, res);
	}
	ps_push(b, a, res);
}

t_resolve	*my_sort(t_stack *a, t_stack *b, int *goal)
{
	t_resolve	*res;
	int			i;
	int			t1;
	int			t2;

	res = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (res == NULL)
		memory_error();
	res->index = 'm';
	i = 0;
	while (stack_is_sort(a))
	{
		if (a->size > 2)
		{
			check_direction(a, goal[i], &t1);
			check_direction(a, goal[i+1], &t2);
			if (t2 < t1)
			{
				push_value(a, b, goal[i+1], res);
				push_value(a, b, goal[i], res);
				ps_swap(b, res);
				i += 2;
				continue;
			}
		}
		push_value(a, b, goal[i], res);
		i++;
	}
	while (b->size > 0)
		ps_push(a, b, res);
	return (res);
}
