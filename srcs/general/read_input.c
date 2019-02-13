/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:46:05 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 12:03:53 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	count_arg(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static void	strar_clear(char **strar)
{
	int i;

	i = 0;
	while (strar[i])
	{
		free(strar[i]);
		i++;
	}
	free(strar);
}

static int	clear_all(t_stack *stack, char **args)
{
	stack_clear(stack);
	strar_clear(args);
	return (-1);
}

int			read_input(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		n;
	char	**args;
	char	*arg;

	i = argc - 1;
	while (i >= 1)
	{
		args = ft_strsplit(argv[i], ' ');
		n = count_arg(args);
		while (n > 0)
		{
			arg = args[n - 1];
			if (check_input(arg, stack_a))
				return (clear_all(stack_a, args));
			if (stack_put(stack_a, ft_atoi(arg)))
				return (clear_all(stack_a, args));
			n--;
		}
		strar_clear(args);
		i--;
	}
	return (0);
}
