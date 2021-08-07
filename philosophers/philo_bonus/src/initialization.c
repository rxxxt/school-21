/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:39:52 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:39:55 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	initializing_semaphores(t_data *data)
{
	sem_unlink(FORKS);
	sem_unlink(WAITER);
	sem_unlink(PRINT);
	data->sem_freedom_of_speech = sem_open(PRINT, O_CREAT, ALLPERMS, 1);
	if (data->sem_freedom_of_speech == SEM_FAILED)
		error_manager(SEMAPHORE_FAILED);
	data->sem_waiter = sem_open(WAITER, O_CREAT, ALLPERMS, 1);
	if (data->sem_waiter == SEM_FAILED)
		error_manager(SEMAPHORE_FAILED);
	data->sem_forks = sem_open(FORKS, O_CREAT, ALLPERMS, data->number_of_philo);
	if (data->sem_forks == SEM_FAILED)
		error_manager(SEMAPHORE_FAILED);
}

void	initialization(t_data *data, int argc, char **argv)
{
	data->existence = 1;
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_number_of_meals = -1;
	if (argc == 6)
		data->min_number_of_meals = ft_atoi(argv[5]);
	data->start = get_time_in_ms();
	data->number_of_meals = 0;
	data->last_meal = 0;
	initializing_semaphores(data);
}
