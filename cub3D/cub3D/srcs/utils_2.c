/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:41:42 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:51:37 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

static char	*get_word(char *s, int len)
{
	char	*p;
	char	*word;
	char	*word_p;

	if ((word = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	word_p = word;
	p = s;
	while (len != 0)
	{
		*word++ = *p++;
		len--;
	}
	*word = '\0';
	return (word_p);
}

static int	word_len(char *s, char c)
{
	int		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	count_len(char *s, char c)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (len);
}

char		**free_ans(char **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL)
		free(a[i++]);
	free(a);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**word;
	char	**ans;
	char	*ptr;

	ptr = (char *)s;
	if ((word = (char**)malloc(sizeof(char *) *
(count_len((char *)s, c) + 1))) == NULL)
		return (NULL);
	ans = word;
	while (ptr != NULL && *ptr != '\0')
	{
		if (*ptr != c)
		{
			if ((*word = get_word(ptr, word_len(ptr, c))) == NULL)
				return (free_ans(ans));
			word++;
			ptr = ft_strchr(ptr, c);
		}
		else
			ptr++;
	}
	*word = NULL;
	return (ans);
}
