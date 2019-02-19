/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:43:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 16:03:17 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	error_clear(t_stack *a, t_stack *b)
{
	stack_clear(a);
	stack_clear(b);
	ft_printf("Error\n");
	return (-1);
}

void		check_flags(char *flags, int *argc, char ***argv)
{
	if (*argc < 3)
		return ;
	if (!ft_strcmp((*argv)[1], "-v"))
	{
		flags[0] = 'v';
		(*argc)--;
		(*argv)++;
	}
}

int			main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		flags[2];

	if (argc == 1)
		return (0);
	ft_bzero(flags, 2);
	stack_ini(&stack_a, "a");
	stack_ini(&stack_b, "b");
	check_flags(flags, &argc, &argv);
	if (read_input(&stack_a, argc, argv) ||
		handle_commands(&stack_a, &stack_b, flags))
		return (error_clear(&stack_a, &stack_b));
	if (!stack_is_sort(&stack_a) && stack_b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
