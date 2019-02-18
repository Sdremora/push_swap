/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_support_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:36:17 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/18 12:15:10 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

t_elem	*stack_pop_elem(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*next;
	t_elem	*prev;

	if (stack->size == 0)
		return (NULL);
	elem = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		next = elem->next;
		prev = elem->prev;
		next->prev = prev;
		prev->next = next;
		stack->head = prev;
	}
	elem->next = NULL;
	elem->prev = NULL;
	stack->size--;
	return (elem);
}

int		stack_put_elem(t_stack *stack, t_elem *new_elem)
{
	t_elem	*temp;

	if (new_elem == NULL)
		return (-1);
	if (stack->size == 0)
	{
		stack->head = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		temp = stack->head->next;
		stack->head->next = new_elem;
		temp->prev = new_elem;
		new_elem->prev = stack->head;
		new_elem->next = temp;
		stack->head = new_elem;
	}
	(stack->size)++;
	return (0);
}

int		stack_put(t_stack *stack, int value)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)ft_memalloc(sizeof(t_elem));
	if (new_elem == NULL)
		memory_error();
	new_elem->value = value;
	return (stack_put_elem(stack, new_elem));
}

int		stack_get_average(t_stack *stack, int *average)
{
	int			i;
	int			*arr;

	arr = stack_to_array(stack);
	comb_sort(arr, stack->size);
	i = stack->size / 2;
	*average = arr[i];
	free(arr);
	return (i);
}
