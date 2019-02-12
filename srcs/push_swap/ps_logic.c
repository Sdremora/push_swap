/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:42:24 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/12 12:10:13 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	first_sort(t_stack stack_a)
{
	t_solution	solution;

	solution.count = 2;
	solution.log_str = "sa\npb\n";
	stack_a.prev = NULL;
	return (solution);
}

t_solution	second_sort(t_stack stack_a)
{
	t_solution	solution;

	solution.count = 4;
	solution.log_str = "sa\npb\npb\npb\n";
	stack_a.prev = NULL;
	return (solution);
}

int		get_min_solution(t_solution *solution)
{
	int min;
	int min_count;
	int cur_count;
	int i;

	min = 0;
	min_count = (solution[min]).count;
	i = 1;
	while (i < SORT_COUNT)
	{
		cur_count = (solution[i]).count;
		if (min_count > cur_count)
		{
			min = i;
			min_count = cur_count;
		}
		i++;
	}
	return (min);
}

void	print_solution(t_solution *solution)
{
	ft_printf("%s", solution->log_str);
}

void	ps_logic(t_stack *stack_a)
{
	t_solution	solution[SORT_COUNT];
	int min;

	solution[0] = first_sort(*stack_a);
	solution[1] = second_sort(*stack_a);
	min = get_min_solution(solution);
	print_solution(&(solution[min]));
}
