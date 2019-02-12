/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_attach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:41:31 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/24 16:42:36 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Содаем новый элемент списка и кидаем в него контент
*/

t_list	*ft_lst_attach(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = (void *)content;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
