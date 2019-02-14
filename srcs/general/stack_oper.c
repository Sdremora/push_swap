/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:58:08 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 16:35:41 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

/*
**	Take the first element at the top of stack "out" and put them in stack "in".
**	If stack is empty - do nothing
*/

void	stack_push(t_stack *in, t_stack *out)
{
	t_elem	*elem;

	if (out->size == 0)
		return ;
	elem = out->head;
	out->head = elem->prev;
	out->size--;
	if (out->size == 0)
		out->back = NULL;
	elem->prev = in->head;
	in->head = elem;
	if (in->size == 0)
		in->back = elem;
	in->size++;
}

/*
**	Swap the first 2 elements at the top of stack.
**	If stack.size < 2 - do nothing.
*/

void	stack_swap(t_stack *stack)
{
	t_elem	*first;
	t_elem	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->prev;
	first->prev = second->prev;
	second->prev = first;
	stack->head = second;
	if (stack->size == 2)
		stack->back = first;
}

/*
**	1	->	2
**	2		3
**	3		1
*/

void	stack_rotate(t_stack *stack)
{
	t_elem	*first;

	first = stack->head;
	stack->back->prev = first;
	stack->back = first;
	stack->head = first->prev;
	stack->back->prev = NULL;
}

/*
**	1	->	3
**	2		1
**	3		2
*/

void	stack_rev_rotate(t_stack *stack)
{
	t_elem	*last;

	last = stack->back;
	last->prev = stack->head;
	stack->head = last;
	while (last->prev != stack->back)
		last = last->prev;
	stack->back = last;
	stack->back->prev = NULL;
}
