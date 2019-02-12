/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:10:37 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/05 12:43:20 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#define FALSE 0
#define TRUE 1

static size_t	count_words(const char *s, char c)
{
	int		flag;
	size_t	word;

	flag = FALSE;
	word = 0;
	while (*s)
	{
		if (*s != c && flag == FALSE)
		{
			word++;
			flag = TRUE;
		}
		if (*s == c && flag == TRUE)
			flag = FALSE;
		s++;
	}
	return (word);
}

static int		found_end(const char *str, char c)
{
	size_t	end;

	end = 1;
	while (str[end] != '\0' && str[end] != c)
		end++;
	return (end);
}

static char		**word_split(char **ar, char const *s, char del, size_t k)
{
	size_t	word_num;
	size_t	offset;
	char	*word;

	word_num = 0;
	while (word_num < k)
	{
		if (*s != del)
		{
			offset = found_end(s, del);
			if ((word = ft_strsub(s, 0, offset)) == NULL)
			{
				while (word_num-- > 0)
					free(ar[word_num]);
				free(ar);
				return (NULL);
			}
			ar[word_num++] = word;
			s += offset;
			continue;
		}
		s++;
	}
	ar[k] = NULL;
	return (ar);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	size_t		k;

	k = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (k + 1));
	if (result == NULL)
		return (NULL);
	result = word_split(result, s, c, k);
	return (result);
}
