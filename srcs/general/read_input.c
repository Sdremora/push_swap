/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:46:05 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 11:23:48 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int		count_arg(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static int	clear_stack(t_stack *stack)
{
	stack_clear(stack);
	return (-1);
}

int		read_input(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		n;
	char	**args;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		args = ft_strsplit(argv[i], ' ');
		n = count_arg(args);
		while (n > 0)
		{
			arg = args[n - 1];
			if (check_input(arg, stack_a))
				return (clear_stack(stack_a));
			if (stack_put(stack_a, ft_atoi(arg)))
				return (clear_stack(stack_a));
			n--;
		}
		i++;
	}
	return (0);
}