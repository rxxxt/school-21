/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:40:20 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:40:22 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	observe_the_philosophers(t_data	*data)
{
	pthread_t	thread;
	int			time_after_eating;

	pthread_create(&thread, NULL, life_of_philosopher, (void *)data);
	while (data->existence)
	{
		time_after_eating = (int)(get_time_in_ms() - data->start)
			- data->last_meal;
		if (time_after_eating > data->time_to_die)
		{
			sem_wait(data->sem_freedom_of_speech);
			printf("%ld ms #%d died\n", get_time_in_ms() - data->start,
				data->number);
			data->existence = 0;
			exit(1);
		}
		if (data->min_number_of_meals > 0
			&& data->number_of_meals >= data->min_number_of_meals)
			data->existence = 0;
	}
}
