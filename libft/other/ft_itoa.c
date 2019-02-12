/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:41 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/03 11:03:03 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(int n)
{
	int sign;

	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	if (n / 10 != 0)
		return (get_size(n / 10) + 1 + sign);
	return (1 + sign);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_size(n);
	result = ft_strnew(size);
	if (result == NULL)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	while (1)
	{
		result[size - 1] = n % 10 * sign + '0';
		if (n / 10 == 0)
			break ;
		size--;
		n = n / 10;
	}
	return (result);
}
