/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:59:08 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/14 02:43:55 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_params(t_all *all)
{
	int	i;

	i = 0;
	if (!(all->mlx = mlx_init()))
		exit_failure(-10);
	all->map = NULL;
	while (i < 6)
	{
		all->img[i].img = NULL;
		all->img[i++].addr = NULL;
	}
}

void	init_all_params(t_all *all)
{
	init_params(all);
	all->plr.x = 0.0;
	all->plr.y = 0.0;
	all->dir.x = 0.0;
	all->dir.y = 0.0;
	all->plane.x = 0.0;
	all->plane.y = 0.0;
	all->ray_dir.x = 0.0;
	all->ray_dir.y = 0.0;
	all->move.up = 0;
	all->move.down = 0;
	all->move.left = 0;
	all->move.right = 0;
	all->move.rotation_left = 0;
	all->move.rotation_right = 0;
	all->width = 0;
	all->height = 0;
	all->floor = -1;
	all->ceilling = -1;
	all->side = 0;
	all->sprite_count = 0;
}

void	read_config_file(char *file, t_list **lst)
{
	int		fd;
	int		errno;
	char	*line;
	t_list	*tmp;

	tmp = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		exit_failure(-13);
	while ((errno = get_next_line(fd, &line)) > 0)
		ft_lstadd_back(&tmp, ft_lstnew(line));
	if (errno == -1)
		exit_failure(-1);
	ft_lstadd_back(&tmp, ft_lstnew(line));
	if (ft_lstsize(tmp) < 11)
		exit_failure(-5);
	*lst = tmp;
}

void	create_new_img(t_all *all)
{
	if (!(all->img[0].img = mlx_new_image(all->mlx, all->width, all->height)))
		exit_failure(-10);
	if (!(all->img[0].addr = mlx_get_data_addr(all->img[0].img,
					&all->img[0].bits_per_pixel,
					&all->img[0].line_length, &all->img[0].endian)))
		exit_failure(-10);
}

void	init_cube(char *file, int save)
{
	t_all	all;
	t_list	*lst;
	t_list	*tmp;

	read_config_file(file, &lst);
	tmp = lst;
	init_all_params(&all);
	all.save = save;
	while (lst && !all.map)
	{
		parse(&all, lst);
		lst = lst->next;
	}
	ft_lstclear(&tmp, free);
	map_check(&all, 0, 0);
	create_new_img(&all);
	if (save)
		ray_casting(&all);
	if (!(all.win = mlx_new_window(all.mlx, all.width, all.height,
					"cub3D")))
		exit_failure(-10);
	loops(all);
}
