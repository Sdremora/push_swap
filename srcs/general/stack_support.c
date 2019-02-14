/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:45:19 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 10:09:41 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	stack_ini(t_stack *stack)
{
	stack->head = NULL;
	stack->back = NULL;
	stack->size = 0;
}

void	stack_clear(t_stack *stack)
{
	t_elem	*temp;
	t_elem	*prev;

	if (stack == NULL)
		return ;
	temp = stack->head;
	while (temp != NULL)
	{
		prev = temp->prev;
		free(temp);
		temp = prev;
	}
	stack->head = NULL;
	stack->back = NULL;
	stack->size = 0;
}

int		stack_put(t_stack *stack, int value)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (new_elem == NULL)
		return (-1);
	new_elem->prev = stack->head;
	new_elem->value = value;
	stack->head = new_elem;
	if (stack->size == 0)
		stack->back = new_elem;
	(stack->size)++;
	return (0);
}

int		stack_copy(t_stack *copy, t_stack *srcs)
{
	t_elem	*cur_elem;
	t_elem	*new_elem;
	t_elem	*prev_elem;

	stack_ini(copy);
	cur_elem = srcs->head;
	while (cur_elem)
	{
		new_elem = (t_elem *)ft_memalloc(sizeof(t_elem));
		if (new_elem == NULL)
		{
			stack_clear(copy);
			return (-1);
		}
		new_elem->value = cur_elem->value;
		if (copy->head == NULL)
			copy->head = new_elem;
		else
			prev_elem->prev = new_elem;
		prev_elem = new_elem;
		cur_elem = cur_elem->prev;
	}
	copy->back = new_elem;
	copy->size = srcs->size;
	return (0);
}

int		*stack_to_array(const t_stack *stack)
{
	int		*array;
	t_elem	*elem;
	int		i;

	array = (int *)malloc(sizeof(int) * stack->size);
	if (array == NULL)
		return (NULL);
	elem = stack->head;
	i = 0;
	while (elem)
	{
		array[i] = elem->value;
		elem = elem->prev;
		i++;
	}
	return (array);
}
