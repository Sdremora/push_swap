/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:53:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 10:29:12 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

enum			e_oper
{
	SWAP_A = '1',
	SWAP_B,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	R_ROTATE_A,
	R_ROTATE_B,
};

typedef t_resolve *(*t_funcs)(t_stack *stack_a, t_stack *stack_b, \
							int *sort_array);

t_resolve		*ps_sort(t_stack *stack_a, t_stack *stack_b);
int				ps_log(t_resolve *resolve, char *oper);

t_resolve		*ps_buble_sort(t_stack *a, t_stack *b, int *goal);
t_resolve		*quick_sort(t_stack *stack_a, t_stack *stack_b, int *goal);
void			simple_sort_a(t_stack *a, t_stack *b, t_resolve *res);
void			simple_sort_b(t_stack *a, t_stack *b, t_resolve *res);
void			ps_sort_3elem(t_stack *a, t_resolve *res);
void			found_maxmed(int *arr, int *max, int *med);
void			ps_stack_combine(char *format, t_stack *a,\
								t_stack *b, t_resolve *res);
int				ps_push(t_stack *in, t_stack *out, t_resolve *resolve);
int				ps_swap(t_stack *stack, t_resolve *resolve);
int				ps_dswap(t_stack *s1, t_stack *s2, t_resolve *resolve);
int				ps_rotate(t_stack *stack, t_resolve *resolve);
int				ps_drotate(t_stack *s1, t_stack *s2, t_resolve *resolve);
int				ps_rev_rotate(t_stack *stack, t_resolve *resolve);
int				ps_drev_rotate(t_stack *s1, t_stack *s2, t_resolve *resolve);

t_resolve		*resolve_ini(char index);
#endif
