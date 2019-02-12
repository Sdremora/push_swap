/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:18:00 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/06 11:18:03 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	clear(char ***f, char **buf)
{
	int		i;

	i = *((int *)(*f)[0]);
	while (--i > -1)
		free((*f)[i]);
	free(*f);
	*f = NULL;
	if (**buf)
		free(*buf);
	return (-1);
}

static int	init(char ***f, int d, char **buf)
{
	char	**temp;

	if (!f || !*f)
	{
		if (!(*f = (char **)ft_memalloc(sizeof(char *) * (5 + 1))))
			return (-1);
		(*f)[0] = ft_itoa(5);
	}
	if (!(*buf = ft_memalloc(BUFF_SIZE + 1)))
		return (clear(f, buf));
	if (d >= ft_atoi((*f)[0]))
	{
		if (!(temp = (char **)ft_memalloc(sizeof(char *) * (d + 2))))
			return (clear(f, buf));
		temp = ft_memcpy(temp, *f, sizeof(char *) * (ft_atoi((*f)[0]) + 1));
		free(*f);
		*f = temp;
		free((*f)[0]);
		(*f)[0] = ft_itoa(d + 1);
	}
	return (0);
}

static int	find_line(char ***f, int d, char **buf)
{
	int		nr_bytes_read;
	char	*tmp;

	if (!(*f)[d + 1] || !ft_strchr((*f)[d + 1], '\n'))
	{
		while (!ft_strchr(*buf, '\n'))
		{
			if ((nr_bytes_read = read(d, *buf, BUFF_SIZE)) < 0)
				return (clear(f, buf));
			else if (nr_bytes_read == 0)
				return (0);
			(*buf)[nr_bytes_read] = '\0';
			if ((*f)[d + 1])
			{
				tmp = (*f)[d + 1];
				(*f)[d + 1] = ft_strjoin((*f)[d + 1], *buf);
				free(tmp);
			}
			else if (!((*f)[d + 1] = ft_strdup(*buf)))
				return (clear(f, buf));
		}
	}
	return (1);
}

static int	return_line(char ***f, int d, char **buf, char **l)
{
	char *tmp;

	if ((*f)[++d] && ft_strchr((*f)[d], '\n'))
	{
		if (!(*l = ft_strsub((*f)[d], 0, ft_strchr((*f)[d], '\n') - (*f)[d])))
			return (clear(f, buf));
		tmp = (*f)[d];
		if (!((*f)[d] = ft_strdup(ft_strchr((*f)[d], '\n') + 1)))
			return (clear(f, buf));
		free(tmp);
		return (1);
	}
	else if ((*f)[d])
	{
		if (!(*l = ft_strdup((*f)[d])))
			return (clear(f, buf));
		ft_strdel(&((*f)[d]));
		if (ft_strcmp(*l, "\0") == 0)
			return (0);
		return (1);
	}
	return (0);
}

int			get_next_line(const int d, char **line)
{
	char		*buf;
	static char	**f;
	int			exit_code;
	char		tmp_arr[1];

	if (!line || d < 0 || read(d, tmp_arr, 0) < 0)
		return (-1);
	if (init(&f, d, &buf) < 0)
		return (-1);
	if (find_line(&f, d, &buf) < 0)
	{
		*line = NULL;
		return (-1);
	}
	if ((exit_code = return_line(&f, d, &buf, line)) < 0)
		return (-1);
	free(buf);
	return (exit_code);
}
