/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:07:20 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/21 11:35:34 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	set_size(t_game *g)
{
	if (g->element.x_size < 200)
		g->element.x_size = 250;
	if (g->element.y_size < 200)
		g->element.y_size = 250;
}

int		is_size_num(char *size)
{
	while (*size != 0)
	{
		if (*size < '0' || *size > '9')
			return (-1);
		size++;
	}
	return (1);
}

void	handle_size(t_game *g, char **word)
{
	int size_x;
	int size_y;

	mlx_get_screen_size(g->mlx, &size_x, &size_y);
	if (word[3] != NULL || word[2] == NULL)
		print_error("WRONG SIZE NUM!");
	if (word[1][0] == '-' || word[2][0] == '-')
		print_error("MINUS MAP SIZE!");
	if (is_size_num(word[1]) == -1 || is_size_num(word[2]) == -1)
		print_error("WRONG MAP SIZE INPUT!");
	g->element.x_size = ft_atoi(word[1]);
	g->element.y_size = ft_atoi(word[2]);
	if (g->element.x_size <= 1 || g->element.y_size <= 1)
		print_error("MAP SIZE ERROR!");
	set_size(g);
	if (g->element.x_size > size_x || g->element.x_size == -1)
		g->element.x_size = size_x;
	if (g->element.y_size > size_y || g->element.y_size == -1)
		g->element.y_size = size_y;
}

char	*handle_texture(char **word)
{
	char	*texture;

	if (word[1] == NULL)
		print_error("WRONG TEXTURE NUM!");
	if (word[2] != NULL)
		print_error("WRONG TEXTURE NUM!");
	texture = ft_strdup(word[1]);
	return (texture);
}

void	seperate_type(t_game *g, char *type, char **word)
{
	if (ft_strncmp(type, "R", ft_strlen("R")) == 0)
		handle_size(g, word);
	else if (ft_strncmp(type, "NO", ft_strlen("NO")) == 0)
		g->element.n_texture = handle_texture(word);
	else if (ft_strncmp(type, "SO", ft_strlen("SO")) == 0)
		g->element.s_texture = handle_texture(word);
	else if (ft_strncmp(type, "S", ft_strlen("S")) == 0)
		g->element.sp_texture = handle_texture(word);
	else if (ft_strncmp(type, "WE", ft_strlen("WE")) == 0)
		g->element.w_texture = handle_texture(word);
	else if (ft_strncmp(type, "EA", ft_strlen("EA")) == 0)
		g->element.e_texture = handle_texture(word);
	else
		print_error("WRONG TYPE!");
}
