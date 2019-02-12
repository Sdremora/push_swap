/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:49:54 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/02 22:19:30 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;

	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		s++;
	if (!*s)
		return (ft_strnew(0));
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	result = ft_strsub(s, 0, i + 1);
	return (result);
}
