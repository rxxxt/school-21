/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:57:40 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:58:49 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_sprite(t_all *all)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	if (!(all->sprite = malloc(sizeof(t_sprite) * all->sprite_count)))
		exit_failure(-10);
	while (y < all->map_size)
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
			{
				all->sprite[i].x = x + 0.5;
				all->sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	sort_sprites(all);
}

void	sort_sprites(t_all *all)
{
	t_sprite	tmp;
	int			i;

	i = 0;
	while (i < all->sprite_count)
	{
		all->sprite[i].dist = (all->plr.x - all->sprite[i].x) * (all->plr.x -
				all->sprite[i].x) + (all->plr.y - all->sprite[i].y) *
						(all->plr.y - all->sprite[i].y);
		i++;
	}
	i = 0;
	while (i < all->sprite_count - 1)
	{
		if (all->sprite[i].dist < all->sprite[i + 1].dist)
		{
			tmp = all->sprite[i];
			all->sprite[i] = all->sprite[i + 1];
			all->sprite[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}
