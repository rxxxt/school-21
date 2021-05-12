/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:12:28 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 18:57:49 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

# define MOVE_SPEED  0.15
# define ROT_SPEED 0.07
# define DELTA 0.15

typedef struct	s_dpoint {
	double		x;
	double		y;
}				t_dpoint;

typedef struct	s_sprite {
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_ipoint {
	int			x;
	int			y;
}				t_ipoint;

typedef struct	s_move {
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
	int			rotation_left:1;
	int			rotation_right:1;
}				t_move;

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img[6];
	t_dpoint	plr;
	t_dpoint	dir;
	t_dpoint	plane;
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	t_dpoint	ray_dir;
	t_dpoint	transform;
	t_move		move;
	t_ipoint	pos_map;
	t_ipoint	step;
	t_ipoint	texture;
	t_sprite	*sprite;
	double		perp_wall_dist;
	int			width;
	int			height;
	int			side;
	int			line_height;
	t_ipoint	draw_start;
	t_ipoint	draw_end;
	int			map_size;
	int			floor;
	int			ceilling;
	int			save;
	int			sprite_count;
	double		inv_det;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;

}				t_all;

int				ray_casting(t_all *all);
int				get_next_line(int fd, char **line);
void			parse(t_all *all, t_list *lst);
void			exit_failure(int error);
void			map_check(t_all *all, int x, int y);
int				params_are_set(t_all *all);
void			set_player(t_all *all, int x, int y);
void			init_cube(char *file, int save);
void			init_params(t_all *all);
void			rotation(t_all *all);
void			step_forward(t_all *all);
void			step_back(t_all *all);
void			step_left(t_all *all);
void			step_right(t_all *all);
int				close_window(void);
int				keydown(int keycode, t_all *all);
int				keyup(int keycode, t_all *all);
void			movement(t_all *all);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				get_color_texture(t_all *all, t_img img);
void			set_resolution(char *line, t_all *all);
void			set_texture(char *file, t_all *all, t_img *img);
void			set_color(char *str, int *color);
void			set_player(t_all *all, int x, int y);
void			create_map(t_all *all, t_list *lst, t_list *tmp);
void			fill_in_header(t_all *all, unsigned char **bitmap);
void			fill_in_body(t_all *all, unsigned char **bitmap);
void			take_screenshot(t_all *all);
void			initial_parameters(t_all *all, int x);
void			wall_search(t_all *all);
void			height_of_walls(t_all *all, double *buffer, int x);
void			position_x_in_texture(t_all *all);
void			pixel_put_to_img(t_all *all, int x, int y);
void			set_sprite(t_all *all);
void			sort_sprites(t_all *all);
void			draw_sprites(t_all *all, double *buffer, int i);
void			loops(t_all all);

#endif
