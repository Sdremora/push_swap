/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:14 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 10:38:07 by sdremora         ###   ########.fr       */
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
	resolve->count = 19;
	resolve->log_str = ft_strdup("my sort");
	return (resolve);
}
