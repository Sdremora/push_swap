/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_devide_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 09:37:01 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/17 15:51:21 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return index in array or -1 if not exist
*/

int			is_exist(int value, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int			devide_stack(t_stack *a, t_stack *b, t_resolve *res, int *goal)
{
	int	size_b;
	t_elem	*cur_elem;

	size_b = a->size / 2;
	while (b->size != size_b)
	{
		cur_elem = a->head;
		if (is_exist(cur_elem->value, goal, size_b) >= 0)
			ps_push(b, a, res);
		else
			ps_rotate(a, res);
	}
	return (res->count);
}

/*
**	0	->	stack is not sorted
**	a	->	stack is sorted in ascending order
**	d	->	stack is sorted in descending order
*/

char		check_order(t_stack *st)
{
	int		dif;
	t_elem	*cur_elem;
	int		count;
	int		i;

	cur_elem = st->head;
	dif = 0;
	count = 0;
	i = 0;
	while (i < st->size)
	{
		if (dif == 0)
			dif = cur_elem->value - cur_elem->prev->value;
		if (dif < 0 && cur_elem->value - cur_elem->prev->value > 0)
			count++;
		if (dif > 0 && cur_elem->value - cur_elem->prev->value < 0)
			count++;
		cur_elem = cur_elem->prev;
		i++;
	}
	if (count == 1)
		return ((dif < 0) ? 'a' : 'd');
	if (count == st->size - 1)
		return ((dif < 0) ? 'd' : 'a');
	return (0);
}

/*
**	'o'	->	sorted
**	'r'	->	need rotate
**	's'	->	need swap
**	't'	->	opposite order
*/

char		sort_stack(t_stack *stack, char order, int *goal, int size)
{
	int		i;
	t_elem	*elem;
	char	is_order;
	int		goal_value;
	int		min_value;

	if (stack->name[0] == 'a')
	{
		goal_value = goal[size - stack->size];
		min_value = goal[size-1];
	}
	if (stack->name[0] == 'b')
	{
		goal_value = goal[stack->size - 1];
		min_value = goal[0];
	}
	elem = stack->head;
	i = 0;
	is_order = check_order(stack);
	if (is_order == order && stack->head->value == goal_value)
		return ('o');
	if (is_order != 0 && is_order == order && stack->head->value != goal_value)
		return ('r');
	if (is_order != 0 && is_order != order)
		return ('t');
	if (stack->head->value == min_value)
		return ('r');
	if (order == 'a' && (stack->head->value > stack->head->prev->value))
		return ('s');
	if (order == 'd' && (stack->head->value < stack->head->prev->value))
		return ('s');
	return ('r');
}
/*
**	a	->	ascendind
**	d	->	descending
*/

void		make_oper(t_stack	*stack, char com, t_resolve *res)
{
	if (com == 'r')
		ps_rotate(stack, res);
	if (com == 's')
		ps_swap(stack, res);
}

void		change_order(t_stack *a, t_stack *b, t_resolve *res, int goal)
{
	t_elem *elem;
	int	size;

	size = a->size;
	while (a->head->value != goal)
		ps_rotate(a, res);
	while (a->size > 0)
	{
		ps_push(b, a, res);
		ps_rev_rotate(a, res);
	}
	while (size > 0)
	{
		ps_push(a, b, res);
		size--;
	}
}

t_resolve	*my_devide_sort(t_stack *a, t_stack *b, int *goal)
{
	t_resolve	*res;
	char		a_oper;
	char		b_oper;
	int			size;

	res = resolve_ini('d');
	if (!stack_is_sort(a))
		return (res);
	size = a->size;
	devide_stack(a, b, res, goal); //можно разделять в разных направлениях и брать короткое
	a_oper = sort_stack(a, 'a', goal, size);
	b_oper = sort_stack(b, 'd', goal, size);
	while (a_oper != 'o' || b_oper != 'o')
	{
		if (a_oper == 't')
		{
			change_order(a, b, res, goal[size - a->size]);
			a_oper = 'o';
		}
		if (b_oper == 't')
		{
			change_order(a, b, res, goal[size - a->size]);
			a_oper = 'o';
		}
		if (a_oper == 'o' && b_oper != 'o')
			make_oper(b, b_oper, res);
		else if (b_oper == 'o' && a_oper != 'o')
			make_oper(a, a_oper, res);
		else if (a_oper == 's' && a_oper == b_oper)
			ps_dswap(a, b, res);
		else if (a_oper == 'r' && a_oper == b_oper)
			ps_drotate(a, b, res);
		else if (a_oper == 's')
			ps_swap(a, res);
		else
			ps_swap(b, res);
		a_oper = (a_oper == 'o') ? a_oper : sort_stack(a, 'a', goal, size);
		b_oper = (b_oper == 'o') ? b_oper : sort_stack(b, 'd', goal, size);
	}
	while (b->size > 0)
		ps_push(a, b, res);
	return (res);
}
