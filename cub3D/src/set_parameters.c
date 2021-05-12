/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:37:26 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:52:45 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_resolution(char *line, t_all *all)
{
	int xmax;
	int ymax;

	xmax = 15360;
	ymax = 8640;
	if (!(all->mlx = mlx_init()))
		exit_failure(-10);
	while (*line == ' ')
		line++;
	(all->width || all->height) ? exit_failure(-2) : 0;
	if (!all->save)
		mlx_get_screen_size(all->mlx, &xmax, &ymax);
	all->width = (ft_nbrlen(line) > ft_digit_capacity(xmax) ? xmax :
			ft_atoi_and_bias(&line));
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	all->height = (ft_nbrlen(line) > ft_digit_capacity(ymax) ? ymax :
			ft_atoi_and_bias(&line));
	while (ft_isdigit(*line))
		line++;
	(all->width < 1 || all->height < 1 || *line) ? exit_failure(-2) : 0;
	all->width = (all->width > xmax ? xmax : all->width);
	all->height = (all->height > ymax ? ymax : all->height);
}

void	set_texture(char *file, t_all *all, t_img *img)
{
	if (!(file = ft_strtrim(file, " \t")))
		exit_failure(-10);
	if (ft_revstrncmp(file, ".xpm", 4))
		exit_failure(-3);
	if (img->addr)
		exit_failure(-6);
	if (!(img->img = mlx_xpm_file_to_image(all->mlx, file,
					&img->width, &img->height)))
		exit_failure(-3);
	free(file);
	if (!(img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian)))
		exit_failure(-3);
}

void	set_color(char *str, int *color)
{
	int r;
	int	g;
	int b;

	if (*color != -1)
		exit_failure(-8);
	str = ft_remove_chars(str, " \t");
	(!*str || ft_nbrlen(str) > 3 || !ft_isdigit(*str)) ? exit_failure(-4) : 0;
	r = ft_atoi_and_bias(&str);
	str += (*str == ',' ? 1 : 0);
	(!*str || ft_nbrlen(str) > 3 || !ft_isdigit(*str)) ? exit_failure(-4) : 0;
	g = ft_atoi_and_bias(&str);
	str += (*str == ',' ? 1 : 0);
	(!*str || ft_nbrlen(str) > 3 || !ft_isdigit(*str)) ? exit_failure(-4) : 0;
	b = ft_atoi_and_bias(&str);
	(*str || r > 255 || g > 255 || b > 255) ? exit_failure(-4) : 0;
	*color = ((r << 16 | g << 8 | b));
}

void	set_player(t_all *all, int x, int y)
{
	if (all->plr.x || all->plr.y)
		exit_failure(-11);
	all->plr.x = x + 0.5;
	all->plr.y = y + 0.5;
	if (all->map[y][x] == 'E')
	{
		all->dir.x = 1.0;
		all->plane.y = 0.66;
	}
	else if (all->map[y][x] == 'N')
	{
		all->dir.y = -1.0;
		all->plane.x = 0.66;
	}
	else if (all->map[y][x] == 'W')
	{
		all->dir.x = -1.0;
		all->plane.y = -0.66;
	}
	else if (all->map[y][x] == 'S')
	{
		all->dir.y = 1.0;
		all->plane.x = -0.66;
	}
	all->map[y][x] = '0';
}

void	create_map(t_all *all, t_list *lst, t_list *tmp)
{
	int	i;
	int	len;
	int	max_len;

	max_len = 0;
	all->map_size = ft_lstsize(lst);
	while (tmp)
	{
		if (max_len < (len = ft_strlen(tmp->content)))
			max_len = len;
		(!len) ? exit_failure(-5) : 0;
		tmp = tmp->next;
	}
	if (!(all->map = ft_calloc(sizeof(char *), all->map_size + 1)))
		exit_failure(-10);
	i = 0;
	while (lst)
	{
		if (!(all->map[i] = ft_substr(lst->content, 0, max_len)))
			exit_failure(-10);
		if ((len = ft_strlen(all->map[i])) < max_len)
			ft_memset(all->map[i] + len, ' ', max_len - len);
		lst = lst->next;
		i++;
	}
}
