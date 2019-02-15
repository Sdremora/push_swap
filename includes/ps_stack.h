/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:53:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 10:13:21 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include "libft.h"

typedef struct	s_elem
{
	int				value;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

typedef	struct	s_stack
{
	t_elem	*head;
	t_elem	*back;
	int		size;
	char	*name;
}				t_stack;

void			stack_ini(t_stack *stack, char *name);
void			stack_clear(t_stack *stack);
int				stack_put(t_stack *stack, int value);
int				stack_copy(t_stack *copy, t_stack *srcs);
int				*stack_to_array(const t_stack *stack);

void			stack_push(t_stack *in, t_stack *out);
void			stack_swap(t_stack *stack);
void			stack_rotate(t_stack *stack);
void			stack_rev_rotate(t_stack *stack);
#endif
