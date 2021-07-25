#include "../includes/philo.h"

long	get_time_in_ms()
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() - start < ms)
		usleep(1);
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

int	validation(int argc, char** argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			printf("ERROR: invalid argument\n");
			return (0);
		}
		++i;
	}
	return (1);
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

void	*life_cycle_of_philosopher(void *args)
{
	t_data *data = (t_data *)args;
	unsigned int	i;
	int				left;
	int				right;
	int				number;

	number = ++data->number;
	left = number - 1;
	if (number == data->number_of_philosophers)
		right = 0;
	else
		right = number;


//	printf("A = %d\n", a);

//	long	start;
//
//	start = get_time_in_ms();
//	ft_usleep(100);
//	printf("%ld\n", get_time_in_ms() - start);

	i = 1;
	while (i < 5)
	{
		if (i % 2 == number % 2)
		{
			pthread_mutex_lock(&data->fork[left]);
			printf("%ld ms %d has taken a %d fork\n", get_time_in_ms() - data->start, number, left);
			pthread_mutex_lock(&data->fork[right]);
			printf("%ld ms %d has taken a %d fork\n", get_time_in_ms() - data->start, number, right);
			ft_usleep(1);
			pthread_mutex_unlock(&data->fork[left]);
			pthread_mutex_unlock(&data->fork[right]);
		}
		else
			ft_usleep(2);
		++i;
//		take_forks(data);
//		eat(data);
//		put_forks(data);
//		nap(data);
//		think(data);
	}

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
	if (validation(argc, argv)) // TODO: проверить на отрицательные значения
	{
		set_parameters(&data, argc, argv);
		data.thread = malloc(sizeof(pthread_t) * data.number_of_philosophers);
		i = 0;
		data.fork = malloc(sizeof(pthread_mutex_t*) * data.number_of_philosophers);
		while (i++ < data.number_of_philosophers)
		{
			pthread_mutex_init(&data.fork[i], NULL);
			pthread_create(&data.thread[i], NULL, life_cycle_of_philosopher, (void *)&data);
//			pthread_detach(data.thread[i]);
		}
		ft_usleep(10);
		i = 0;
		while (i < data.number_of_philosophers)
			pthread_join(data.thread[i++], NULL);
	}
	return (0);
}