/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:58:08 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/15 11:57:49 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

/*
**	Take the first element at the top of stack "out" and put them in stack "in".
**	If stack is empty - do nothing
*/

int	stack_push(t_stack *in, t_stack *out)
{
	return (stack_put_elem(in, stack_pop_elem(out)));
}

/*
**	Swap the first 2 elements at the top of stack.
**	If stack.size < 2 - do nothing.
*/

int	stack_swap(t_stack *stack)
{
	t_elem	*first;
	t_elem	*second;

	if (stack->size < 2)
		return (-1);
	first = stack_pop_elem(stack);
	second = stack_pop_elem(stack);
	stack_put_elem(stack, first);
	stack_put_elem(stack, second);
	return (0);
}

/*
**	1	->	2
**	2		3
**	3		1
*/

int	stack_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return (-1);
	stack->head = stack->head->prev;
	return (0);
}

/*
**	1	->	3
**	2		1
**	3		2
*/

int	stack_rev_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return (-1);
	stack->head = stack->head->next;
	return (0);
}
