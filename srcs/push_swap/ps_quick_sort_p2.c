/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:33:06 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/18 14:06:13 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	'1'	->	swap_a
**	'2'	->	swap_b
**	'3'	->	push_a
**	'4'	->	push_b
**	'5'	->	rotate_a
**	'6'	->	rotate_b
**	'7'	->	rev_rotate_a
**	'8'	->	rev_rotate_b
*/

static void	tricky_sort_3elem(t_stack *a, t_stack *b, t_resolve *res)
{
	int	*arr;
	int	max_i;
	int	med_i;

	arr = stack_to_array(a);
	if (arr == NULL)
		memory_error();
	found_maxmed(arr, &max_i, &med_i);
	if (max_i == 0 && med_i == 1)
		ps_stack_combine("14131", a, b, res);
	else if (max_i == 0 && med_i == 2)
		ps_stack_combine("1413", a, b, res);
	else if (max_i == 1 && med_i == 0)
		ps_stack_combine("4141", a, b, res);
	else if (max_i == 2 && med_i == 0)
		ps_stack_combine("1", a, b, res);
	else if (max_i == 1 && med_i == 2)
		ps_stack_combine("413", a, b, res);
	free(arr);
}

static void	tricky_sort_b3elem(t_stack *a, t_stack *b, t_resolve *res)
{
	int	*arr;
	int	max_i;
	int	med_i;

	arr = stack_to_array(a);
	if (arr == NULL)
		memory_error();
	found_maxmed(arr, &max_i, &med_i);
	if (max_i == 0 && med_i == 1)
		ps_stack_combine("333", a, b, res);
	else if (max_i == 0 && med_i == 2)
		ps_stack_combine("3233", a, b, res);
	else if (max_i == 1 && med_i == 0)
		ps_stack_combine("3313", a, b, res);
	else if (max_i == 2 && med_i == 0)
		ps_stack_combine("32313", a, b, res);
	else if (max_i == 1 && med_i == 2)
		ps_stack_combine("23233", a, b, res);
	else if (max_i == 2 && med_i == 1)
		ps_stack_combine("232313", a, b, res);
	free(arr);
}

void		simple_sort_b(t_stack *a, t_stack *b, t_resolve *res)
{
	if (b->size == 1)
		ps_push(a, b, res);
	else if (b->size == 2)
	{
		if (b->head->value < b->head->prev->value)
			ps_swap(b, res);
		ps_push(a, b, res);
		ps_push(a, b, res);
	}
	else if (b->size == 3)
			tricky_sort_b3elem(a, b, res);
}

void		simple_sort_a(t_stack *a, t_stack *b, t_resolve *res)
{
	if (a->size == 2)
	{
		if (a->head->value > a->head->prev->value)
			ps_swap(a, res);
	}
	else if (a->size == 3)
	{
		if (a->grade == 0)
			ps_sort_3elem(a, res);
		else
			tricky_sort_3elem(a, b, res);
	}
}
