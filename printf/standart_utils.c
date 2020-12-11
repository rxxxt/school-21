/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:07:31 by tredfort          #+#    #+#             */
/*   Updated: 2020/12/10 23:59:36 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		strnbrlen(const char *s, int p)
{
	int	count;

	count = 0;
	if (p == 1)
		while (s && *s >= '0' && *s <= '9' && (s++))
			count++;
	else if (p == 2)
		while (s && *s && s++)
			count++;
	return (count);
}

int		ft_atoi(const char *str)
{
	int nb;
	int sign;

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
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}
