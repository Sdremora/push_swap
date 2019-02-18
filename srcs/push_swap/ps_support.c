/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 09:40:04 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/17 10:16:33 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_resolve *resolve_ini(char index)
{
	t_resolve *resolve;

	resolve = (t_resolve *)malloc(sizeof(t_resolve));
	if (resolve == NULL)
		memory_error();
	resolve->count = 0;
	resolve->log_len = 0;
	resolve->log_max_len = 50;
	resolve->log_str = (char *)ft_memalloc(resolve->log_max_len);
	if (resolve->log_str == NULL)
		memory_error();
	resolve->index = index;
	return (resolve);
}
