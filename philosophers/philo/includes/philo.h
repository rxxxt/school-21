/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:55:52 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:55:54 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define INCORRECT_NUMBER_OF_ARGUMENTS	1
# define INVALID_ARGUMENT				2
# define NO_MEMORY_ALLOCATED			3

typedef struct s_philo
{
	int				number_of_meals;
	int				last_meal;
	pthread_mutex_t	fork;
}				t_philo;

typedef struct s_data
{
	int					existence;
	int					number;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					min_number_of_meals;
	int					timeout;
	long				start;
	pthread_mutex_t		freedom_of_speech;
	t_philo				*philo;
}				t_data;

int			ft_atoi(const char *str);
int			error_manager(int errno);
int			valid_arguments(int argc, char **argv);
void		observe_the_philosophers(t_data *data);
void		*life_of_philosopher(void *args);
long		get_time_in_ms(void);
void		ft_usleep(long ms);

#endif
