/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:53:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 17:13:54 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SORT_COUNT 2

# include "libft.h"
# include "ps_stack.h"
# include "general.h"

typedef	struct	s_resolve
{
	int		count;
	char	*log_str;
}				t_resolve;

typedef t_resolve *(*funcs)(t_stack *stack_a, t_stack *stack_b, \
							int *sort_array);

t_resolve		*ps_sort(t_stack *stack_a, t_stack *stack_b);

t_resolve		*my_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array);
t_resolve		*quick_sort(t_stack *stack_a, t_stack *stack_b, int *sort_array);

#endif
