/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:45:19 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 12:04:39 by sdremora         ###   ########.fr       */
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
