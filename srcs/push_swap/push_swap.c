/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:43:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 11:31:51 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_input(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		ft_strlen(argv[i]);
		i++;
	}
	return (0);
}

t_stack *new_stack_elem(int value)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->value = value;
	elem->prev = NULL;
	return (elem);
}

void	clear_stack(t_stack *stack)
{
	t_stack *cur_elem;
	t_stack	*temp;

	cur_elem = stack;
	while (cur_elem != NULL)
	{
		temp = cur_elem->prev;
		free(cur_elem);
		cur_elem = temp;
	}
}

t_stack	*stack_ini(int argc, char **argv)
{
	int i;
	t_stack	*top_elem;
	t_stack	*cur_elem;
	t_stack	*next_elem;

	i = 1;
	top_elem = new_stack_elem(ft_atoi(argv[i++]));
	if (top_elem == NULL)
		return (NULL);
	next_elem = top_elem;
	while (i < argc)
	{
		cur_elem = new_stack_elem(ft_atoi(argv[i]));
		if (cur_elem == NULL)
		{
			clear_stack(top_elem);
			return (NULL);
		}
		next_elem->prev = cur_elem;
		cur_elem = next_elem;
		i++;
	}
	return (top_elem);
}

int		error_print(void)
{
	ft_printf("Error\n");
	return (-1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack;

	if (check_input(argc, argv))
		return (error_print());
	stack = stack_ini(argc, argv);
	if (stack == NULL)
		return (error_print());
	ps_logic(stack);
	return (0);
}