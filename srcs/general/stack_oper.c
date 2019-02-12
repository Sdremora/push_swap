/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:58:08 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 17:08:15 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	oper_swap(t_stack *top_elem)
{
	int temp;

	if (top_elem == NULL || (top_elem)->prev == NULL)
		return ;
	temp = top_elem->value;
	top_elem->value = top_elem->prev->value;
	top_elem->prev->value = temp;
}

void	oper_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack *temp;

	top_a = *stack_a;
	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	temp->prev = top_a;
	(*stack_a) = temp;
	(*stack_b) = (*stack_b)->prev;
}

void	oper_rotate(t_stack	**stack)
{

}