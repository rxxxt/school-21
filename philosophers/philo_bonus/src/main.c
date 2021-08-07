/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:40:11 by tredfort          #+#    #+#             */
/*   Updated: 2021/08/07 22:40:13 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	destroy_semaphores(t_data *data)
{
	sem_close(data->sem_freedom_of_speech);
	sem_close(data->sem_waiter);
	sem_close(data->sem_forks);
	sem_unlink(PRINT);
	sem_unlink(WAITER);
	sem_unlink(FORKS);
}

static void	kill_all_processes(int *pid, int size)
{
	int	i;

	i = 0;
	while (i < size)
		kill(pid[i++], SIGKILL);
}

static void	start_processes(t_data *data, int *pid)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			error_manager(FORK_FAILED);
		data->number = i + 1;
		if (!pid[i])
		{
			observe_the_philosophers(data);
			exit(0);
		}
		++i;
	}
}

static void	wait_for_processes(t_data *data, int *pid)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->number_of_philo)
	{
		waitpid(0, &status, 0);
		if (status)
		{
			kill_all_processes(pid, data->number_of_philo);
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*pid;

	if (argc != 5 && argc != 6)
		error_manager(INCORRECT_NUMBER_OF_ARGUMENTS);
	if (!valid_arguments(argc, argv))
		error_manager(INVALID_ARGUMENT);
	initialization(&data, argc, argv);
	pid = (int *)malloc(sizeof(int) * data.number_of_philo);
	if (!pid)
		error_manager(NO_MEMORY_ALLOCATED);
	start_processes(&data, pid);
	wait_for_processes(&data, pid);
	destroy_semaphores(&data);
	free(pid);
	return (0);
}
