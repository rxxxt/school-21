/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:55:41 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/16 15:18:05 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initial_parameters(t_all *all, int x)
{
	double camera_x;

	camera_x = 2.0 * x / all->width - 1;
	all->ray_dir.x = all->dir.x + all->plane.x * camera_x;
	all->ray_dir.y = all->dir.y + all->plane.y * camera_x;
	all->pos_map.x = (int)all->plr.x;
	all->pos_map.y = (int)all->plr.y;
	all->delta_dist.x = (!all->ray_dir.x) ? 1 : fabs(1 / all->ray_dir.x);
	all->delta_dist.x = (!all->ray_dir.y) ? 0 : all->delta_dist.x;
	all->delta_dist.y = (!all->ray_dir.y) ? 1 : fabs(1 / all->ray_dir.y);
	all->delta_dist.y = (!all->ray_dir.x) ? 0 : all->delta_dist.y;
	if (all->ray_dir.x < 0 && (all->step.x = -1))
		all->side_dist.x = (all->plr.x - all->pos_map.x) * all->delta_dist.x;
	else if ((all->step.x = 1))
		all->side_dist.x = (all->pos_map.x + 1.0 - all->plr.x) *
			all->delta_dist.x;
	if (all->ray_dir.y < 0 && (all->step.y = -1))
		all->side_dist.y = (all->plr.y - all->pos_map.y) * all->delta_dist.y;
	else if ((all->step.y = 1))
		all->side_dist.y = (all->pos_map.y + 1.0 - all->plr.y) *
			all->delta_dist.y;
}

void	wall_search(t_all *all)
{
	while (all->map[all->pos_map.y][all->pos_map.x] != '1')
	{
		if (all->side_dist.x < all->side_dist.y)
		{
			all->side_dist.x += all->delta_dist.x;
			all->pos_map.x += all->step.x;
			all->side = 3;
		}
		else
		{
			all->side_dist.y += all->delta_dist.y;
			all->pos_map.y += all->step.y;
			all->side = 1;
		}
	}
}

void	height_of_walls(t_all *all, double *buffer, int x)
{
	if (all->side == 3)
		all->perp_wall_dist = (all->pos_map.x - all->plr.x + (1.0 - all->step.x)
				/ 2) / all->ray_dir.x;
	else
		all->perp_wall_dist = (all->pos_map.y - all->plr.y + (1.0 - all->step.y)
				/ 2) / all->ray_dir.y;
	buffer[x] = all->perp_wall_dist;
	if (all->side == 3 && all->ray_dir.x > 0)
		all->side = 4;
	if (all->side == 1 && all->ray_dir.y > 0)
		all->side = 2;
	all->line_height = (int)(all->height / all->perp_wall_dist);
	all->draw_start.y = -all->line_height / 2 + all->height / 2;
	if (all->draw_start.y < 0)
		all->draw_start.y = 0;
	all->draw_end.y = all->line_height / 2 + all->height / 2;
	if (all->draw_end.y >= all->height)
		all->draw_end.y = all->height - 1;
}

void	position_x_in_texture(t_all *all)
{
	double	wallx;

	if (all->side == 3 || all->side == 4)
		wallx = all->plr.y + all->perp_wall_dist * all->ray_dir.y;
	else
		wallx = all->plr.x + all->perp_wall_dist * all->ray_dir.x;
	wallx -= (int)(wallx);
	all->texture.x = (int)(wallx * (double)(all->img[all->side].width));
}

void	pixel_put_to_img(t_all *all, int x, int y)
{
	int		color;
	double	step;
	double	tex_pos;

	step = 1.0 * all->img[all->side].height / all->line_height;
	tex_pos = (all->draw_start.y - all->height / 2.0 + all->line_height / 2.0) *
			step;
	while (y < all->height)
	{
		if (y < all->draw_start.y)
			color = all->ceilling;
		else if (y <= all->draw_end.y)
		{
			all->texture.y = (int)tex_pos;
			if ((int)tex_pos > all->img[all->side].height - 1)
				all->texture.y &= (all->img[all->side].height - 1);
			tex_pos += step;
			color = get_color_texture(all, all->img[all->side]);
			(color == 0xFF000000) ? (color = 0) : 0;
		}
		else
			color = all->floor;
		my_mlx_pixel_put(&all->img[0], x, y, color);
		y++;
	}
}
