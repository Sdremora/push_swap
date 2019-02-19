/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:03:51 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 14:38:42 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	end_print(void)
{
	ft_printf("=====\t=====\n"
			"  a  \t  b  \n"
			"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}

void	stack_write(t_stack *a, t_stack *b, char *com)
{
	int		max_size;
	char	*str[2];
	t_elem	*elem_a;
	t_elem	*elem_b;

	max_size = (a->size > b->size) ? a->size : b->size;
	elem_a = a->head;
	elem_b = b->head;
	ft_bzero(str, sizeof(char *) * 2);
	ft_printf("     {yellow}%s{def}\n", com);
	while (max_size > 0)
	{
		if (a->size >= max_size)
		{
			str[0] = ft_itoa(elem_a->value);
			elem_a = elem_a->prev;
		}
		else
			str[0] = " ";
		if (b->size >= max_size)
		{
			str[1] = ft_itoa(elem_b->value);
			elem_b = elem_b->prev;
		}
		else
			str[1] = " ";
		ft_printf("%s\t%s\n", str[0], str[1]);
		max_size--;
	}
	end_print();
}
