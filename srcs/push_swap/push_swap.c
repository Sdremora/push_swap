/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:43:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 17:03:29 by sdremora         ###   ########.fr       */
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
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (check_input(argc, argv))
		return (error_print());
	if (argc == 2)
		return (0);
	stack = stack_ini(argc, argv);
	if (stack == NULL)
		return (error_print());
	ps_logic(stack);
	return (0);
}