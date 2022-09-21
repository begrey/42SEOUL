/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:31:21 by sunmin            #+#    #+#             */
/*   Updated: 2021/06/03 15:44:37 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_joinfree2(char **s1, char **s2)
{
	char	*str;

	str = ft_strjoin(*s1, *s2);
	free(*s1);
	free(*s2);
	return (str);
}

char	*str_append2(char *s1, char *s2)
{
	char	*str;

	str = ft_joinfree2(&s1, &s2);
	return (str);
}

char	*str_append3(char *s1, char c)
{
	char	*s;
	char	*str;
	int		new_len;
	int		i;

	s = (char *)s1;
	new_len = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	str[new_len] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	return (str);
}

int		is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		is_dollar(char c)
{
	if (c == '$')
		return (1);
	return (0);
}
