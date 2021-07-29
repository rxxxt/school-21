#include "../includes/philo.h"

void	initialization(t_data *data, int argc, char **argv)
{
	int	i;

	data->existence = 1;
	data->number = 0;
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_number_of_meals = -1;
	if (argc == 6)
		data->min_number_of_meals = ft_atoi(argv[5]);
	data->start = get_time_in_ms();
	pthread_mutex_init(&data->freedom_of_speech, NULL);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philo)
		return ;
	memset(data->philo, 0, sizeof(t_philo) * data->number_of_philo);
	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->philo[i++].fork, NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread;
	t_data		data;
	int			i;

	if (argc != 5 && argc != 6)
		return (error_manager(INCORRECT_NUMBER_OF_ARGUMENTS));
	if (!valid_arguments(argc, argv))
		return (error_manager(INVALID_ARGUMENT));
	initialization(&data, argc, argv);
	if (!data.philo)
		return (error_manager(NO_MEMORY_ALLOCATED));
	i = 0;
	while (i < data.number_of_philo)
	{
		pthread_create(&thread, NULL, life_of_philosopher, (void *) &data);
		pthread_detach(thread);
		++i;
	}
	observe_the_philosophers(&data);
	ft_usleep(100);
	free(data.philo);
	return (0);
}
