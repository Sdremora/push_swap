/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_log_r_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:55:28 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:12:27 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_dswap(t_stack *s1, t_stack *s2, t_resolve *resolve)
{
	char buf[3];

	stack_swap(s1);
	stack_swap(s2);
	ft_bzero(buf, 3);
	ft_strcat(buf, "ss");
	resolve->count++;
	return (ps_log(resolve, buf));
}

int	ps_drotate(t_stack *s1, t_stack *s2, t_resolve *resolve)
{
	char buf[3];

	stack_rotate(s1);
	stack_rotate(s2);
	ft_bzero(buf, 3);
	ft_strcat(buf, "rr");
	resolve->count++;
	return (ps_log(resolve, buf));
}

int	ps_drev_rotate(t_stack *s1, t_stack *s2, t_resolve *resolve)
{
	char buf[4];

	stack_rev_rotate(s1);
	stack_rev_rotate(s2);
	ft_bzero(buf, 4);
	ft_strcat(buf, "rrr");
	resolve->count++;
	return (ps_log(resolve, buf));
}
