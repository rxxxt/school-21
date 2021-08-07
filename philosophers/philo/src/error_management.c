/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:56:01 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:56:03 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_number(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	error_manager(int errno)
{
	printf("ERROR: ");
	if (errno == INCORRECT_NUMBER_OF_ARGUMENTS)
		printf("incorrect number of arguments\n");
	else if (errno == INVALID_ARGUMENT)
		printf("invalid argument\n");
	else if (errno == NO_MEMORY_ALLOCATED)
		printf("memory not allocated\n");
	return (errno);
}

int	valid_arguments(int argc, char **argv)
{
	int	i;
	int	number;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if ((!is_number(argv[i]) || number < 0) || (argc == 6 && number == 0))
			return (0);
		++i;
	}
	return (1);
}
