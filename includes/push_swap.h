/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:53:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 12:08:49 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SORT_COUNT 2

# include "libft.h"
# include "ps_stack.h"
# include "general.h"

typedef	struct	s_solution
{
	int		count;
	char	*log_str;
}				t_solution;

void			ps_logic(t_stack *stack_a, t_stack *stack_b);

#endif
