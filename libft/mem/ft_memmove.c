/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:05:13 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/02 19:15:53 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	if (s1 < s2)
	{
		while (len-- > 0)
			*s1++ = *s2++;
	}
	if (s1 > s2)
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	return (dst);
}
