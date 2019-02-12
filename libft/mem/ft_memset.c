/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:46:53 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/02 22:49:49 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symb;
	char			*str;

	symb = (unsigned char)c;
	str = (char *)b;
	while (len-- > 0)
		*str++ = symb;
	return (b);
}
