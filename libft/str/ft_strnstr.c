/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:00:56 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/03 11:25:33 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while ((i < needle_len) && (haystack[i] == needle[i]))
				i++;
			if (i == needle_len)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
