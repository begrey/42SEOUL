/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimkwon <jimkwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:54 by jimkwon           #+#    #+#             */
/*   Updated: 2021/04/22 15:02:02 by jimkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../../mlx/mlx.h"
# include "../../mlx_mms/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PI 3.1415926535
# define KEYPRESS 2
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 123
# define E 124
# define USER 10
# define RAY_ANGLE 60

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_user
{
	double		x;
	double		y;
	double		angle;
	double		turn_speed;
	int			turn_d;
	int			walk_d;
	int			walk_speed;
}				t_user;

typedef struct	s_element
{
	double		sprite_x;
	double		**sprite;
	char		*n_texture;
	char		*s_texture;
	char		*e_texture;
	char		*w_texture;
	char		*sp_texture;
	int			sprite_len;
	int			y_size;
	int			x_size;
	int			f_color;
	int			c_color;
	int			map_x;
	int			map_y;
	int			**map;
}				t_element;

typedef struct	s_sprite
{
	double		dist1;
	double		dist2;
	double		x_1;
	double		x_2;
	double		y_1;
	double		y_2;
	double		angle;
	double		s_angle;
	double		e_angle;
	double		m_x;
	double		m_y;
	double		s_x;
	double		s_y;
	double		e_x;
	double		e_y;
	double		height;
	double		width;
	double		dist;
}				t_sprite;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	double		*distance;
	double		x_walk;
	double		y_walk;
	double		rotate;
	double		x;
	double		y;
	double		w_x;
	double		w_y;
	double		new_x;
	double		new_y;
	double		move_x;
	double		move_y;
	double		ratio;
	double		sq_h;
	double		sq_w;
	double		tile_x;
	double		tile_y;
	double		dist;
	int			save;
	int			color_a;
	int			color_b;
	int			s_color_up;
	int			s_color_down;
	t_img		img;
	t_img		wall_n;
	t_img		wall_s;
	t_img		wall_e;
	t_img		wall_w;
	t_img		sprite_img;
	t_user		user;
	t_element	element;
	t_sprite	sprite;
}				t_game;

char			**ft_split(char const *s, char c);
char			**free_ans(char **a);
char			*is_in_newline(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(char *s);
char			*ft_strdup(char *s);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				get_next_line(int fd, char **line);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
int				ft_atoi_base(char *str, int str_base);
int				ft_atoi(const char *str);
int				split_new_line(char **line, char **prev, char *index);
int				return_status(char **line, char **prev, char *index);
int				check_argv(char **arg);
int				find_sprite_spot(t_game *g, double angle);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				press_event(int key, t_game *g);
int				mouse_press(t_game *g);
int				unpress_event(int key, t_game *g);
void			get_next_word(char *line, t_game *g);
void			get_row_and_col(char *line, t_game *g);
void			get_map(char *line, t_game *g, int i);
void			open_file(t_game *g, char *arg);
void			parse_line(t_game *g, int fd, int fd2, int m);
void			parse_map(t_game *g, int fd, int fd2);
void			init_wall(t_game *g);
void			init_user(t_game *g);
void			init_texture(t_game *g);
void			print_error(char *message);
void			put_bit_map(t_game *g);
void			seperate_type(t_game *g, char *type, char **word);
void			handle_color(t_game *g, char **color, char type);
void			map_check(t_game *g);
void			blank_check(t_game *g);
void			make_user(t_game *g);
void			sort_sprite(t_game *g);
void			set_sprite_element(t_game *g, double sprite_x, double sprite_y);
void			make_sprite(t_game *g, double sprite_x, double sprite_y);
void			draw(t_game *g, int x, int y, int color);
void			set_sprite_color(t_game *g, int i, int j, int x);
void			make_wall(t_game *g, int num, double angle, int boolean);
void			set_tile_position(t_game *g, double x, double y);
void			reset(t_game *g, int boolean);
void			check_argument(t_game *g, int argc, char **argv);
void			paint_color2(t_game *g, int i, int position);
void			move_user(t_game *g, int key);
void			free_lines(char *line, char *line2);
void			check_user(t_game *g);
void			check_corner(t_game *g, int i, int j);
#endif
