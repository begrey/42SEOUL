/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:38:28 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:32:11 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		set_sprite_element(t_game *g, double sprite_x, double sprite_y)
{
	double	move_left;
	double	move_right;

	move_left = cos(g->user.angle + 90 * (PI / 180)) * (g->sprite.width / 2);
	move_right = sin(g->user.angle + 90 * (PI / 180)) * (g->sprite.width / 2);
	g->sprite.s_x = ((sprite_x - move_left)) - g->user.x;
	g->sprite.s_y = ((sprite_y - move_right)) - g->user.y;
	g->sprite.e_x = ((sprite_x + move_left)) - g->user.x;
	g->sprite.e_y = ((sprite_y + move_right)) - g->user.y;
	g->sprite.s_angle = atan2(g->sprite.s_y, g->sprite.s_x) - g->user.angle;
	g->sprite.e_angle = atan2(g->sprite.e_y, g->sprite.e_x) - g->user.angle;
	if (g->sprite.s_angle - g->sprite.e_angle > PI)
	{
		if (g->sprite.s_angle < 0)
			g->sprite.e_angle += PI * 2;
		else if (g->sprite.s_angle < PI)
			g->sprite.e_angle += PI * 2;
		else if (g->sprite.s_angle > PI)
			g->sprite.s_angle -= PI * 2;
	}
	g->sprite.angle = atan2(g->sprite.m_y, g->sprite.m_x) - g->user.angle;
	g->sprite.dist = sqrtf(g->sprite.m_x * g->sprite.m_x +
	g->sprite.m_y * g->sprite.m_y) * cos(g->sprite.angle);
	g->sprite.height = 1 / (g->sprite.dist / 10) * 50 * g->sprite.width;
}

void		paint_sprite(t_game *g, int start, int end, double middle)
{
	int		j;
	int		z;

	j = start;
	z = 0;
	while (j < end)
	{
		while (z < g->sprite.height)
		{
			if (j >= 0 && j < g->element.x_size &&
			(g->sprite.dist < g->distance[j]))
			{
				set_sprite_color(
					g, j - start, z, end - start);
				if (g->s_color_down != 0x000000 &&
				middle + z < g->element.y_size)
					draw(g, j, middle + z, g->s_color_down);
				if (g->s_color_up != 0x000000 && middle - z > 0)
					draw(g, j, middle - z, g->s_color_up);
			}
			z++;
		}
		z = 0;
		j++;
	}
}

void		make_sprite(t_game *g, double sprite_x, double sprite_y)
{
	g->sprite.m_x = sprite_x - g->user.x;
	g->sprite.m_y = sprite_y - g->user.y;
	if (g->sq_h > g->sq_w)
		g->sprite.width = g->sq_w;
	else
		g->sprite.width = g->sq_h;
	set_sprite_element(g, sprite_x, sprite_y);
	if (g->sprite.height > g->element.y_size)
		g->sprite.height = g->element.y_size;
	paint_sprite(g,
	find_sprite_spot(g, g->sprite.s_angle),
	find_sprite_spot(g, g->sprite.e_angle), g->element.y_size / 2);
}
