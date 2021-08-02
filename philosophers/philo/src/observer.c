#include "../includes/philo.h"

static void	checking_the_number_of_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (data->philo[i].number_of_meals < data->min_number_of_meals)
			break ;
		++i;
	}
	if (i == data->number_of_philo)
		data->existence = 0;
}

static int	is_the_philosopher_dead(t_data *data)
{
	int	i;
	int	current_time;

	i = 0;
	while (i < data->number_of_philo)
	{
		current_time = (int)(get_time_in_ms() - data->start);
		if (current_time - data->philo[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->freedom_of_speech);
			printf("%ld ms %d died\n", get_time_in_ms() - data->start, i + 1);
			data->existence = 0;
			return (1);
		}
		++i;
	}
	return (0);
}

void	observe_the_philosophers(t_data *data)
{
	data->start = get_time_in_ms();
	while (data->existence)
	{
		if (is_the_philosopher_dead(data))
			break ;
		if (data->min_number_of_meals > 0)
			checking_the_number_of_meals(data);
//		ft_usleep(1);
	}
}
