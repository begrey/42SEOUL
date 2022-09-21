/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:42:50 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/22 15:01:42 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		check_color(char *line, t_game *g, char **word)
{
	int		comma;
	char	**color;
	int		i;

	i = 0;
	comma = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		print_error("WRONG COMMA NUM!");
	color = ft_split(line + 1, ',');
	handle_color(g, color, line[0]);
	free_ans(color);
	free_ans(word);
}

void		get_next_word(char *line, t_game *g)
{
	char	**word;
	char	*type;

	word = ft_split(line, ' ');
	type = word[0];
	if (ft_strncmp(type, "F", ft_strlen(type)) == 0 ||
	ft_strncmp(type, "C", ft_strlen(type)) == 0)
	{
		check_color(line, g, word);
		return ;
	}
	seperate_type(g, type, word);
	free_ans(word);
}

void		parse_line(t_game *g, int fd, int fd2, int m)
{
	char	*line;
	char	*line2;

	while (get_next_line(fd, &line) != 0 && get_next_line(fd2, &line2) != 0)
	{
		if (*line != 0)
		{
			if (m < 7)
			{
				get_next_word(line, g);
				free_lines(line, line2);
			}
			else
				break ;
			m++;
		}
		else
			free_lines(line, line2);
	}
	if (line[0] == 0)
		print_error("ERROR!");
	get_next_word(line, g);
	free_lines(line, line2);
	parse_map(g, fd, fd2);
}

void		set_sprite_spot(t_game *g)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = 0;
	g->sq_h = g->element.y_size / (double)g->element.map_x;
	g->sq_w = g->element.x_size / (double)g->element.map_y;
	g->element.sprite = malloc(sizeof(double *) * (g->element.sprite_len + 1));
	g->element.sprite[g->element.sprite_len] = NULL;
	while (++i < g->element.map_x)
	{
		j = -1;
		while (++j < g->element.map_y)
		{
			if (g->element.map[i][j] == 2)
			{
				g->element.sprite[len] = malloc(sizeof(double) * 2);
				g->element.sprite[len][0] = j * g->sq_w + g->sq_w / 2;
				g->element.sprite[len][1] = i * g->sq_h + g->sq_h / 2;
				len++;
			}
		}
	}
}

void		open_file(t_game *g, char *arg)
{
	int		fd;
	int		fd2;

	g->element.map_x = 0;
	g->element.map_y = 0;
	g->element.sprite_len = 0;
	fd = open(arg, O_RDONLY);
	fd2 = open(arg, O_RDONLY);
	if (fd == -1 || fd2 == -1)
		print_error("FD ERROR!");
	parse_line(g, fd, fd2, 0);
	map_check(g);
	blank_check(g);
	set_sprite_spot(g);
	if (g->user.angle == -1.1)
		print_error("NO USER!");
	close(fd);
	close(fd2);
}
