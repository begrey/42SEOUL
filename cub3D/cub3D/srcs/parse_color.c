/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:07:59 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/22 14:47:49 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

char		*make_hex(int n)
{
	char	*hex;
	char	major;
	char	minor;

	if (!(hex = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	major = n / 16 + '0';
	minor = n % 16 + '0';
	if (major > 57)
		major += 7;
	if (minor > 57)
		minor += 7;
	hex[0] = major;
	hex[1] = minor;
	hex[2] = '\0';
	return (hex);
}

int			rgb_to_hex(int *color)
{
	char	*r;
	char	*g;
	char	*b;
	char	*hex;
	char	*hex_temp;

	r = make_hex(color[0]);
	g = make_hex(color[1]);
	b = make_hex(color[2]);
	hex_temp = ft_strjoin(r, g);
	hex = ft_strjoin(hex_temp, b);
	free(r);
	free(g);
	free(b);
	free(hex_temp);
	return (ft_atoi_base(hex, 16));
}

void		is_in_num(char **color, int i)
{
	int		j;
	int		flag;

	j = 0;
	flag = 0;
	while (color[i][j] != '\0')
	{
		if (color[i][j] >= '0' && color[i][j] <= '9')
		{
			flag = 1;
			break ;
		}
		j++;
	}
	if (flag == 0)
		print_error("COLOR NUM ERROR!");
}

void		handle_color(t_game *g, char **color, char type)
{
	int		i;
	int		j;
	int		c[3];

	i = 0;
	j = 0;
	if (color[2] == NULL)
		print_error("WRONG COLOR NUM!");
	while (i < 3)
	{
		is_in_num(color, i);
		if (color[i][0] == ' ' && color[i][1] == 0)
			print_error("WRONG COLOR INPUT!");
		if (ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
			print_error("WRONG COLOR INPUT!");
		c[j] = ft_atoi(color[i]);
		i++;
		j++;
	}
	if (type == 'F')
		g->element.c_color = rgb_to_hex(c);
	else
		g->element.f_color = rgb_to_hex(c);
}
