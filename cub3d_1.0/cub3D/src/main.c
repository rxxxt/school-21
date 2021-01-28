/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:42:42 by tredfort          #+#    #+#             */
/*   Updated: 2021/01/16 19:42:46 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>
#include <math.h>

char	*remove_spaces(char *str, char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int		atoi_bias(char **str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*(*str) && ((*(*str) >= '\t' && *(*str) <= '\r') || *(*str) == ' '))
		(*str)++;
	if (*(*str) == '-')
		sign = -1;
	if (*(*str) == '-' || *(*str) == '+')
		(*str)++;
	while (*(*str) && ft_isdigit(*(*str)))
		nb = nb * 10 + *(*str)++ - '0';
	return (sign * nb);
}

void            my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_map(t_all *s, t_list *lst, t_list *tmp, int size)
{
	int 	i;
	int 	len;
	int 	max_len;

	max_len = 0;
	while (tmp)
	{
		if (max_len < (len = ft_strlen(tmp->content)))
			max_len = len;
		tmp = tmp->next;
	}
	if (!(s->map = (char **)ft_calloc(sizeof(char *), size + 1)))
		s->errno = -10;
	i = 0;
	while (lst && !s->errno)
	{
		if (!(s->map[i] = ft_substr(lst->content, 0, max_len)))
			s->errno = -10;
		if ((len = ft_strlen(s->map[i])) < max_len)
			ft_memset(s->map[i] + len, ' ', max_len - len);
		i++;
		lst = lst->next;
	}
}

void	mlx_square_put(t_all *s, int x, int y, int color)
{
	int	nx;
	int ny;

	ny = y;
	while (ny++ < y + scale)
	{
		nx = x;
		while (nx++ < x + scale)
			my_mlx_pixel_put(&s->img, nx, ny, color);
	}
}

//void	cast_ray(t_all *s)
//{
//	t_plr	ray = s->plr; // задаем координаты луча равные координатам игрока
//
//	ray.x *= scale;
//	ray.y *= scale;
//	while (s->map[(int)(ray.y / scale)][(int)(ray.x / scale)] != '1')
//	{
//		ray.x += cos(ray.dir);
//		ray.y += sin(ray.dir);
//		printf("%f\n", ray.dir);
//		my_mlx_pixel_put(&s->img, ray.x, ray.y, 0x990099);
//	}
//}

void	cast_rays(t_all *s)
{
	double	overview = 90 * M_PI / 180;		//угол обзора
	t_plr	ray = s->plr; // задаем координаты и направление луча равные
	// координатам игрока
	ray.start = ray.dir - overview / 2; // начало веера лучей
	ray.end = ray.dir + overview / 2; // край веера лучей
	ray.x *= scale;
	ray.y *= scale;
	while (ray.start <= ray.end)
	{
		ray.x = s->plr.x * scale; // каждый раз возвращаемся в точку начала
		ray.y = s->plr.y * scale;
		while (s->map[(int)(ray.y / scale)][(int)(ray.x / scale)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			my_mlx_pixel_put(&s->img, ray.x, ray.y, 0x990099);
		}
		ray.start += overview / 60;
	}
}

void	output_plr(t_all *s)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y < s->size)
	{
		x = -1;
		while (s->map[y][++x])
		{
			if ((int)s->plr.x == x && (int)s->plr.y == y)
				mlx_square_put(s, x * scale, y * scale, 0x00FF00);
		}
	}
}

void	init_mlx(t_all *s)
{
	s->img.img = mlx_new_image(s->mlx, s->rx, s->ry);
	s->img.addr = mlx_get_data_addr(s->img.img, &s->img.bits_per_pixel,
									&s->img.line_length, &s->img.endian);
}

void	output(t_all *s)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y < s->size)
	{
		x = -1;
		while (s->map[y][++x])
		{
			if (s->map[y][x] == '1')
				mlx_square_put(s, x * scale, y * scale, 0xFFFFFF);
			else if (s->map[y][x] == '2')
				mlx_square_put(s, x * scale, y * scale, 0xFF0000);
		}
	}
	output_plr(s);
	cast_rays(s);
	mlx_hook(s->win, 2, 0L, move, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	mlx_loop(s->mlx);
}

int 	ft_move(int keycode, t_all *s)
{
	if (keycode == 13)
	{
		if (s->map[(int)(s->plr.x + s->x.dirx * moveSpeed)][(int)(s->plr.y)] == '0')
			s->plr.x += s->x.dirx * moveSpeed;
		if (s->map[(int)(s->plr.x)][(int)(s->plr.y + s->x.diry * moveSpeed)] == '0')
			s->plr.y += s->x.diry * moveSpeed;
	}
	if (keycode == 1)
	{
		if (s->map[(int)(s->plr.x - s->x.dirx * moveSpeed)][(int)(s->plr.y)] == '0')
			s->plr.x -= s->x.dirx * moveSpeed;
		if (s->map[(int)(s->plr.x)][(int)(s->plr.y - s->x.diry * moveSpeed)] == '0')
			s->plr.y -= s->x.diry * moveSpeed;
	}
	if (keycode == 2)
	{
		s->x.oldDirX = s->x.dirx;
		s->x.dirx = s->x.dirx * cos(-rotSpeed) - s->x.diry * sin(-rotSpeed);
		s->x.diry = s->x.oldDirX * sin(-rotSpeed) + s->x.diry * cos(-rotSpeed);
		s->x.oldPlaneX = s->x.planeX;
		s->x.planeX = s->x.planeX * cos(-rotSpeed) - s->x.planeY * sin(-rotSpeed);
		s->x.planeY = s->x.oldPlaneX * sin(-rotSpeed) + s->x.planeY * cos(-rotSpeed);
	}
	if (keycode == 0)
	{
		s->x.oldDirX = s->x.dirx;
		s->x.dirx = s->x.dirx * cos(rotSpeed) - s->x.diry * sin(rotSpeed);
		s->x.diry = s->x.oldDirX * sin(rotSpeed) + s->x.diry * cos(rotSpeed);
		s->x.oldPlaneX = s->x.planeX;
		s->x.planeX = s->x.planeX * cos(rotSpeed) - s->x.planeY * sin(rotSpeed);
		s->x.planeY = s->x.oldPlaneX * sin(rotSpeed) + s->x.planeY * cos(rotSpeed);
	}
	return (0);
}

void	raycasting(t_all *s)
{
	int 	x = 0;
	while (x < s->rx)
	{
		s->x.cameraX = 2 * x / (double)s->rx - 1;
		s->x.rayDirX = s->x.dirx + s->x.planeX * s->x.cameraX;
		s->x.rayDirY = s->x.diry + s->x.planeY * s->x.cameraX;
		s->x.mapX = s->plr.x;
		s->x.mapY = s->plr.y;
		s->x.hit = 0;
		s->x.deltaDistX = (!s->x.rayDirY) ? 0 : ((!s->x.rayDirX) ? 1 :
				fabs(1 / s->x.rayDirX));
		s->x.deltaDistY = (!s->x.rayDirX) ? 0 : ((!s->x.rayDirY) ? 1 :
				fabs(1 / s->x.rayDirY));
		if (s->x.rayDirX < 0)
		{
			s->x.stepX = -1;
			s->x.sideDistX = (s->plr.x - s->x.mapX) * s->x.deltaDistX;
		} else
		{
			s->x.stepX = 1;
			s->x.sideDistX = (s->x.mapX + 1.0 - s->plr.x) * s->x.deltaDistX;
		}
		if (s->x.rayDirY < 0)
		{
			s->x.stepY = -1;
			s->x.sideDistY = (s->plr.y - s->x.mapY) * s->x.deltaDistY;
		} else
		{
			s->x.stepY = 1;
			s->x.sideDistY = (s->x.mapY + 1.0 - s->plr.y) * s->x.deltaDistY;
		}
		while (!s->x.hit)
		{
			if (s->x.sideDistX < s->x.sideDistY)
			{
				s->x.sideDistX += s->x.deltaDistX;
				s->x.mapX += s->x.stepX;
				s->x.side = 0;
			} else
			{
				s->x.sideDistY += s->x.deltaDistY;
				s->x.mapY += s->x.stepY;
				s->x.side = 1;
			}
			if (s->map[s->x.mapX][s->x.mapY] > 0)
				s->x.hit = 1;
		}
		if (!s->x.side)
			s->x.perpWallDist = (s->x.mapX - s->plr.x + (1.0 - s->x.stepX) / 2) / s->x.rayDirX;
		else
			s->x.perpWallDist = (s->x.mapY - s->plr.y + (1.0 - s->x.stepY) / 2) / s->x.rayDirY;
		s->x.lineHeight = (int)(s->ry / s->x.perpWallDist);
		s->x.drawStart = -s->x.lineHeight / 2 + s->ry / 2;
		if (s->x.drawStart < 0)
			s->x.drawStart = 0;
		s->x.drawEnd = s->x.lineHeight / 2 + s->ry / 2;
		if (s->x.drawEnd >= s->ry)
			s->x.drawEnd = s->ry - 1;
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
//	mlx_hook(s->win, 2, 0L, ft_move, s);
}

//int 	move(int keycode, t_all *s)
//{
//	int x;
//	int y;
//
//	x = (int)s->plr.x;
//	y = (int)s->plr.y;
//	if (keycode == 13 && s->map[y - 1][x] == '0')
//		s->plr.y--;
//	else if (keycode == 1 && s->map[y + 1][x] == '0')
//		s->plr.y++;
//	else if (keycode == 2 && s->map[y][x + 1] == '0')
//		s->plr.x++;
//	else if (keycode == 0 && s->map[y][x - 1] == '0')
//		s->plr.x--;
//	if (s->plr.dir > 2 * M_PI)
//		s->plr.dir -= 2 * M_PI;
//	else if (s->plr.dir < 0)
//		s->plr.dir += 2 * M_PI;
//	if (keycode == 123)
//		s->plr.dir -=  5 * M_PI / 180;
//	else if (keycode == 124)
//		s->plr.dir += 5 * M_PI / 180;
//	mlx_destroy_image(s->mlx, s->img.img);
//	init_mlx(s);
//	output(s);
//	return (0);
//}

void	start(char *map)
{
	int		fd;
	char	*line;
	t_all	s;
	t_list	*tmp;

	if ((fd = open(map, O_RDONLY)) < 0)
		write(2, "\033[31mError : Failed to open the map\n\033[0m", 40);
	else
		{
			s.rx = 0;
			s.ry = 0;
			s.lst = NULL;
			s.errno = 0;
			s.map = NULL;
			s.no = NULL;
			s.so = NULL;
			s.we = NULL;
			s.ea = NULL;
			s.sp = NULL;
			s.plr.x = 0;
			s.plr.y = 0;
			s.plr.dir = 0.0;
			s.fc = 0;
			s.cc = 0;
			s.mlx = NULL;
			s.win = NULL;
			s.img.img = NULL;
			while ((s.errno = get_next_line(fd, &line)) > 0)
				ft_lstadd_back(&s.lst, ft_lstnew(line));
			ft_lstadd_back(&s.lst, ft_lstnew(line));
			tmp = s.lst;
			while (tmp && !error_check(s) && !s.map)
			{
				if (parser(tmp->content, &s) && (s.size = ft_lstsize(tmp)))
					create_map(&s, tmp, tmp, s.size);
				tmp = tmp->next;
			}
			if (map_check(&s))
				error_check(s);
			s.win = mlx_new_window(s.mlx, s.rx, s.ry, "Test");
			init_mlx(&s);


			s.x.dirx = -1;
			s.x.diry = 0;
			s.x.planeX = 0;
			s.x.planeY = 0.66;
			raycasting(&s);
			mlx_hook(s.win, 2, 0L, ft_move, &s);
			mlx_loop(s.mlx);

//			output(&s);
			exit(EXIT_FAILURE);
		}
}

int		main(int argc, char **argv)
{
	if (argc == 3 && !ft_revstrncmp(argv[1], ".cub", 4) &&
		!ft_revstrncmp(argv[2], "--save", 6))
		start(argv[1]);
	else if (argc == 2 && !ft_revstrncmp(argv[1], ".cub", 4))
		start(argv[1]);
	else
	 	write(2, "\033[31mError : Invalid arguments\n\033[0m", 35);
	return (0);
}