/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:43:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:13:26 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_print(void)
{
	ft_printf("Error\n");
	return (-1);
}

static void	print_resolve(t_resolve *resolve)
{
	ft_printf("%s\n", resolve->log_str);
	ft_printf("n = %d\n", resolve->count);
}

int			main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_resolve	*resolve;

	if (argc == 1)
		return (0);
	stack_ini(&stack_a, "a");
	stack_ini(&stack_b, "b");
	if (read_input(&stack_a, argc, argv))
		return (error_print());
	resolve = ps_sort(&stack_a, &stack_b);
	if (resolve == NULL)
		return (error_print());
	print_resolve(resolve);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	ft_free(2, &resolve->log_str, &resolve);
	return (0);
}
