/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:12:28 by tredfort          #+#    #+#             */
/*   Updated: 2021/01/14 17:12:31 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# define scale 30 // размер блока на карте
# define moveSpeed 5.0 // размер блока на карте
# define rotSpeed 3.0 // размер блока на карте



typedef struct	s_plr //структура для игрока и луча
{
	double		x;
	double		y;
	double		dir;
	double		start;
	double		end;
}				  t_plr;

typedef struct	s_param //структура для игрока и луча
{
	double		dirx;
	double		diry;
	double		oldDirX;
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;
	double		deltaDistX;
	double		deltaDistY;
}				  t_param;

typedef struct  s_img {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_img;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_list		*lst;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	int			fc;
	int			cc;
	int 		rx;
	int 		ry;
	int 		size;
	int 		errno;
	t_param		x;
	t_plr		plr;
}				t_all;

int			get_next_line(int fd, char **line);
int			ft_revstrncmp(char *s1, char *s2, int n);
int			atoi_bias(char **str);
int			parser(char *str, t_all *s);
int			error_check(t_all s);
int			map_check(t_all *s);
char		*remove_spaces(char *str, char *set);
void		set_player(t_all *s, int x, int y);
int 		move(int keycode, t_all *s);

#endif
