/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:41:17 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/03 20:40:08 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static void	del(void *lst, size_t size)
{
	free(lst);
	size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*firs_new_el;
	t_list	*new_elem;
	t_list	*cur_elem;

	firs_new_el = NULL;
	while (lst)
	{
		new_elem = f(lst);
		if (new_elem == NULL)
		{
			if (firs_new_el != NULL)
				ft_lstdel(&firs_new_el, del);
			return (NULL);
		}
		if (firs_new_el == NULL)
		{
			firs_new_el = new_elem;
			cur_elem = new_elem;
		}
		cur_elem->next = new_elem;
		cur_elem = new_elem;
		lst = lst->next;
	}
	return (firs_new_el);
}
