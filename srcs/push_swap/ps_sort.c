/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:42:24 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 11:34:40 by sdremora         ###   ########.fr       */
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
	while (resolve[i] != NULL)
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

static t_resolve	**sort_all(t_stack *stack_a, t_stack *stack_b, \
					t_funcs *sort_func, int *sort_array)
{
	t_resolve	**resolve;
	t_stack		copy;
	int			i;

	i = 0;
	resolve = (t_resolve **)ft_memalloc(\
					sizeof(t_resolve *) * 3);
	if (resolve == NULL)
		memory_error();
	while (sort_func[i] != NULL)
	{
		stack_copy(&copy, stack_a);
		resolve[i] = sort_func[i](&copy, stack_b, sort_array);
		stack_clear(&copy);
		i++;
	}
	resolve[i] = NULL;
	return (resolve);
}

t_resolve			*ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_resolve	**resolve;
	t_funcs		sort_func[3];
	int			*sort_array;

	sort_array = stack_to_array(stack_a);
	if (sort_array == NULL)
		memory_error();
	comb_sort(sort_array, stack_a->size);
	sort_func[0] = quick_sort;
	sort_func[1] = (stack_a->size < 1) ? ps_buble_sort : NULL;
	sort_func[2] = NULL;
	resolve = sort_all(stack_a, stack_b, sort_func, sort_array);
	free(sort_array);
	return (get_min_resolve(resolve));
}
