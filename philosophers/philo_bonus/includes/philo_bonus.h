/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:38:15 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:38:17 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# define INCORRECT_NUMBER_OF_ARGUMENTS	1
# define INVALID_ARGUMENT				2
# define NO_MEMORY_ALLOCATED			3
# define SEMAPHORE_FAILED				4
# define FORK_FAILED					5

# define FORKS		"sem_forks"
# define WAITER		"sem_waiter"
# define PRINT		"sem_freedom_of_speech"

typedef struct s_data
{
	int		existence;
	int		number;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		min_number_of_meals;
	int		number_of_meals;
	int		last_meal;
	long	start;
	sem_t	*sem_freedom_of_speech;
	sem_t	*sem_forks;
	sem_t	*sem_waiter;
}				t_data;

int			ft_atoi(const char *str);
void		error_manager(int errno);
int			valid_arguments(int argc, char **argv);
void		initialization(t_data *data, int argc, char **argv);
void		observe_the_philosophers(t_data *data);
void		*life_of_philosopher(void *arg);
long		get_time_in_ms(void);
void		ft_usleep(long ms);

#endif
