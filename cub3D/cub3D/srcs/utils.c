/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:32:53 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 14:02:23 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int					ft_atoi_base_2(int len, char *str, int str_base)
{
	int ans;
	int num;
	int base;

	ans = 0;
	num = 1;
	base = 1;
	while (len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
		{
			num = str[len] - '0';
			ans += num * base;
		}
		else if (str[len] >= 'A' && str[len] <= 'F')
		{
			num = str[len] - 'A' + 10;
			ans += num * base;
		}
		base *= str_base;
		len--;
	}
	return (ans);
}

int					ft_atoi_base(char *str, int str_base)
{
	int				len;
	int				ans;

	len = 0;
	while (str[len] != '\0')
		len++;
	len = len - 1;
	ans = ft_atoi_base_2(len, str, str_base);
	free(str);
	return (ans);
}

int					ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (i < num && *p1 != '\0' && *p2 != '\0')
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	if (i == num)
		return (0);
	else if (*p1 != '\0' || *p2 != '\0')
		return (*p1 - *p2);
	return (0);
}

int					ft_atoi(const char *str)
{
	long long		minus;
	long long		total;

	minus = 1;
	total = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (*str != '\0' && (*str >= '0' && *str <= '9'))
		total += *str++ - '0';
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if (minus == 1 && total > 2147483647)
			return (-1);
		if (minus == -1 && total > 2147483648)
			return (0);
		total *= 10;
		total += *str++ - '0';
	}
	return ((int)(total * minus));
}

char				*ft_strchr(const char *str, int c)
{
	char			*p;

	p = (char *)str;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (NULL);
}
