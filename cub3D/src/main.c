/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:42:42 by tredfort          #+#    #+#             */
/*   Updated: 2021/02/12 21:14:04 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 2 && !ft_revstrncmp(argv[1], ".cub", 4))
		init_cube(argv[1], 0);
	else if (argc == 3 && !ft_revstrncmp(argv[1], ".cub", 4) &&
		!ft_strcmp(argv[2], "--save"))
		init_cube(argv[1], 1);
	else
		write(2, "\033[31mError\nInvalid arguments\n\033[0m", 33);
	return (0);
}
