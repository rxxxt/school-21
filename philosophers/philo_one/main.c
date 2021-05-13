#include "philo_one.h"

long	get_time_in_ms()
{
	struct timeval tv;
	double time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;

	return ((long)time);
}

void	set_parameters(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_number_of_meals = -1;
	if (argc == 6)
		data->min_number_of_meals = ft_atoi(argv[5]);
	data->start = get_time_in_ms();
}

void	*passed(void *start)
{
	usleep(100000);
	printf("%ld\n", get_time_in_ms() - (long)start);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_data	data;

	data.start = get_time_in_ms();
	data.thread = malloc(sizeof(pthread_t) * 2);
	pthread_create(&data.thread[0], NULL, passed, (void *)data.start);
	usleep(10000);
	pthread_create(&data.thread[0], NULL, passed, (void *)data.start);
	pthread_join(data.thread[0], NULL);
	if (argc >= 5 && argc <= 6)
	{
		set_parameters(&data, argc, argv);
//		init_philosophers();
//		run_philosophers(data);
	}
	return (0);
}