/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 14:36:36 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	devide_b(t_stack *a, t_stack *b, t_resolve *res)
{
	int		i;
	int		average;
	int		r_count;

	i = stack_get_average(b, &average);
	i = (b->size % 2 != 0) ? i + 1 : i;
	r_count = 0;
	while (i > 0)
	{
		if (b->head->value >= average)
		{
			ps_push(a, b, res);
			i--;
		}
		else
		{
			ps_rotate(b, res);
			r_count++;
		}
	}
	if (r_count > 0 && b->grade == -1)
	{
		while (r_count-- > 0)
			ps_rev_rotate(b, res);
	}
}

static void	devide_a(t_stack *a, t_stack *b, t_resolve *res)
{
	int		i;
	int		average;
	int		r_count;

	i = stack_get_average(a, &average);
	r_count = 0;
	while (i > 0)
	{
		if (a->head->value < average)
		{
			ps_push(b, a, res);
			i--;
		}
		else
		{
			ps_rotate(a, res);
			r_count++;
		}
	}
	if (r_count > 0 && a->grade == -1)
	{
		while (r_count-- > 0)
			ps_rev_rotate(a, res);
	}
}

static void	ilogic(t_stack *a, t_resolve *res, int rec_count)
{
	t_stack	b;
	t_stack	tricky_a;

	stack_ini(&b, "b");
	b.grade = (rec_count == 1) ? 0 : -1;
	if (a->size > 3)
	{
		devide_a(a, &b, res);
		ilogic(a, res, rec_count + 1);
	}
	else
		simple_sort_a(a, &b, res);
	while (b.size > 3)
	{
		stack_ini(&tricky_a, "a");
		devide_b(&tricky_a, &b, res);
		tricky_a.grade = -1;
		ilogic(&tricky_a, res, rec_count + 1);
		while (tricky_a.size > 0)
		{
			stack_rev_rotate(&tricky_a);
			stack_push(a, &tricky_a);
		}
	}
	simple_sort_b(a, &b, res);
}

/*
**	b->grade = -2 and sort_array[0] = sort_array[0] for -Wextra -Werror
*/

t_resolve	*quick_sort(t_stack *a, t_stack *b, int *sort_array)
{
	t_resolve	*res;
	int			rec_count;

	b->grade = -2;
	sort_array[0] = sort_array[0];
	res = resolve_ini('d');
	if (!stack_is_sort(a))
		return (res);
	rec_count = 1;
	ilogic(a, res, rec_count);
	return (res);
}
