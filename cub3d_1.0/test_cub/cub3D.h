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
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include </usr/local/include/mlx.h>
# define moveSpeed 0.5
# define rotSpeed 0.08



typedef struct	s_param //структура для игрока и луча
{
	int 		h;
	int			w;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		oldDirX;
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		cameraX;
	int 		map[24][24];
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
	t_param		x;
}				t_all;

void		raycasting(t_all *all);

#endif
