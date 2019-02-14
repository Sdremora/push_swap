/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:32:00 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:03:56 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	re_str(t_resolve *resolve)
{
	size_t	new_max;
	char	*log_str;

	if (resolve->log_max_len == 0)
		new_max = 50;
	else
		new_max = (size_t)(resolve->log_max_len * 1.247);
	log_str = (char *)ft_memalloc(new_max + 1);
	if (log_str == NULL)
		return (-1);
	if (resolve->log_str)
		ft_strcat(log_str, resolve->log_str);
	free(resolve->log_str);
	resolve->log_str = log_str;
	resolve->log_max_len = new_max;
	return (0);
}

int			ps_log(t_resolve *resolve, char *oper)
{
	int		len;

	len = ft_strlen(oper);
	if (len + resolve->log_len + 1 > resolve->log_max_len)
	{
		if (re_str(resolve))
			return (-1);
	}
	if (resolve->log_len != 0)
	{
		ft_strcat(resolve->log_str, "\n");
		resolve->log_len++;
	}
	ft_strcat(resolve->log_str, oper);
	resolve->log_len += len;
	return (0);
}
