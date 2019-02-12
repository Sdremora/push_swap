/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:54:32 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/06 10:55:02 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (char unsigned *)dst;
	str2 = (char unsigned *)src;
	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
