/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:48:00 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:32:10 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			find_sprite_spot(t_game *g, double angle)
{
	double	spot;

	spot = tan(angle) * g->dist + g->element.x_size / 2;
	return ((int)spot);
}

void		set_sprite_color(t_game *g, int i, int j, int x)
{
	int		h;
	int		y;

	y = g->sprite.height;
	h = g->sprite_img.height / 2;
	g->s_color_down = g->sprite_img.data[(int)
	(i * (g->sprite_img.width / (double)x) +
	(h + (j * h / y) - 1) * g->sprite_img.width)];
	g->s_color_up = g->sprite_img.data[(int)
	(i * (g->sprite_img.width / (double)x) +
	(h - (j * h / y)) * g->sprite_img.width)];
}

void		set_sort_element(t_game *g, int j)
{
	g->sprite.x_1 = g->element.sprite[j][0] - g->user.x;
	g->sprite.x_2 = g->element.sprite[j + 1][0] - g->user.x;
	g->sprite.y_1 = g->element.sprite[j][1] - g->user.y;
	g->sprite.y_2 = g->element.sprite[j + 1][1] - g->user.y;
	g->sprite.dist1 = sqrtf(
		g->sprite.x_1 * g->sprite.x_1 + g->sprite.y_1 * g->sprite.y_1);
	g->sprite.dist2 = sqrtf(
		g->sprite.x_2 * g->sprite.x_2 + g->sprite.y_2 * g->sprite.y_2);
}

void		sort_sprite(t_game *g)
{
	double	temp[2];
	int		i;
	int		j;

	i = -1;
	while (++i < g->element.sprite_len - 1)
	{
		j = i;
		while (j < g->element.sprite_len - 1)
		{
			set_sort_element(g, j);
			if (g->sprite.dist1 < g->sprite.dist2)
			{
				temp[0] = g->sprite.x_1 + g->user.x;
				temp[1] = g->sprite.y_1 + g->user.y;
				g->element.sprite[j][0] = g->sprite.x_2 + g->user.x;
				g->element.sprite[j][1] = g->sprite.y_2 + g->user.y;
				g->element.sprite[j + 1][0] = temp[0];
				g->element.sprite[j + 1][1] = temp[1];
			}
			j++;
		}
	}
}
