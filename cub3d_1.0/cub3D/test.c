/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:16:10 by tredfort          #+#    #+#             */
/*   Updated: 2021/01/14 17:16:12 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>

//
//char	**make_map(t_list **head, int size)
//{
//	char	  **map = ft_calloc(size + 1, sizeof(char *));
//	int		  i = -1;
//	t_list	*tmp = *head;
//
//	while (tmp)
//	{
//		map[++i] = tmp->content;
//		tmp= tmp->next;
//	}
////	i = -1;
////	while (map[++i])
////		ft_putendl_fd(map[i], 1);
//	return (map);
//}
//
//void	ft_cast_ray(t_all *all)
//{
//	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока
//
//	while (all->map[(int)(ray.y / block_size)][(int)(ray.x / block_size)] != '1')
//	{
//		ray.x += cos(ray.dir);
//		ray.y += sin(ray.dir);
//		mlx_pixel_put(all->win->mlx, all->win, ray.x, ray.y, 0x990099);
//	}
//}

int		main(int argc, char **argv)
{
//	int		fd = open(argv[1], O_RDONLY);
//	char 	*line = NULL;
//	t_list	*head = NULL;
//
//	while (get_next_line(fd, &line))
//		ft_lstadd_back(&head, ft_lstnew(line));
//	ft_lstadd_back(&head, ft_lstnew(line));
//	make_map(&head, ft_lstsize(head));
	printf("%d", ft_revstrncmp("map.cub", ".cub", 4));
	return (0);
}

//int		main(void)
//{
//	int		fd;
//	char	*line;
//
//	fd = open("maps/map.cub", O_RDONLY);
//	while (get_next_line(fd, &line) > 0)
//	{
//		printf("%s\n", line);
//		free(line);
//	}
//	printf("%s\n", line);
//	free(line);
//	return (0);
//}

//int main()
//{
//	void	*mlx;
//	void 	*win;
//	int 	x;
//	int 	y = 100;
//
//	mlx = mlx_init();
//	win	= mlx_new_window(mlx, 640, 480, "Test");
//	while (y++ < 200)
//	{
//		x = 100;
//		while (x++ < 200)
//			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
//	}
//	mlx_loop(mlx);
//	return (0);
//}
