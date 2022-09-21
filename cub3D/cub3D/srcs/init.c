/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:55:38 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/22 15:02:37 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_user(t_game *g)
{
	if (g->element.x_size == -1 || g->element.y_size == -1)
		print_error("WRONG MAP INPUT");
	g->sq_h = g->element.y_size / (double)g->element.map_x;
	g->sq_w = g->element.x_size / (double)g->element.map_y;
	g->distance = malloc(sizeof(double) * g->element.x_size);
	g->user.x = g->sq_w * g->user.x - g->sq_w / 2;
	g->user.y = g->sq_h * g->user.y - g->sq_h / 2;
	g->user.turn_d = 0;
	g->user.walk_d = 0;
	if ((int)g->user.angle == 69)
		g->user.angle = 0;
	else if ((int)g->user.angle == 87)
		g->user.angle = PI;
	else if ((int)g->user.angle == 83)
		g->user.angle = PI / 2;
	else
		g->user.angle = PI * 3 / 2;
	g->user.walk_speed = 7;
	g->user.turn_speed = 5 * (PI / 180);
	g->x_walk = 0;
	g->y_walk = 0;
	g->new_x = 0;
	g->new_y = 0;
	g->rotate = 0;
	g->dist = (g->element.x_size / 2) / (tan(30 * PI / 180));
}

void	*load_image(t_game *g, char *texture, int *h, int *w)
{
	void *img;

	img = mlx_xpm_file_to_image(g->mlx, texture, h, w);
	if (img == 0)
		print_error("file ERROR!");
	return (img);
}

void	init_texture(t_game *g)
{
	g->wall_e.img = load_image(
		g, g->element.e_texture, &g->wall_e.height, &g->wall_e.width);
	g->wall_n.img = load_image(
		g, g->element.n_texture, &g->wall_n.height, &g->wall_n.width);
	g->wall_s.img = load_image(
		g, g->element.s_texture, &g->wall_s.height, &g->wall_s.width);
	g->wall_w.img = load_image(
		g, g->element.w_texture, &g->wall_w.height, &g->wall_w.width);
	g->sprite_img.img = load_image(
		g, g->element.sp_texture, &g->sprite_img.height, &g->sprite_img.width);
	g->wall_e.data = (int *)mlx_get_data_addr(
		g->wall_e.img, &g->wall_e.bpp, &g->wall_e.size_l, &g->wall_e.endian);
	g->wall_n.data = (int *)mlx_get_data_addr(
		g->wall_n.img, &g->wall_n.bpp, &g->wall_n.size_l, &g->wall_n.endian);
	g->wall_s.data = (int *)mlx_get_data_addr(
		g->wall_s.img, &g->wall_s.bpp, &g->wall_s.size_l, &g->wall_s.endian);
	g->wall_w.data = (int *)mlx_get_data_addr(
		g->wall_w.img, &g->wall_w.bpp, &g->wall_w.size_l, &g->wall_w.endian);
	g->sprite_img.data = (int *)mlx_get_data_addr(
		g->sprite_img.img, &g->sprite_img.bpp,
		&g->sprite_img.size_l, &g->sprite_img.endian);
}

void	print_error(char *message)
{
	printf("error\n%s\n", message);
	exit(0);
}

void	free_lines(char *line, char *line2)
{
	free(line);
	free(line2);
}
