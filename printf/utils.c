/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:33:13 by tredfort          #+#    #+#             */
/*   Updated: 2020/12/10 22:48:47 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		putadr(size_t n)
{
	int count;

	count = 0;
	if (n > 15)
		count = putadr(n / 16);
	count += putnchar((n % 16) + (((n % 16) > 9) ? ('x' - 33) : '0'), 1);
	return (count);
}

int		putnchar(char c, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		putnstr(char *s, int max)
{
	int count;

	count = 0;
	while (s && *s && max-- > 0)
		count += putnchar(*s++, 1);
	return (count);
}

int		puthex_un(unsigned int n, char x)
{
	int count;

	count = 0;
	if (x == 'u')
	{
		if (n > 9)
			count = puthex_un((n / 10), x);
		count += putnchar(n % 10 + '0', 1);
		return (count);
	}
	if (n > 15)
		count = puthex_un((n / 16), x);
	count += putnchar((n % 16) + (((n % 16) > 9) ? (x - 33) : '0'), 1);
	return (count);
}

int		nbrlen(size_t nb, char x)
{
	int len;
	int n;

	n = (x == 'u' ? 10 : 16);
	len = 0;
	if (!nb)
		len++;
	while (nb)
	{
		len++;
		nb /= n;
	}
	return (len);
}
