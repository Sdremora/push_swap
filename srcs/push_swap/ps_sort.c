/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:42:24 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 18:24:17 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		get_min_solution(t_solution *solution)
// {
// 	int min;
// 	int min_count;
// 	int cur_count;
// 	int i;

// 	min = 0;
// 	min_count = (solution[min]).count;
// 	i = 1;
// 	while (i < SORT_COUNT)
// 	{
// 		cur_count = (solution[i]).count;
// 		if (min_count > cur_count)
// 		{
// 			min = i;
// 			min_count = cur_count;
// 		}
// 		i++;
// 	}
// 	return (min);
// }

static t_resolve	**error_clear(t_resolve **resolve)
{
	int i;

	i = 0;
	while (i < SORT_COUNT)
	{
		ft_free(2, resolve[i]->log_str, resolve[i]);
		i++;
	}
	return (NULL);
}

static t_resolve	**sort_all(t_stack *stack_a, t_stack *stack_b, \
					funcs *sort_func, int *sort_array)
{
	t_resolve	**resolve;
	t_stack		copy;
	int 		i;
	int 		is_error;

	i = 0;
	is_error = 0;
	resolve = (t_resolve **)ft_memalloc( \
					sizeof(t_resolve *) * SORT_COUNT);
	if (resolve == NULL)
		return (NULL);
	while (i < SORT_COUNT && !is_error)
	{
		if (!stack_copy(&copy, stack_a))
			resolve[i] = sort_func[i](&copy, stack_b, sort_array);
		if (resolve[i] == NULL)
			is_error = -1;
		stack_clear(&copy);
		i++;
	}
	if (is_error)
		return (error_clear(resolve));
	return (resolve);
}

t_resolve			*ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_resolve	**resolve;
	funcs		sort_func[SORT_COUNT];
	int			*sort_array;

	sort_array = stack_to_array(stack_a);
	if (sort_array == NULL)
		return (NULL);
	comb_sort(sort_array, stack_a->size);
	sort_func[0] = my_sort;
	sort_func[1] = quick_sort;
	resolve = sort_all(stack_a, stack_b, sort_func, sort_array);

	return (NULL);
}
