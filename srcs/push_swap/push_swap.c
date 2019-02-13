/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:43:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 10:38:20 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_print(void)
{
	ft_printf("Error\n");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	stack_ini(&stack_a);
	stack_ini(&stack_b);
	if (read_input(&stack_a, argc, argv))
		return (error_print());
	ps_logic(&stack_a, &stack_b);
	return (0);
}