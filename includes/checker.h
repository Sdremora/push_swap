/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 09:33:21 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/19 11:05:09 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# include "libft.h"
# include "ps_stack.h"
# include "general.h"
# include <fcntl.h>

int		handle_commands(t_stack *a, t_stack *b, char *flags);
void	stack_write(t_stack *a, t_stack *b, char *com);

#endif