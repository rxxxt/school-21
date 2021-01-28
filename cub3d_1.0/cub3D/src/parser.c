/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:30:36 by tredfort          #+#    #+#             */
/*   Updated: 2021/01/16 15:30:40 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_resolution(char *line, t_all *s)
{
	int xmax;
	int ymax;
	int xmin;
	int ymin;

	s->errno = (s->rx || s->ry ? -2 : s->errno);
	xmin = 320;
	ymin = 240;
	s->mlx = mlx_init();
	mlx_get_screen_size(s->mlx, &xmax, &ymax);
	s->rx = atoi_bias(&line);
	s->ry = atoi_bias(&line);
	s->errno = (s->rx <= 0 || s->ry <= 0 || *line ? -2 : s->errno);
	s->rx = (s->rx > xmax ? xmax : s->rx);
	s->rx = (s->rx < xmin ? xmin : s->rx);
	s->ry = (s->ry > ymax ? ymax : s->ry);
	s->ry = (s->ry < ymin ? ymin : s->ry);
}

char	*set_textures(char *file, t_all *s)
{
	int 	fd;

	s->errno = (!ft_strncmp(file - 3, "NO ", 3) && s->no ? -6 : s->errno);
	s->errno = (!ft_strncmp(file - 3, "SO ", 3) && s->so ? -6 : s->errno);
	s->errno = (!ft_strncmp(file - 3, "WE ", 3) && s->we ? -6 : s->errno);
	s->errno = (!ft_strncmp(file - 3, "EA ", 3) && s->ea ? -6 : s->errno);
	s->errno = (!ft_strncmp(file - 2, "S ", 2) && s->sp ? -6 : s->errno);
	if (!(file = ft_strtrim(file, " \t")))
		s->errno = -10;
	if ((fd = open(file, O_RDONLY)) < 0 || ft_revstrncmp(file, ".xpm", 4))
		s->errno = -3;
	close(fd);
	return (file);
}

int		set_color(char *str, t_all *s)
{
	int r;
	int	g;
	int b;

	str = remove_spaces(str, " \t");
	s->errno = (!ft_strncmp(str - 2, "F ", 2) && s->fc ? -8 : s->errno);
	s->errno = (!ft_strncmp(str - 2, "C ", 2) && s->cc ? -8 : s->errno);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -4 : s->errno);
	r = atoi_bias(&str);
	str += (*str != '\0' ? 1 : 0);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -4 : s->errno);
	g = atoi_bias(&str);
	str += (*str != '\0' ? 1 : 0);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -4 : s->errno);
	b = atoi_bias(&str);
	s->errno = (*str != '\0' || r > 255 || g > 255 || b > 255 ? -4 : s->errno);
	return (r << 16 | g << 8 | b);
}

void	set_player(t_all *s, int x, int y)
{
	if (s->plr.x || s->plr.y || s->plr.dir)
		s->errno = - 9;
	s->plr.x = x + 0.5;
	s->plr.y = y + 0.5;
	if (s->map[y][x] == 'E')
		s->plr.dir = 0.0;
	else if (s->map[y][x] == 'N')
		s->plr.dir = (3 * M_PI / 2 );
	else if (s->map[y][x] == 'W')
		s->plr.dir = M_PI;
	else if (s->map[y][x] == 'S')
		s->plr.dir = (M_PI / 2);
}

int		parser(char *str, t_all *s)
{
	while (*str == ' ')
		str++;
	if (*str == 'R' && *(str + 1) == ' ')
		set_resolution(str + 1, s);
	else if (*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		s->no = set_textures(str + 3, s);
	else if (*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		s->so = set_textures(str + 3, s);
	else if (*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		s->we = set_textures(str + 3, s);
	else if (*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		s->ea = set_textures(str + 3, s);
	else if (*str == 'S' && *(str + 1) == ' ')
		s->sp = set_textures(str + 2, s);
	else if (*str == 'F' && *(str + 1) == ' ')
		s->fc = set_color(str + 2, s);
	else if (*str == 'C' && *(str + 1) == ' ')
		s->cc = set_color(str + 2, s);
	else if (*str != '1' && *str != '\0')
		s->errno = - 7;
	else if (*str == '1' && !s->map)
		return (1);
	return (0);
}