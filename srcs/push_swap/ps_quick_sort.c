/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/17 17:46:57 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return index in array or -1 if not exist
*/

static int			is_exist(int value, int *arr, int size)
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

static int			devide_stack(t_stack *a, t_stack *b, t_resolve *res, t_goal goal)
{
	int		i;
	int		rev_count;
	t_elem	*cur_elem;

	i = goal.len;
	rev_count = 0;
	while (i > 0)
	{
		cur_elem = a->head;
		if (is_exist(cur_elem->value, goal.arr + goal.start, goal.len) >= 0)
		{
			ps_push(b, a, res);
			i--;
		}
		else
		{
			ps_rotate(a, res);
			rev_count++;
		}
	}
	while (rev_count > 0)
		ps_rev_rotate(a, res);
	return (res->count);
}

static void		swap(t_stack *a, t_resolve *res)
{
	if (a->size == 2)
	{
		if (a->head->value > a->head->prev->value)
			ps_swap(a, res);
	}
}

static void		sort(t_stack *a, t_stack *b, t_goal goal, t_resolve *res)
{
	int	size;
	int	size_b;
	int	dif;

	size = a->size;
	size_b = b->size;
	if (goal.len <= 2)
		swap(a, res);
	else
	{
		goal.len = goal.len / 2;
		devide_stack(a, b, res, goal);
		goal.start = goal.len;
		sort(a, b, goal, res);
	}
	dif = b->size - size_b;
	if (dif <= 2 && dif != 0)
	{
		while (dif-- > 0)
			ps_push(a, b, res);
		swap(a, res);
	}
	else
	{
		goal.len = b->size;
		goal.start = b->size;
		while (b->size > 0)
			ps_push(a, b, res);
		sort(a, b, goal, res);
	}




}


t_resolve	*quick_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array)
{
	t_resolve	*res;
	int			size;
	t_goal		goal;

	res = resolve_ini('d');
	if (!stack_is_sort(stack_a))
		return (res);
	goal.arr = sort_array;
	goal.len = stack_a->size;
	goal.start = 0;
	sort(stack_a, stack_b, goal, res);
	return (res);
}



// t_resolve	*quick_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array)
// {
// 	t_resolve	*resolve;

// 	if (!stack_a || !stack_b || !sort_array)
// 		return (NULL);
// 	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
// 	if (resolve == NULL)
// 		return (NULL);
// 	resolve->index = '2';
// 	resolve->count = 99999999;
// 	resolve->log_str = ft_strdup("quick sort");
// 	return (resolve);
// }
