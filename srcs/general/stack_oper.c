/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:58:08 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/13 10:20:29 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

int		stack_push(t_stack *stack)
{
	t_elem	*temp;
	int		value;

	temp = stack->head;
	stack->head = temp->prev;
	stack->size--;
	if (stack->size == 0)
		stack->back = NULL;
	value = temp->value;
	free(temp);
	return (value);
}
