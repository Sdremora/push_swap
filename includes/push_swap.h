/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:53:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 16:56:44 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SORT_COUNT 3

# include "libft.h"
# include "ps_stack.h"
# include "general.h"

typedef	struct	s_resolve
{
	int		count;
	char	*log_str;
	size_t	log_len;
	size_t	log_max_len;
	char	index;
}				t_resolve;

typedef struct	s_sort_set
{
	t_stack	*a;
	t_stack	*b;
	int		*goal;
	int		*end;
	char	*resolve;
}				t_sort_set;


typedef t_resolve *(*t_funcs)(t_stack *stack_a, t_stack *stack_b, \
							int *sort_array);

t_resolve		*ps_sort(t_stack *stack_a, t_stack *stack_b);
int				ps_log(t_resolve *resolve, char *oper);

t_resolve		*ps_buble_sort(t_stack *a, t_stack *b, int *goal);
t_resolve		*my_sort(t_stack *stack_a, t_stack *stack_b, int *goal);
t_resolve		*quick_sort(t_stack *stack_a, t_stack *stack_b, int *goal);

int				ps_push(t_stack *in, t_stack *out, t_resolve *resolve);
int				ps_swap(t_stack *stack, t_resolve *resolve);
int				ps_dswap(t_stack *s1, t_stack *s2, t_resolve *resolve);
int				ps_rotate(t_stack *stack, t_resolve *resolve);
int				ps_drotate(t_stack *s1, t_stack *s2, t_resolve *resolve);
int				ps_rev_rotate(t_stack *stack, t_resolve *resolve);
int				ps_drev_rotate(t_stack *s1, t_stack *s2, t_resolve *resolve);

#endif
