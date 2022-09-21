/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:33:01 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:40:34 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		paint_color2(t_game *g, int i, int position)
{
	int		h;

	h = g->wall_e.height / 2;
	if (position == 3)
	{
		g->color_a = g->wall_s.data[(int)((g->wall_s.width
		- (g->w_x * (g->wall_s.width / (double)(g->sq_w))))
		+ (h - (int)(i * h / (g->ratio))) * g->wall_s.width - 1)];
		g->color_b = g->wall_s.data[(int)((g->wall_s.width
		- (g->w_x * (g->wall_s.width / (double)(g->sq_w))))
		+ (h + (int)(i * h / (g->ratio))) * g->wall_s.width - 1)];
	}
	else
	{
		g->color_a = g->wall_n.data[(int)((g->w_x *
		(g->wall_n.width / (double)(g->sq_w)))
		+ (h - (int)(i * h / (g->ratio))) * g->wall_n.width)];
		g->color_b = g->wall_n.data[(int)((g->w_x *
		(g->wall_n.width / (double)(g->sq_w)))
		+ (h + (int)(i * h / (g->ratio))) * g->wall_n.width)];
	}
}

void		paint_color(t_game *g, int i, int position)
{
	int		h;

	h = g->wall_e.height / 2;
	if (position == 1)
	{
		g->color_a = g->wall_e.data[(int)((g->w_y * (g->wall_e.width) / (double)
		(g->sq_h)) + (h - (int)(i * h / (g->ratio))) * g->wall_e.width)];
		g->color_b = g->wall_e.data[(int)((g->w_y * (g->wall_e.width) / (double)
		(g->sq_h)) + (h + (int)(i * h / (g->ratio))) * g->wall_e.width)];
	}
	else if (position == 2)
	{
		g->color_a = g->wall_w.data[(int)((g->wall_w.width
		- (g->w_y * (g->wall_w.width / (double)(g->sq_h))))
		+ (h - (int)(i * h / (g->ratio))) * g->wall_w.width - 1)];
		g->color_b = g->wall_w.data[(int)((g->wall_w.width
		- (g->w_y * (g->wall_w.width / (double)(g->sq_h))))
		+ (h + (int)(i * h / (g->ratio))) * g->wall_w.width - 1)];
	}
	else
		paint_color2(g, i, position);
}

void		paint_wall(t_game *g, int i, int boolean)
{
	set_tile_position(g, g->x, g->y);
	if (boolean == 1)
	{
		if ((int)g->w_x == 0)
			paint_color(g, i, 1);
		else
			paint_color(g, i, 2);
	}
	else
	{
		if ((int)g->w_y == 0)
			paint_color(g, i, 3);
		else
			paint_color(g, i, 4);
	}
}

void		draw_wall(t_game *g, int x, double middle, int boolean)
{
	int		i;

	i = 0;
	while (i < g->element.y_size / 2)
	{
		if (i < g->ratio)
		{
			paint_wall(g, i, boolean);
			draw(g, x, middle + i, g->color_b);
			draw(g, x, middle - i, g->color_a);
		}
		else
		{
			draw(g, x, middle + i, g->element.c_color);
			draw(g, x, middle - i, g->element.f_color);
		}
		i++;
	}
}

void		make_wall(t_game *g, int num, double angle, int boolean)
{
	double	dist;
	double	ray_x;
	double	ray_y;
	double	ratio;

	reset(g, boolean);
	ray_x = g->new_x - g->user.x;
	ray_y = g->new_y - g->user.y;
	angle = atan2(ray_y, ray_x) - g->user.angle;
	dist = sqrtf(ray_x * ray_x + ray_y * ray_y) * cos(angle);
	dist -= 0.8;
	if (g->sq_h > g->sq_w)
		ratio = g->sq_w;
	else
		ratio = g->sq_h;
	g->ratio = 1 / (dist / 10) * ratio * 50;
	g->distance[num] = dist;
	draw_wall(g, num, g->element.y_size / 2, boolean);
}
