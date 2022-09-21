/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:51:15 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/20 07:36:06 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		get_row_and_col(char *line, t_game *g)
{
	g->element.map_x += 1;
	if (g->element.map_y < (int)ft_strlen(line))
		g->element.map_y = (int)ft_strlen(line);
}

int			get_map_2(t_game *g, char *line, int i)
{
	int		j;

	j = -1;
	while (line[++j] != '\0')
	{
		if (line[j] == ' ')
			g->element.map[i][j] = 3;
		else if (line[j] >= '0' && line[j] <= '2')
		{
			if (line[j] == '2')
				g->element.sprite_len++;
			g->element.map[i][j] = line[j] - '0';
		}
		else if (line[j] == 'N' || line[j] == 'W'
		|| line[j] == 'E' || line[j] == 'S')
		{
			g->user.x = j + 1;
			g->user.y = i + 1;
			check_user(g);
			g->user.angle = line[j];
		}
		else
			print_error("WRONG MAP INPUT!");
	}
	return (j);
}

void		get_map(char *line, t_game *g, int i)
{
	int		j;

	g->element.map[i] = malloc(sizeof(int) * g->element.map_y);
	j = get_map_2(g, line, i);
	while (j < g->element.map_y)
	{
		if (g->element.map[i][j - 1] == 0)
			print_error("MAP ERROR!");
		g->element.map[i][j] = 3;
		j++;
	}
}

void		parse_map_2(t_game *g, int i, int fd2, int j)
{
	char	*line2;
	int		ret;

	if (g->element.map_x >= g->element.map_y)
		g->element.map_y = g->element.map_x;
	else
		g->element.map_x = g->element.map_y;
	g->element.map = malloc(sizeof(int *) * g->element.map_x);
	while ((ret = get_next_line(fd2, &line2)) != -1)
	{
		if (*line2 != 0)
			get_map(line2, g, i++);
		free(line2);
		if (ret == 0)
			break ;
	}
	while (i < g->element.map_y)
	{
		g->element.map[i] = malloc(sizeof(int) * g->element.map_y);
		while (j < g->element.map_y)
			g->element.map[i][j++] = 3;
		i++;
		j = 0;
	}
}

void		parse_map(t_game *g, int fd, int fd2)
{
	char	*line;
	int		i;
	int		ret;
	int		map_line;

	i = 0;
	map_line = 0;
	while ((ret = get_next_line(fd, &line)) != -1)
	{
		if (*line != 0)
		{
			get_row_and_col(line, g);
			if (map_line == -1)
				print_error("Map Line ERROR!");
			else
				map_line = 1;
		}
		if (*line == 0 && map_line == 1)
			map_line = -1;
		free(line);
		if (ret == 0)
			break ;
	}
	parse_map_2(g, i, fd2, 0);
}
