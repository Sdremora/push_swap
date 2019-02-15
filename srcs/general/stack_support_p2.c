/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_support_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:45:19 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 12:33:04 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	stack_ini(t_stack *stack, char *name)
{
	stack->head = NULL;
	stack->size = 0;
	stack->name = name;
}

void	stack_clear(t_stack *stack)
{
	t_elem	*temp;
	t_elem	*next;

	if (stack == NULL)
		return ;
	temp = stack->head;
	while (stack->size > 0)
	{
		next = temp->next;
		free(temp);
		temp = next;
		stack->size--;
	}
	stack->head = NULL;
}

void	stack_copy(t_stack *copy, t_stack *srcs)
{
	t_elem	*cur_elem;
	int		i;

	i = 0;
	cur_elem = srcs->head->next;
	stack_ini(copy, srcs->name);
	while (i < srcs->size)
	{
		stack_put(copy, cur_elem->value);
		cur_elem = cur_elem->next;
		i++;
	}
}

int		*stack_to_array(const t_stack *stack)
{
	int		*array;
	t_elem	*elem;
	int		i;

	array = (int *)ft_memalloc(sizeof(int) * stack->size);
	if (array == NULL)
		memory_error();
	elem = stack->head;
	i = 0;
	while (i < stack->size)
	{
		array[i] = elem->value;
		elem = elem->prev;
		i++;
	}
	return (array);
}