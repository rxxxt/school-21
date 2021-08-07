/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:56:21 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:56:22 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void
	what_does_a_philosopher_do(t_data *data, char *action, int time, int number)
{
	pthread_mutex_lock(&data->freedom_of_speech);
	printf("%ld ms %d %s\n", get_time_in_ms() - data->start, number, action);
	pthread_mutex_unlock(&data->freedom_of_speech);
	if (time)
		ft_usleep(time);
}

static void	take_the_forks(t_data *data, int left, int right, int number)
{
	pthread_mutex_lock(&data->philo[left].fork);
	what_does_a_philosopher_do(data, "has taken left a fork", 0, number);
	pthread_mutex_lock(&data->philo[right].fork);
	what_does_a_philosopher_do(data, "has taken right a fork", 0, number);
}

static void	put_the_forks(t_data *data, int left, int right)
{
	pthread_mutex_unlock(&data->philo[left].fork);
	pthread_mutex_unlock(&data->philo[right].fork);
}

static void	life_cycle(t_data *data, int left, int right, int number)
{
	take_the_forks(data, left, right, number);
	data->philo[left].last_meal = (int)(get_time_in_ms() - data->start);
	what_does_a_philosopher_do(data, "is eating", data->time_to_eat, number);
	++data->philo[left].number_of_meals;
	put_the_forks(data, left, right);
	what_does_a_philosopher_do(data, "is sleeping", data->time_to_sleep,
		number);
	what_does_a_philosopher_do(data, "is thinking", 0, number);
}

void	*life_of_philosopher(void *args)
{
	t_data			*data;
	unsigned int	i;
	int				right;
	int				number;

	data = (t_data *)args;
	number = ++data->number;
	right = number;
	if (number == data->number_of_philo)
		right = 0;
	if (number % 2 == 0)
		ft_usleep(2);
	i = 1;
	while (data->existence)
	{
		if (i % 2 == number % 2)
			life_cycle(data, number - 1, right, number);
		++i;
	}
	return (NULL);
}
