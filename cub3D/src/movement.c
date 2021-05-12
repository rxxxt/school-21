/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:56:52 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:15:21 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotation(t_all *all)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = all->dir.x;
	old_planex = all->plane.x;
	if (all->move.rotation_right)
	{
		all->dir.x = old_dirx * cos(ROT_SPEED) - all->dir.y * sin(ROT_SPEED);
		all->dir.y = old_dirx * sin(ROT_SPEED) + all->dir.y * cos(ROT_SPEED);
		all->plane.x = old_planex * cos(ROT_SPEED) - all->plane.y *
													sin(ROT_SPEED);
		all->plane.y = old_planex * sin(ROT_SPEED) + all->plane.y *
													cos(ROT_SPEED);
	}
	if (all->move.rotation_left)
	{
		all->dir.x = old_dirx * cos(-ROT_SPEED) - all->dir.y * sin(-ROT_SPEED);
		all->dir.y = old_dirx * sin(-ROT_SPEED) + all->dir.y * cos(-ROT_SPEED);
		all->plane.x = old_planex * cos(-ROT_SPEED) - all->plane.y *
			sin(-ROT_SPEED);
		all->plane.y = old_planex * sin(-ROT_SPEED) + all->plane.y *
			cos(-ROT_SPEED);
	}
}

void	step_forward(t_all *all)
{
	if (all->map[(int)(all->plr.y)][(int)(all->plr.x + all->dir.x *
		(MOVE_SPEED + DELTA))] == '0')
		all->plr.x += all->dir.x * MOVE_SPEED;
	if (all->map[(int)(all->plr.y + all->dir.y * (MOVE_SPEED + DELTA))]
		[(int)(all->plr.x)] == '0')
		all->plr.y += all->dir.y * MOVE_SPEED;
}

void	step_back(t_all *all)
{
	if (all->map[(int)(all->plr.y)][(int)(all->plr.x - all->dir.x *
		(MOVE_SPEED + DELTA))] == '0')
		all->plr.x -= all->dir.x * MOVE_SPEED;
	if (all->map[(int)(all->plr.y - all->dir.y * (MOVE_SPEED + DELTA))]
		[(int)(all->plr.x)] == '0')
		all->plr.y -= all->dir.y * MOVE_SPEED;
}

void	step_left(t_all *all)
{
	if (all->map[(int)(all->plr.y)][(int)(all->plr.x - all->plane.x *
		(MOVE_SPEED + DELTA))] == '0')
		all->plr.x -= all->plane.x * MOVE_SPEED;
	if (all->map[(int)(all->plr.y - all->plane.y * (MOVE_SPEED + DELTA))]
		[(int)(all->plr.x)] == '0')
		all->plr.y -= all->plane.y * MOVE_SPEED;
}

void	step_right(t_all *all)
{
	if (all->map[(int)(all->plr.y)][(int)(all->plr.x + all->plane.x *
		(MOVE_SPEED + DELTA))] == '0')
		all->plr.x += all->plane.x * MOVE_SPEED;
	if (all->map[(int)(all->plr.y + all->plane.y * (MOVE_SPEED + DELTA))]
		[(int)(all->plr.x)] == '0')
		all->plr.y += all->plane.y * MOVE_SPEED;
}
