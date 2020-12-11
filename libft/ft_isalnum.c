/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:49:45 by tredfort          #+#    #+#             */
/*   Updated: 2020/10/30 13:34:58 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z'));
}
