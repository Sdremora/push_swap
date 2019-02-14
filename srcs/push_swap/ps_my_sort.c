/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:03:29 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_resolve	*my_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array)
{
	t_resolve	*resolve;

	if (!stack_a || !stack_b || !sort_array)
		return (NULL);
	resolve = (t_resolve *)ft_memalloc(sizeof(t_resolve));
	if (resolve == NULL)
		return (NULL);
	ps_push(stack_b, stack_a, resolve);
	ps_push(stack_b, stack_a, resolve);
	ps_push(stack_b, stack_a, resolve);
	ps_push(stack_a, stack_b, resolve);
	ps_push(stack_a, stack_b, resolve);
	ps_rotate(stack_a, resolve);
	ps_rev_rotate(stack_a, resolve);
	ps_swap(stack_a, resolve);
	ps_dswap(stack_a, stack_b, resolve);
	ps_drotate(stack_a, stack_b, resolve);
	ps_drev_rotate(stack_a, stack_b, resolve);
	resolve->count = 1;
	return (resolve);
}
