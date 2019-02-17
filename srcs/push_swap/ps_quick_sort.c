/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 18:00:32 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		re_sort(t_sort_set *set)
{
	t_sort_set	new_set;

	new_set = *set;
	// if (set->end > 3)
	// {
	// 	new_set->end
	// }
}

t_resolve	*quick_sort2(t_stack *stack_a, t_stack *stack_b, int *sort_array)
{
	t_resolve	*resolve;
	t_sort_set	set;

	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (resolve == NULL)
		memory_error();

	set.a = stack_a;
	set.b = stack_b;
	set.goal = sort_array;
	set.goal = sort_array;
	set.resolve = resolve;
	set.end = set.a->size;
	re_sort(&set);
	return (resolve);
}

t_resolve	*quick_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array)
{
	t_resolve	*resolve;

	if (!stack_a || !stack_b || !sort_array)
		return (NULL);
	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (resolve == NULL)
		return (NULL);
	resolve->index = '2';
	resolve->count = 99999999;
	resolve->log_str = ft_strdup("quick sort");
	return (resolve);
}
