#include "cub3D.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	img_init(t_all *all)
{
	all->img.img = mlx_new_image(all->mlx, all->x.w, all->x.h);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									&all->img.line_length, &all->img.endian);
}

int 	ft_move(int keycode, t_all *all)
{
		if (keycode == 53)
			exit(0);
	if (keycode == 13)
	{
		if (!all->x.map[(int)(all->x.posx + all->x.dirx * moveSpeed)][(int)
			(all->x.posy)])
			all->x.posx += all->x.dirx * moveSpeed;
		if (!all->x.map[(int)(all->x.posx)][(int)(all->x.posy + all->x.diry
			* moveSpeed)])
			all->x.posy += all->x.diry * moveSpeed;
	}
	if (keycode == 1)
	{
		if (!all->x.map[(int)(all->x.posx - all->x.dirx * moveSpeed)][(int)
		(all->x.posy)])
			all->x.posx -= all->x.dirx * moveSpeed;
		if (!all->x.map[(int)(all->x.posx)][(int)(all->x.posy - all->x.diry *
			moveSpeed)])
			all->x.posy -= all->x.diry * moveSpeed;
	}
	if (keycode == 0)
	{
		if (!all->x.map[(int)(all->x.posx - all->x.planeX * moveSpeed)][(int)
				(all->x.posy)])
			all->x.posx -= all->x.planeX * moveSpeed;
		if (!all->x.map[(int)(all->x.posx)][(int)(all->x.posy - all->x.planeY *
			moveSpeed)])
			all->x.posy -= all->x.planeY * moveSpeed;
	}
	if (keycode == 2)
	{
		if (!all->x.map[(int)(all->x.posx - all->x.planeX * moveSpeed)][(int)
				(all->x.posy)])
			all->x.posx += all->x.planeX * moveSpeed;
		if (!all->x.map[(int)(all->x.posx)][(int)(all->x.posy - all->x.planeY *
																moveSpeed)])
			all->x.posy += all->x.planeY * moveSpeed;
	}
	if (keycode == 123)
	{
		all->x.oldDirX = all->x.dirx;
		all->x.dirx = all->x.dirx * cos(rotSpeed) - all->x.diry * sin
				(rotSpeed);
		all->x.diry = all->x.oldDirX * sin(rotSpeed) + all->x.diry * cos
				(rotSpeed);
		all->x.oldPlaneX = all->x.planeX;
		all->x.planeX = all->x.planeX * cos(rotSpeed) - all->x.planeY *
				sin(rotSpeed);
		all->x.planeY = all->x.oldPlaneX * sin(rotSpeed) + all->x.planeY *
				cos(rotSpeed);
	}
	if (keycode == 124)
	{
		all->x.oldDirX = all->x.dirx;
		all->x.dirx = all->x.dirx * cos(-rotSpeed) - all->x.diry * sin
				(-rotSpeed);
		all->x.diry = all->x.oldDirX * sin(-rotSpeed) + all->x.diry * cos
				(-rotSpeed);
		all->x.oldPlaneX = all->x.planeX;
		all->x.planeX = all->x.planeX * cos(-rotSpeed) - all->x.planeY *
														 sin(-rotSpeed);
		all->x.planeY = all->x.oldPlaneX * sin(-rotSpeed) + all->x.planeY * cos(-rotSpeed);
	}
	raycasting(all);
	return (0);
}

