/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:57:45 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 10:40:45 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

static void	buble_sort(int *data, int size)
{
	int i;
	int is_sort;

	is_sort = -1;
	while (is_sort)
	{
		is_sort = 0;
		i = 0;
		while (i < size - 1)
		{
			if (data[i] > data[i + 1])
			{
				swap(data + i, data + i + 1);
				is_sort = -1;
			}
			i++;
		}
	}
}

void		comb_sort(int *data, int size)
{
	int		i;
	int		step;
	float	fact;

	step = size - 1;
	fact = 1.247f;
	while (step >= 1)
	{
		i = 0;
		while (i + step < size)
		{
			if (data[i] > data[i + step])
				swap(data + i, data + i + step);
			i++;
		}
		step = (int)(step / fact);
	}
	buble_sort(data, size);
}
