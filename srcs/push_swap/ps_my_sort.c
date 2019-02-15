/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 12:35:36 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /*
// **	0 	-> 	sorted
// **	-1	->	not sorted
// */

// int			is_sort(t_stack	*stack, int *goal)
// {
// 	int		i;
// 	t_elem	*cur_elem;

// 	cur_elem = stack->head;
// 	i = 0;
// 	while (cur_elem->prev != NULL)
// 	{
// 		if (cur_elem->value != goal[i])
// 			return (-1);
// 		cur_elem = cur_elem->prev;
// 		i++;
// 	}
// 	return (0);
// }

// void		make_sort(t_stack *a, t_stack *b, int *goal, t_resolve *resolve)
// {
// 	int	t1;
// 	int t2;
// 	int	i;
// 	int len;

// 	len = a->size;
// 	i = 0;
// 	while (i < len)
// 	{

// 		i++;
// 	}
// }

// t_resolve	*my_sort(t_stack *stack_a, t_stack *stack_b, int *goal)
// {
// 	t_resolve	*resolve;
// 	int			i;

// 	if (!stack_a || !stack_b || !goal)
// 		return (NULL);
// 	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
// 	if (resolve == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (is_sort(stack_a, goal))
// 	{
// 		make_sort(stack_a, stack_b, goal, resolve);

// 	}
// 	return (resolve);
// }


t_resolve	*my_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array)
{
	t_resolve	*resolve;

	if (!stack_a || !stack_b || !sort_array)
		return (NULL);
	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (resolve == NULL)
		return (NULL);
	resolve->count = 10;
	resolve->log_str = ft_strdup("my sort");
	return (resolve);
}