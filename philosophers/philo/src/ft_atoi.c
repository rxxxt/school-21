#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (sign == -1 && nb > INT32_MAX)
			return (INT32_MIN);
		if (sign == 1 && nb >= INT32_MAX)
			return (INT32_MAX);
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * (int)nb);
}
