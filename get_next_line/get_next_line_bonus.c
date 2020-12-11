/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:33:19 by tredfort          #+#    #+#             */
/*   Updated: 2020/11/17 00:59:21 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(int fd, char **tmp_buf, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (tmp_buf[fd])
	{
		if ((ptr_n = ft_strchr(tmp_buf[fd], '\n')))
		{
			*ptr_n++ = '\0';
			*line = ft_strdup(tmp_buf[fd]);
			ft_strcpy(tmp_buf[fd], ptr_n);
		}
		else
		{
			*line = ft_strdup(tmp_buf[fd]);
			free(tmp_buf[fd]);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr_n);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp_buf[1024];
	char		*buf;
	char		*ptr_n;
	size_t		rs;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(buf = malloc(sizeof(char) *
			(BUFFER_SIZE + 1))) || read(fd, buf, 0) < 0)
		return (-1);
	ptr_n = next_line(fd, tmp_buf, line);
	while (!ptr_n && (rs = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rs] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n++ = '\0';
			tmp_buf[fd] = ft_strdup(ptr_n);
		}
		*line = ft_strjoin(line, buf);
	}
	free(buf);
	if (ptr_n)
		return (1);
	tmp_buf[fd] = NULL;
	return (0);
}
