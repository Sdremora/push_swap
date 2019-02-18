/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:36:09 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/18 14:37:11 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_combine(char *format, t_stack *a, t_stack *b, t_resolve *res)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(format);
	while (i < len)
	{
		if (format[i] == SWAP_A)
			ps_swap(a, res);
		else if (format[i] == SWAP_B)
			ps_swap(b, res);
		else if (format[i] == PUSH_A)
			ps_push(a, b, res);
		else if (format[i] == PUSH_B)
			ps_push(b, a, res);
		else if (format[i] == ROTATE_A)
			ps_rotate(a, res);
		else if (format[i] == ROTATE_B)
			ps_rotate(b, res);
		else if (format[i] == R_ROTATE_A)
			ps_rev_rotate(a, res);
		else if (format[i] == R_ROTATE_B)
			ps_rev_rotate(b, res);
		i++;
	}
}

void	found_maxmed(int *arr, int *max, int *med)
{
	if (arr[0] > arr[1] && arr[0] > arr[2])
	{
		*max = 0;
		*med = (arr[1] > arr[2]) ? 1 : 2;
	}
	if (arr[1] > arr[0] && arr[1] > arr[2])
	{
		*max = 1;
		*med = (arr[0] > arr[2]) ? 0 : 2;
	}
	if (arr[2] > arr[0] && arr[2] > arr[1])
	{
		*max = 2;
		*med = (arr[0] > arr[1]) ? 0 : 1;
	}
}

void		ps_sort_3elem(t_stack *a, t_resolve *res)
{
	int	*arr;
	int	max_i;
	int	med_i;

	arr = stack_to_array(a);
	if (arr == NULL)
		memory_error();
	found_maxmed(arr, &max_i, &med_i);
	if (max_i == 0 && med_i == 1)
	{
		ps_rotate(a, res);
		ps_swap(a, res);
	}
	if (max_i == 0 && med_i == 2)
		ps_rotate(a, res);
	if (max_i == 1 && med_i == 0)
		ps_rev_rotate(a, res);
	if (max_i == 2 && med_i == 0)
		ps_swap(a, res);
	if (max_i == 1 && med_i == 2)
	{
		ps_swap(a, res);
		ps_rotate(a, res);
	}
	free(arr);
}
