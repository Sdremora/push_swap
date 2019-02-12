/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:44:41 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/28 10:40:27 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_pow(int nb, unsigned int power)
{
	long long int result;

	if (nb == 0)
		return (0);
	result = 1;
	if (power > 0)
		result = nb * ft_pow(nb, power - 1);
	return (result);
}
