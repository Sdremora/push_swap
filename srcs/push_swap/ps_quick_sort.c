/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/18 11:43:35 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_sort_3elem(t_stack *a, t_resolve *res)
{

}

void		tricky_sort_3elem(t_stack *a, t_resolve *res)
{

}

void		tricky_sort_b3elem(t_stack *a, t_stack *b, t_resolve *res)
{
	ps_push(a, b, res);
	ps_push(a, b, res);
	ps_push(a, b, res);
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

void		simple_sort_a(t_stack *a, t_resolve *res)
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
			tricky_sort_3elem(a, res);
	}
}

void		devide_b(t_stack *a, t_stack *b, t_resolve *res)
{
	int 	i;
	int 	size;
	int		average;
	int		r_count;

	average = stack_get_average(b);
	i = 0;
	size = b->size;
	r_count = 0;
	while (i < size) // нужно заранее определить сколько элементов нужно переместить и делать цикл по ним
	{
		if (b->head->value > average)
			ps_push(a, b, res);
		else
		{
			ps_rotate(b, res);
			r_count++;
		}
		i++;
	}
	if (r_count > 0 && b->grade == -1)
	{
		while (r_count-- > 0)
			ps_rev_rotate(b, res);
	}
}

void		devide_a(t_stack *a, t_stack *b, t_resolve *res)
{
	int 	i;
	int		size;
	int		average;
	int		r_count;

	average = stack_get_average(a); //если много больших чисел, то переполнение и беда
	i = 0;
	size = a->size;
	r_count = 0;
	while (i < size) // нужно заранее определить сколько элементов нужно переместить и делать цикл по ним
	{
		if (a->head->value <= average)
			ps_push(b, a, res);
		else
		{
			ps_rotate(a, res);
			r_count++;
		}
		i++;
	}
	if (r_count > 0 && a->grade == -1)
	{
		while (r_count-- > 0)
			ps_rev_rotate(a, res);
	}
}

void		ilogic(t_stack *a, t_resolve *res)
{
	t_stack	b;
	t_stack	tricky_a;

	stack_ini(&b, "b");
	if (a->size > 3)
	{
		devide_a(a, &b, res);
		ilogic(a, res);
	}
	else
		simple_sort_a(a, res);
	while (b.size > 3)
	{
		stack_ini(&tricky_a, "a");
		devide_b(&tricky_a, &b, res);
		tricky_a.grade = -1;
		ilogic(&tricky_a, res);
		while (tricky_a.size > 0)
			stack_push(a, &tricky_a);
	}
	simple_sort_b(a, &b, res);
}

t_resolve	*quick_sort(t_stack *a, t_stack *b, int *sort_array)
{
	t_resolve	*res;
	int			size;

	res = resolve_ini('d');
	if (!stack_is_sort(a))
		return (res);
	ilogic(a, res);
	return (res);
}

