/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:38:16 by bsprigga          #+#    #+#             */
/*   Updated: 2018/12/23 14:00:30 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstreverse(t_list **lst)
{
	t_list *current;
	t_list *next;
	t_list *previous;

	previous = *lst;
	if ((current = previous->next) == NULL)
		return ;
	previous->next = NULL;
	while (current->next)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	current->next = previous;
	*lst = current;
}
