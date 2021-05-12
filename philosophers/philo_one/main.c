#include "philo_one.h"

void	set_parameters(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_number_of_meals = -1;
	if (argc == 6)
		data->min_number_of_meals = ft_atoi(argv[5]);
}

long	get_time()
{
	struct timeval tv;
	double time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;

	return ((long)time);
}

int main(int argc, char **argv)
{
	t_data	data;
	long	time;

	time = get_time();
	usleep(100000);
	printf("%ld\n", get_time() - time);
	if (argc >= 5 && argc <= 6)
	{
		set_parameters(&data, argc, argv);
//		init_philosophers();
//		run_philosophers(data);
	}
	return (0);
}