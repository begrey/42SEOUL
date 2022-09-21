/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:47:04 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/22 10:34:42 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		draw(t_game *g, int x, int y, int color)
{
	g->img.data[x + y * g->element.x_size] = color;
}

int			main_loop(t_game *g)
{
	if ((g->element.map[(int)((g->user.y + g->y_walk * 2) / g->sq_h)][(int)
	((g->user.x) / g->sq_w)]) != 1 &&
		(g->element.map[(int)((g->user.y) / g->sq_h)][(int)
		((g->user.x + g->x_walk * 2) / g->sq_w)]) != 1 &&
		(g->element.map[(int)((g->user.y + g->y_walk * 2) / g->sq_h)][(int)
		((g->user.x) / g->sq_w)]) != 2 &&
		(g->element.map[(int)((g->user.y) / g->sq_h)][(int)
		((g->user.x + g->x_walk * 2) / g->sq_w)]) != 2)
	{
		g->user.x += g->x_walk;
		g->user.y += g->y_walk;
	}
	g->user.angle += g->rotate;
	if (g->user.angle > PI * 2)
		g->user.angle -= PI * 2;
	if (g->user.angle < 0)
		g->user.angle += PI * 2;
	make_user(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_game	game;

	check_argument(&game, argc, argv);
	game.element.x_size = -1;
	game.element.y_size = -1;
	game.user.angle = -1.1;
	open_file(&game, argv[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
		game.mlx, game.element.x_size, game.element.y_size, "jimkwon");
	game.img.img = mlx_new_image(
		game.mlx, game.element.x_size, game.element.y_size);
	init_user(&game);
	init_texture(&game);
	game.img.data = (int *)mlx_get_data_addr(
		game.img.img, &game.img.bpp, &game.img.size_l, &game.img.endian);
	if (game.save == 1)
		put_bit_map(&game);
	mlx_hook(game.win, 3, 0, &unpress_event, &game);
	mlx_hook(game.win, KEYPRESS, 0, &press_event, &game);
	mlx_hook(game.win, 17, 0, &mouse_press, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
