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

	if ((s->rx || s->ry) && (s->errno = -1))
		return;
	xmin = 320;
	ymin = 240;
	s->mlx = mlx_init();
	mlx_get_screen_size(s->mlx, &xmax, &ymax);
	s->rx = atoi_bias(&line);
	s->ry = atoi_bias(&line);
	if ((s->rx <= 0 || s->ry <= 0 || *line) && (s->errno = -1))
		return;
	s->rx = (s->rx > xmax ? xmax : s->rx);
	s->rx = (s->rx < xmin ? xmin : s->rx);
	s->ry = (s->ry > ymax ? ymax : s->ry);
	s->ry = (s->ry < ymin ? ymin : s->ry);
}

char	*set_textures(char *file, t_all *s)
{
	int 	fd;

	while (*file == ' ')
		file++;
	if ((fd = open(file, O_RDONLY)) < 0 || ft_revstrncmp(file, ".xpm", 4))
		s->errno = -2;
	close(fd);
	return (file);
}

int		set_color(char *str, t_all *s)
{
	int r;
	int	g;
	int b;

	s->errno = (s->fc || s->cc ? -3 : s->errno);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -3 : s->errno);
	r = atoi_bias(&str);
	str += (*str != '\0' ? 1 : 0);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -3 : s->errno);
	g = atoi_bias(&str);
	str += (*str != '\0' ? 1 : 0);
	s->errno = (*str == '\0' || !ft_isdigit(*str) ? -3 : s->errno);
	b = atoi_bias(&str);
	s->errno = (*str != '\0' || r > 255 || g > 255 || b > 255 ? -3 : s->errno);
	return (r << 16 | g << 8 | b);
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
	else if (*str == '1' && !s->map)
		return (1);
	return (0);
}