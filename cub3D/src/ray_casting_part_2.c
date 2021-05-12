/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:14:31 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/14 02:46:54 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculations(t_all *all, int i)
{
	t_dpoint	sprite;

	sprite.x = all->sprite[i].x - all->plr.x;
	sprite.y = all->sprite[i].y - all->plr.y;
	all->inv_det = 1.0 / (all->plane.x * all->dir.y - all->dir.x *
			all->plane.y);
	all->transform.x = all->inv_det * (all->dir.y * sprite.x - all->dir.x *
			sprite.y);
	all->transform.y = all->inv_det * (-all->plane.y * sprite.x + all->plane.x
			* sprite.y);
	all->sprite_screen_x = (int)((all->width / 2) * (1 + all->transform.x /
				all->transform.y));
	all->sprite_height = abs((int)(all->height / all->transform.y));
	if ((all->draw_start.y = -all->sprite_height / 2 + all->height / 2) < 0)
		all->draw_start.y = 0;
	all->draw_end.y = all->sprite_height / 2 + all->height / 2;
	if (all->draw_end.y >= all->height)
		all->draw_end.y = all->height - 1;
	all->sprite_width = abs((int)(all->width / all->transform.y));
	if ((all->draw_start.x = -all->sprite_width / 2 + all->sprite_screen_x) < 0)
		all->draw_start.x = 0;
	all->draw_end.x = all->sprite_width / 2 + all->sprite_screen_x;
	if (all->draw_end.x >= all->width)
		all->draw_end.x = all->width - 1;
}

static void	draw_line(t_all *all, int x)
{
	int y;
	int factor;
	int color;

	y = all->draw_start.y;
	while (y < all->draw_end.y)
	{
		factor = y * 256 - all->height * 128 + all->sprite_height * 128;
		all->texture.y = ((factor * all->img[5].height) / all->sprite_height)
				/ 256;
		color = get_color_texture(all, all->img[5]);
		if (color && color != 0xff000000)
			my_mlx_pixel_put(&all->img[0], x, y, color);
		y++;
	}
}

void		draw_sprites(t_all *all, double *buffer, int i)
{
	int x;

	calculations(all, i);
	x = all->draw_start.x;
	while (x < all->draw_end.x)
	{
		all->texture.x = (int)(256 * (x - (-all->sprite_width / 2 +
				all->sprite_screen_x)) * all->img[5].width /
						all->sprite_width) / 256;
		if (all->transform.y > 0 && x > 0 && x < all->width &&
			all->transform.y < buffer[x])
			draw_line(all, x);
		x++;
	}
}

int			ray_casting(t_all *all)
{
	double	buffer[all->width];
	int		x;
	int		i;

	x = 0;
	mlx_do_sync(all->mlx);
	while (x < all->width)
	{
		initial_parameters(all, x);
		wall_search(all);
		height_of_walls(all, buffer, x);
		position_x_in_texture(all);
		pixel_put_to_img(all, x, 0);
		x++;
	}
	i = 0;
	while (i < all->sprite_count)
		draw_sprites(all, buffer, i++);
	if (all->save)
		take_screenshot(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img[0].img, 0, 0);
	movement(all);
	return (0);
}
