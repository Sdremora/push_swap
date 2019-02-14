/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:42:24 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 18:05:08 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_resolve	*get_min_resolve(t_resolve **resolve)
{
	int			i;
	t_resolve	*min_resolve;
	t_resolve	*temp;

	if (!resolve)
		return (NULL);
	min_resolve = resolve[0];
	i = 1;
	while (i < SORT_COUNT)
	{
		if (min_resolve->count > resolve[i]->count)
		{
			temp = resolve[i];
			resolve[i] = min_resolve;
			min_resolve = temp;
		}
		ft_free(2, &resolve[i]->log_str, &resolve[i]);
		i++;
	}
	free(resolve);
	return (min_resolve);
}

static t_resolve	**error_clear(t_resolve **resolve)
{
	int i;

	i = 0;
	while (i < SORT_COUNT)
	{
		if (resolve[i])
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
	int			i;
	int			is_error;

	i = 0;
	is_error = 0;
	resolve = (t_resolve **)ft_memalloc(\
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
	free(sort_array);
	return (get_min_resolve(resolve));
}
