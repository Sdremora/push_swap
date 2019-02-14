/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_log_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:36:17 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:04:38 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define BUF_SIZE 4

int	ps_push(t_stack *in, t_stack *out, t_resolve *resolve)
{
	char buf[BUF_SIZE];

	stack_push(in, out);
	ft_bzero(buf, BUF_SIZE);
	ft_strcat(buf, "p");
	ft_strncat(buf, in->name, 1);
	return (ps_log(resolve, buf));
}

int	ps_swap(t_stack *stack, t_resolve *resolve)
{
	char buf[BUF_SIZE];

	stack_swap(stack);
	ft_bzero(buf, BUF_SIZE);
	ft_strcat(buf, "s");
	ft_strncat(buf, stack->name, 1);
	return (ps_log(resolve, buf));
}

int	ps_rotate(t_stack *stack, t_resolve *resolve)
{
	char buf[BUF_SIZE];

	stack_rotate(stack);
	ft_bzero(buf, BUF_SIZE);
	ft_strcat(buf, "r");
	ft_strncat(buf, stack->name, 1);
	return (ps_log(resolve, buf));
}

int	ps_rev_rotate(t_stack *stack, t_resolve *resolve)
{
	char buf[BUF_SIZE];

	stack_rev_rotate(stack);
	ft_bzero(buf, BUF_SIZE);
	ft_strcat(buf, "rr");
	ft_strncat(buf, stack->name, 1);
	return (ps_log(resolve, buf));
}
