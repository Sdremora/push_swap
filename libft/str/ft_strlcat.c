/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:26:23 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/02 17:03:30 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	n;

	n = size;
	len_dst = 0;
	while (*dst != '\0' && n > 0)
	{
		len_dst++;
		dst++;
		n--;
	}
	len_src = ft_strlen(src);
	n = size - len_dst;
	if (n-- != 0)
	{
		while (*src != '\0' && n-- > 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len_dst + len_src);
}