void	raycasting(t_all *all)
{
	int 	x = 0;
	while (x < all->x.w)
	{
		all->x.cameraX = 2 * x / (double)all->x.w - 1;
		all->x.rayDirX = all->x.dirx + all->x.planeX * all->x.cameraX;
		all->x.rayDirY = all->x.diry + all->x.planeY * all->x.cameraX;
		all->x.mapX = all->x.posx;
		all->x.mapY = all->x.posy;
		all->x.hit = 0;
		all->x.deltaDistX = (!all->x.rayDirY) ? 0 : ((!all->x.rayDirX) ? 1 :
												 fabs(1 / all->x.rayDirX));
		all->x.deltaDistY = (!all->x.rayDirX) ? 0 : ((!all->x.rayDirY) ? 1 :
												 fabs(1 / all->x.rayDirY));
		if (all->x.rayDirX < 0)
		{
			all->x.stepX = -1;
			all->x.sideDistX = (all->x.posx - all->x.mapX) * all->x.deltaDistX;
		} else
		{
			all->x.stepX = 1;
			all->x.sideDistX = (all->x.mapX + 1.0 - all->x.posx) * all->x
					.deltaDistX;
		}
		if (all->x.rayDirY < 0)
		{
			all->x.stepY = -1;
			all->x.sideDistY = (all->x.posy - all->x.mapY) * all->x.deltaDistY;
		} else
		{
			all->x.stepY = 1;
			all->x.sideDistY = (all->x.mapY + 1.0 - all->x.posy) * all->x.deltaDistY;
		}
		while (!all->x.hit)
		{
			if (all->x.sideDistX < all->x.sideDistY)
			{
				all->x.sideDistX += all->x.deltaDistX;
				all->x.mapX += all->x.stepX;
				all->x.side = 0;
			} else
			{
				all->x.sideDistY += all->x.deltaDistY;
				all->x.mapY += all->x.stepY;
				all->x.side = 1;
			}
			if (all->x.map[all->x.mapX][all->x.mapY] > 0)
				all->x.hit = 1;
		}
		if (!all->x.side)
			all->x.perpWallDist = (all->x.mapX - all->x.posx + (1.0 - all->x.stepX) / 2) / all->x.rayDirX;
		else
			all->x.perpWallDist = (all->x.mapY - all->x.posy + (1.0 - all->x.stepY) / 2) / all->x.rayDirY;

		all->x.lineHeight = (int)(all->x.h / all->x.perpWallDist);
		all->x.drawStart = -all->x.lineHeight / 2 + all->x.h / 2;
		if (all->x.drawStart < 0)
			all->x.drawStart = 0;
		all->x.drawEnd = all->x.lineHeight / 2 + all->x.h / 2;
		if (all->x.drawEnd >= all->x.h)
			all->x.drawEnd = all->x.h - 1;
		for (int i = 0; i < all->x.drawStart; i++)
			my_mlx_pixel_put(&all->img, x, i, 0x540300);
		for (int i = all->x.drawStart; i <= all->x.drawEnd; i++)
		{
			int color;
			if (all->x.side == 1)
				color = (all->x.rayDirY > 0) ? 0xff54ff : 0x1f3dff;
			else
				color = (all->x.rayDirX > 0) ? 0xff9300 : 0xf3ff53;
			my_mlx_pixel_put(&all->img, x, i, color);
		}
		for (int i = all->x.drawEnd + 1; i < all->x.h; i++)
			my_mlx_pixel_put(&all->img, x, i, 0x1c006c);
		x++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}

int main()
{
	t_all all;
	all.x.h = 1080;
	all.x.w = 1920;
	int worldMap[24][24]=
			{
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
			};
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 24; j++)
			all.x.map[i][j] = worldMap[i][j];
//	for (int i = 0; i < 24; i++)
//	{
//		for (int j = 0; j < 24; j++)
//		{
//			printf("%d", all.x.map[i][j]);
//		}
//		printf("\n");
//	}
	all.x.posx = 22;
	all.x.posy = 12;
	all.x.dirx = -1;
	all.x.diry = 0;
	all.x.planeX = 0;
	all.x.planeY = 0.66;
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, all.x.w, all.x.h, "cub3D");

	img_init(&all);
	raycasting(&all);
	mlx_hook(all.win, 2, 0L, ft_move, &all);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 0, 0);
	mlx_loop(all.mlx);
	return (0);
}
