/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:40:02 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:40:05 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void
	what_does_a_philosopher_do(t_data *data, char *action, int time)
{
	sem_wait(data->sem_freedom_of_speech);
	printf("%ld ms #%d %s\n", get_time_in_ms() - data->start, data->number,
		action);
	sem_post(data->sem_freedom_of_speech);
	if (time)
		ft_usleep(time);
}

static void	take_the_forks(t_data *data)
{
	sem_wait(data->sem_waiter);
	sem_wait(data->sem_forks);
	what_does_a_philosopher_do(data, "has taken left a fork", 0);
	sem_wait(data->sem_forks);
	what_does_a_philosopher_do(data, "has taken right a fork", 0);
	sem_post(data->sem_waiter);
}

static void	put_the_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
}

void	*life_of_philosopher(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (data->existence)
	{
		take_the_forks(data);
		data->last_meal = (int)(get_time_in_ms() - data->start);
		what_does_a_philosopher_do(data, "is eating", data->time_to_eat);
		++data->number_of_meals;
		put_the_forks(data);
		what_does_a_philosopher_do(data, "is sleeping", data->time_to_sleep);
		what_does_a_philosopher_do(data, "is thinking", 0);
	}
	return (NULL);
}
