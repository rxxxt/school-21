/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:43:47 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:59:43 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_in_header(t_all *all, unsigned char **bitmap)
{
	int	n;

	n = 0;
	while (n < 54)
		(*bitmap)[n++] = (unsigned char)(0);
	n = all->width * all->height * 4 + 54;
	(*bitmap)[0] = (unsigned char)('B');
	(*bitmap)[1] = (unsigned char)('M');
	(*bitmap)[2] = (unsigned char)(n);
	(*bitmap)[3] = (unsigned char)(n >> 8);
	(*bitmap)[4] = (unsigned char)(n >> 16);
	(*bitmap)[5] = (unsigned char)(n >> 24);
	(*bitmap)[10] = (unsigned char)(54);
	(*bitmap)[14] = (unsigned char)(40);
	(*bitmap)[18] = (unsigned char)(all->width);
	(*bitmap)[19] = (unsigned char)(all->width >> 8);
	(*bitmap)[20] = (unsigned char)(all->width >> 16);
	(*bitmap)[21] = (unsigned char)(all->width >> 24);
	(*bitmap)[22] = (unsigned char)(all->height);
	(*bitmap)[23] = (unsigned char)(all->height >> 8);
	(*bitmap)[24] = (unsigned char)(all->height >> 16);
	(*bitmap)[25] = (unsigned char)(all->height >> 24);
	(*bitmap)[26] = (unsigned char)(1);
	(*bitmap)[28] = (unsigned char)(32);
}

void	fill_in_body(t_all *all, unsigned char **bitmap)
{
	int	x;
	int	y;
	int n;
	int color;

	n = 54;
	y = all->height;
	while (--y >= 0)
	{
		x = 0;
		while (x < all->width)
		{
			color = *(int *)(all->img[0].addr + (y * all->img[0].line_length +
					x * (all->img[0].bits_per_pixel / 8)));
			(*bitmap)[n] = (unsigned char)(color);
			(*bitmap)[n + 1] = (unsigned char)(color >> 8);
			(*bitmap)[n + 2] = (unsigned char)(color >> 16);
			(*bitmap)[n + 3] = (unsigned char)(color >> 24);
			n += 4;
			x++;
		}
	}
}

void	take_screenshot(t_all *all)
{
	unsigned char	*bitmap;
	int				fd;
	int				byte;

	byte = all->width * all->height * 4 + 54;
	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU))
		< 0)
		exit_failure(-12);
	if (!(bitmap = (unsigned char*)malloc(byte)))
		exit_failure(-10);
	fill_in_header(all, &bitmap);
	fill_in_body(all, &bitmap);
	write(fd, bitmap, byte);
	close(fd);
	free(bitmap);
	write(1, "screenshot completed\n", 21);
	exit(EXIT_SUCCESS);
}
