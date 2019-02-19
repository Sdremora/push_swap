/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:03:51 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 15:46:01 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	end_print(void)
{
	ft_printf("===========\t===========\n"
			"     {red}a     \t     b{def}     \n"
			"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}

void	print_elem(t_elem **elem_a, t_elem **elem_b)
{
	if (elem_a)
	{
		ft_printf("{green}% 11d{def}\t", (*elem_a)->value);
		*elem_a = (*elem_a)->prev;
	}
	else
		ft_printf("%11c\t", ' ');
	if (elem_b)
	{
		ft_printf("{cyan}% 11d{def}\n", (*elem_b)->value);
		*elem_b = (*elem_b)->prev;
	}
	else
		ft_printf("\n");
}

void	stack_write(t_stack *a, t_stack *b, char *com)
{
	int		max_size;
	t_elem	*elem_a;
	t_elem	*elem_b;

	max_size = (a->size > b->size) ? a->size : b->size;
	elem_a = a->head;
	elem_b = b->head;
	ft_printf("%12c{yellow}%s{def}\n", ' ', com);
	while (max_size > 0)
	{
		if (a->size >= max_size && b->size >= max_size)
			print_elem(&elem_a, &elem_b);
		else if (a->size >= max_size)
			print_elem(&elem_a, NULL);
		else
			print_elem(NULL, &elem_b);
		max_size--;
	}
	end_print();
}
