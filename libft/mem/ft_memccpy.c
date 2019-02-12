/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:59:22 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/03 12:49:53 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	symb = (unsigned char)c;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	while (n-- > 0)
	{
		*str1 = *str2;
		if (*str1 == symb)
			return (str1 + 1);
		str1++;
		str2++;
	}
	return (0);
}
