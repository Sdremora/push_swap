/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:38:20 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/02 15:15:11 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	while (haystack_len-- >= needle_len)
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
	}
	return (NULL);
}
