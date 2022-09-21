/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:33:54 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/15 12:32:03 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		check_argv(char **arg)
{
	if (ft_strncmp(*arg, "--save", ft_strlen(*arg)) != 0 || ft_strlen(*arg) < 6)
	{
		printf("Invalid argument!\n");
		return (0);
	}
	return (1);
}

void	write_bit_map(int fd, int data, int byte)
{
	write(fd, &data, byte);
}

void	put_bit_map_header(t_game *g, int fd)
{
	int i;

	i = 0;
	write(fd, "BM", 2);
	write_bit_map(fd, g->element.x_size * g->element.y_size + 54, 4);
	write_bit_map(fd, 0, 2);
	write_bit_map(fd, 0, 2);
	write_bit_map(fd, 54, 4);
	write_bit_map(fd, 40, 4);
	write_bit_map(fd, g->element.x_size, 4);
	write_bit_map(fd, g->element.y_size, 4);
	write_bit_map(fd, 1, 2);
	write_bit_map(fd, 32, 2);
	while (i++ < 6)
		write_bit_map(fd, 0, 4);
}

void	put_bit_map(t_game *g)
{
	int	fd;
	int	j;

	make_user(g);
	fd = open("ScreenShot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("File Open Error!\n");
		exit(0);
	}
	put_bit_map_header(g, fd);
	j = g->element.y_size;
	while (--j >= 0)
		write(fd, g->img.data + (g->element.x_size * j), g->element.x_size * 4);
	close(fd);
	exit(0);
}
