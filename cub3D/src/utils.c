/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:06:27 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 22:00:56 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_color_texture(t_all *all, t_img img)
{
	int		pos;

	pos = (all->texture.y * img.line_length + all->texture.x *
			(img.bits_per_pixel / 8));
	return (*(int *)(img.addr + pos));
}

void	loops(t_all all)
{
	mlx_hook(all.win, 2, (1L << 0), &keydown, &all);
	mlx_hook(all.win, 3, (1L << 1), &keyup, &all);
	mlx_hook(all.win, 17, 0, &close_window, &all);
	mlx_loop_hook(all.mlx, ray_casting, &all);
	mlx_loop(all.mlx);
}
