/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:30:47 by tredfort          #+#    #+#             */
/*   Updated: 2021/01/16 15:30:49 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int		error_check(t_all s)
{
	if (s.errno == -1)
		write(2, "\033[31mError: сouldn't parse file (GNL)\n\033[0m", 42);
	else if (s.errno == -2)
		write(2, "\033[31mError: incorrect resolution\n\033[0m", 37);
	else if (s.errno == -3)
		write(2, "\033[31mError: incorrect textures\n\033[0m", 35);
	else if (s.errno == -4)
		write(2, "\033[31mError: incorrect textures color\n\033[0m", 41);
	else if (s.errno == -5)
		write(2, "\033[31mError: incorrect map\n\033[0m", 30);
	else if (s.errno == -6)
		write(2, "\033[31mError: overriding texture\n\033[0m", 35);
	else if (s.errno == -7)
		write(2, "\033[31mError: incorrect map parameters\n\033[0m", 41);
	else if (s.errno == -8)
		write(2, "\033[31mError: overriding textures color\n\033[0m", 42);
	else if (s.errno == -9)
		write(2, "\033[31mError: more than 1 player\n\033[0m", 35);
	else if (s.errno == -10)
		write(2, "\033[31mError: failed to allocate memory\n\033[0m", 42);
	else if (s.errno == -11)
		write(2, "\033[31mError: \n\033[0m", 30);
	else if (s.errno == -12)
		write(2, "\033[31mError: \n\033[0m", 30);
	return (s.errno);
}

int		map_check(t_all *s)
{
	char	**m;
	int		x;
	int		y;

	y = 0;
	m = s->map;
	while (y < s->size)
	{
		x = 0;
		while (m[y][x] && !s->errno)
		{
			if (ft_strchr("NSEW", m[y][x]))
				set_player(s, x, y);
			if (((!ft_strchr(" 1", m[y][x]) && (!m[y][x + 1] ||
				m[y][x + 1] == ' ' || x == 0 || (y == 0 || y == s->size - 1)
				|| m[y + 1][x] == ' ')) || (m[y][x] == ' ' && ((m[y][x + 1]
				&& !ft_strchr(" 1", m[y][x + 1])) || (y != s->size - 1 &&
				!ft_strchr(" 1", m[y + 1][x]))))) ||
				!ft_strchr("012NSEW ", m[y][x]))
				s->errno = -5;
			x++;
		}
		y++;
	}
	return (s->errno);
}