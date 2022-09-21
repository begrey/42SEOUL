/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:45:12 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/20 10:47:22 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	move_user(t_game *g, int key)
{
	if (key == 1)
	{
		g->x_walk = cos(g->user.angle) * g->user.walk_speed;
		g->y_walk = sin(g->user.angle) * g->user.walk_speed;
	}
	else if (key == 2)
	{
		g->x_walk = -cos(g->user.angle) * g->user.walk_speed;
		g->y_walk = -sin(g->user.angle) * g->user.walk_speed;
	}
	else if (key == 3)
	{
		g->x_walk = cos(g->user.angle - (PI / 2)) * g->user.walk_speed;
		g->y_walk = sin(g->user.angle - (PI / 2)) * g->user.walk_speed;
	}
	else
	{
		g->x_walk = cos(g->user.angle + (PI / 2)) * g->user.walk_speed;
		g->y_walk = sin(g->user.angle + (PI / 2)) * g->user.walk_speed;
	}
}

int		press_event(int key, t_game *g)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		move_user(g, 1);
	else if (key == S)
		move_user(g, 2);
	else if (key == A)
		move_user(g, 3);
	else if (key == D)
		move_user(g, 4);
	else if (key == Q)
		g->rotate = -1 * g->user.turn_speed;
	else if (key == E)
		g->rotate = g->user.turn_speed;
	return (1);
}

int		unpress_event(int key, t_game *g)
{
	if (key == W || key == S || key == A || key == D)
	{
		g->x_walk = 0;
		g->y_walk = 0;
	}
	else if (key == Q || key == E)
		g->rotate = 0;
	return (1);
}

int		mouse_press(t_game *g)
{
	g->save = 0;
	exit(0);
	return (1);
}

void	check_corner(t_game *g, int i, int j)
{
	if (j == g->element.map_y - 1 && i < g->element.map_x - 1)
	{
		if (g->element.map[i + 1][j - 1] == 0 && i == 0 && j > 0)
		{
			print_error("MAP ERROR!");
		}
		if (i > 0 && j > 0 && g->element.map[i - 1][j - 1] == 0)
		{
			print_error("MAP ERROR!");
		}
	}
}
