/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:10:50 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/20 10:09:42 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		check_user(t_game *g)
{
	if (g->user.angle != -1.1)
		print_error("USER ERROR!");
}

void		check_cub_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		print_error("Cub File ERROR!");
	file += (len - 1);
	file -= 3;
	if (ft_strncmp(file, ".cub", 4) != 0)
		print_error("Cub File ERROR!");
}

void		check_argument(t_game *g, int argc, char **argv)
{
	if (argc == 2)
		check_cub_file(argv[1]);
	else if (argc == 3)
	{
		if (check_argv(&argv[2]) == 0)
			exit(0);
		else
			g->save = 1;
	}
	else
		print_error("argument ERROR!");
}

void		map_check(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->element.map_x)
	{
		j = 0;
		while (j < g->element.map_y)
		{
			if (i == 0 || j == 0 ||
			i == g->element.map_x - 1 || j == g->element.map_y - 1)
			{
				if (g->element.map[i][j] == 0)
					print_error("MAP ERROR!");
				if (g->element.map[i][j] == 3 && j == g->element.map_y - 1)
					check_corner(g, i, j);
				if (g->element.map[i][j] > 10)
					print_error("USER ERROR!");
			}
			j++;
		}
		i++;
	}
}

void		blank_check(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->element.map_x)
	{
		j = 0;
		while (j < g->element.map_y)
		{
			if (g->element.map[i][j] != 1 && g->element.map[i][j] != 3)
			{
				if ((i != 0 && g->element.map[i - 1][j] == 3) ||
				(j != g->element.map_y - 1 && g->element.map[i][j + 1] == 3)
				|| (i != g->element.map_x - 1
				&& g->element.map[i + 1][j] == 3)
				|| (j != 0 && g->element.map[i][j - 1] == 3))
					print_error("MAP ERROR!");
			}
			j++;
		}
		i++;
	}
}
