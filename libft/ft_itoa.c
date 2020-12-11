/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:59:50 by tredfort          #+#    #+#             */
/*   Updated: 2020/11/28 20:55:41 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_number(unsigned int nb)
{
	int		size;

	size = 1;
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*number;
	unsigned int	nb;
	unsigned int	size;
	unsigned int	i;

	if (n < 0)
		nb = (unsigned int)(-1 * n);
	else
		nb = (unsigned int)n;
	size = size_number(nb);
	if (!(number = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	i = 0;
	if (n < 0 && (number[i] = '-'))
		i++;
	i += size;
	number[i] = '\0';
	while (size-- > 0)
	{
		i--;
		number[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}
