/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:22:44 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:32:09 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		set_tile_position(t_game *g, double x, double y)
{
	while (x > g->sq_w)
		x -= g->sq_w;
	while (y > g->sq_h)
		y -= g->sq_h;
	g->w_x = x;
	g->w_y = y;
	g->new_x = g->x;
	g->new_y = g->y;
}

void		reset(t_game *g, int boolean)
{
	set_tile_position(g, g->x, g->y);
	if (boolean == 1)
	{
		if ((int)g->w_x == 0)
			g->new_x = (int)(g->x / g->sq_w) * g->sq_w;
		else
			g->new_x = ((int)(g->x / g->sq_w) + 1) * g->sq_w;
	}
	else
	{
		if ((int)g->w_y == 0)
			g->new_y = (int)(g->y / g->sq_h) * g->sq_h;
		else
			g->new_y = ((int)(g->y / g->sq_h) + 1) * g->sq_h;
	}
}

int			find_position(t_game *g, int i)
{
	if (g->x != g->user.x + (g->move_x * 0.3 * i)
	&& g->element.map[(int)((g->user.y + (g->move_y * 0.3 * i)) / g->sq_h)][
		(int)(g->x / g->sq_w)] == 1)
		return (1);
	else
		return (0);
}

void		ray_cast(t_game *g, double angle)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g->element.x_size)
	{
		angle = atan2(-(g->element.x_size / 2) + i, g->dist);
		g->move_x = cos(angle + g->user.angle);
		g->move_y = sin(angle + g->user.angle);
		j = 1;
		while (1)
		{
			g->x = g->user.x + (g->move_x * 0.3 * j);
			g->y = g->user.y + (g->move_y * 0.3 * j);
			if (g->element.map[
				(int)(g->y / g->sq_h)][(int)(g->x / g->sq_w)] == 1)
			{
				make_wall(g, i, angle, find_position(g, j - 1));
				break ;
			}
			j++;
		}
	}
}

void		make_user(t_game *g)
{
	int		i;
	double	angle;
	double	cos_angle;

	cos_angle = -60 / 2 * PI / 180;
	if (g->user.angle >= PI)
		g->user.angle -= PI * 2;
	angle = g->user.angle;
	ray_cast(g, cos_angle);
	sort_sprite(g);
	i = -1;
	while (++i < g->element.sprite_len)
		make_sprite(g, g->element.sprite[i][0], g->element.sprite[i][1]);
	g->user.angle = angle;
}
