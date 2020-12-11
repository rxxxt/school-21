/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:33:41 by tredfort          #+#    #+#             */
/*   Updated: 2020/11/17 01:42:25 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*(s++) == c)
			return ((char *)(--s));
	if (!c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char			*new;
	unsigned int	i;

	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*new;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	tmp = *s1;
	while (*(*s1))
		new[i++] = *(*s1)++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	free(tmp);
	return (new);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
