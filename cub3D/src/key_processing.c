/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:03:24 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:13:13 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_window(void)
{
	write(1, "Game over\n", 10);
	exit(EXIT_SUCCESS);
}

int		keydown(int keycode, t_all *all)
{
	if (keycode == 53)
		close_window();
	if (keycode == 13)
		all->move.up = 1;
	if (keycode == 1)
		all->move.down = 1;
	if (keycode == 0)
		all->move.left = 1;
	if (keycode == 2)
		all->move.right = 1;
	if (keycode == 123)
		all->move.rotation_left = 1;
	if (keycode == 124)
		all->move.rotation_right = 1;
	return (0);
}

int		keyup(int keycode, t_all *all)
{
	if (keycode == 13)
		all->move.up = 0;
	if (keycode == 1)
		all->move.down = 0;
	if (keycode == 0)
		all->move.left = 0;
	if (keycode == 2)
		all->move.right = 0;
	if (keycode == 123)
		all->move.rotation_left = 0;
	if (keycode == 124)
		all->move.rotation_right = 0;
	return (0);
}

void	movement(t_all *all)
{
	if (all->move.up)
		step_forward(all);
	if (all->move.down)
		step_back(all);
	if (all->move.left)
		step_left(all);
	if (all->move.right)
		step_right(all);
	if (all->move.rotation_left || all->move.rotation_right)
		rotation(all);
	if (all->move.up || all->move.down || all->move.left || all->move.right ||
			all->move.rotation_left || all->move.rotation_right)
		sort_sprites(all);
}
