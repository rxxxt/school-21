/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:30:36 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:19:13 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_failure(int error)
{
	char *s;

	s = "Not expected\n\033[0m";
	(error == -1) ? s = "Couldn't parse file (GNL)\n\033[0m" : 0;
	(error == -2) ? s = "Incorrect resolution\n\033[0m" : 0;
	(error == -3) ? s = "Incorrect textures\n\033[0m" : 0;
	(error == -4) ? s = "Incorrect color\n\033[0m" : 0;
	(error == -5) ? s = "Incorrect map\n\033[0m" : 0;
	(error == -6) ? s = "Overriding texture\n\033[0m" : 0;
	(error == -7) ? s = "Incorrect map parameters\n\033[0m" : 0;
	(error == -8) ? s = "Overriding color\n\033[0m" : 0;
	(error == -9) ? s = "The player is missing\n\033[0m" : 0;
	(error == -10) ? s = "Failed to allocate memory\n\033[0m" : 0;
	(error == -11) ? s = "More than 1 player\n\033[0m" : 0;
	(error == -12) ? s = "Failed to take screenshot\n\033[0m" : 0;
	(error == -13) ? s = "Failed to open the map\n\033[0m" : 0;
	write(2, "\033[31mError\n", 11);
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

void	map_check(t_all *all, int x, int y)
{
	while (y < all->map_size)
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
				all->sprite_count++;
			if (ft_strchr("NSEW", all->map[y][x]))
				set_player(all, x, y);
			if (((!ft_strchr(" 1", all->map[y][x]) && (!all->map[y][x + 1] ||
				all->map[y][x + 1] == ' ' || x == 0 || (y == 0 ||
				y == all->map_size - 1) || all->map[y + 1][x] == ' ')) ||
				(all->map[y][x] == ' ' && ((all->map[y][x + 1] &&
				!ft_strchr(" 1", all->map[y][x + 1])) ||
				(y != all->map_size - 1 &&
				!ft_strchr(" 1", all->map[y + 1][x])))))
				|| !ft_strchr("012NSEW ", all->map[y][x]))
				exit_failure(-5);
			x++;
		}
		y++;
	}
	set_sprite(all);
	if (!all->plr.x && !all->plr.y)
		exit_failure(-9);
}

int		params_are_set(t_all *all)
{
	int ok;

	ok = 1;
	if (!all->width && !all->height)
		ok = 0;
	else if (!all->img[1].addr)
		ok = 0;
	else if (!all->img[2].addr)
		ok = 0;
	else if (!all->img[3].addr)
		ok = 0;
	else if (!all->img[4].addr)
		ok = 0;
	else if (!all->img[5].addr)
		ok = 0;
	else if (all->floor == -1)
		ok = 0;
	else if (all->ceilling == -1)
		ok = 0;
	return (ok);
}

void	parse(t_all *all, t_list *lst)
{
	char	*line;

	line = lst->content;
	if (!ft_strncmp(line, "R ", 2))
		set_resolution(line + 1, all);
	else if (!ft_strncmp(line, "NO ", 3))
		set_texture(line + 3, all, &all->img[1]);
	else if (!ft_strncmp(line, "SO ", 3))
		set_texture(line + 3, all, &all->img[2]);
	else if (!ft_strncmp(line, "WE ", 3))
		set_texture(line + 3, all, &all->img[3]);
	else if (!ft_strncmp(line, "EA ", 3))
		set_texture(line + 3, all, &all->img[4]);
	else if (!ft_strncmp(line, "S ", 2))
		set_texture(line + 2, all, &all->img[5]);
	else if (!ft_strncmp(line, "F ", 2))
		set_color(line + 2, &all->floor);
	else if (!ft_strncmp(line, "C ", 2))
		set_color(line + 2, &all->ceilling);
	else if (*line && ft_strchr(" 1", *line) && params_are_set(all))
		create_map(all, lst, lst);
	else if (*line)
		exit_failure(-7);
}
