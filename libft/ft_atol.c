/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:58:43 by tredfort          #+#    #+#             */
/*   Updated: 2021/05/14 00:03:56 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	unsigned long	nb;
	long			sign;

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
		if (sign == -1 && nb > LONG_MAX)
			return (LONG_MIN);
		if (sign == 1 && nb >= LONG_MAX)
			return (LONG_MAX);
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * (long)nb);
}
