#include "../includes/philo.h"

long	get_time_in_ms()
{
	struct	timeval tv;
	long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

void	set_parameters(t_data *data, int argc, char **argv)
{
	data->number = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_number_of_meals = -1;
	if (argc == 6)
		data->min_number_of_meals = ft_atoi(argv[5]);
	data->start = get_time_in_ms();
}

void	take_forks(t_data *data)
{
//	printf("%ul ");
}

void	put_forks(t_data *data)
{

}

void	eat(t_data *data)
{

}

void	think(t_data *data)
{

}

void	nap(t_data *data)
{

}

void	ft_usleep(long ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() - start < ms)
		usleep(1);
}

void	*life_cycle_of_philosopher(void *args)
{

	t_data *data = (t_data *)args;

//	printf("A = %d\n", a);

//	long	start;
//
//	start = get_time_in_ms();
//	ft_usleep(100);
//	printf("%ld\n", get_time_in_ms() - start);
//	while (1)
//	{
//		take_forks(data);
//		eat(data);
//		put_forks(data);
//		nap(data);
//		think(data);
//	}
//	a++;
	int a = 0;
	pthread_mutex_lock(data->mut);
	a = data->number++;
	printf("A = %d\n", a);
	pthread_mutex_unlock(data->mut);

	return (NULL);
}

int main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 5 && argc != 6)
	{
		printf("ERROR: incorrect number of arguments\n");
		return (1);
	}
	set_parameters(&data, argc, argv);
	data.thread = malloc(sizeof(pthread_t) * data.number_of_philosophers);
	i = 0;
	data.mut = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data.mut, NULL);
	while (i < data.number_of_philosophers)
	{
		pthread_create(&data.thread[i++], NULL, life_cycle_of_philosopher, (void *)&data);
	}
	i = 0;
	while (i < data.number_of_philosophers)
		pthread_join(data.thread[i++], NULL);
	return (0);
}