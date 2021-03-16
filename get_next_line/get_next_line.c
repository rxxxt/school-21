/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:33:19 by tredfort          #+#    #+#             */
/*   Updated: 2020/11/24 17:52:11 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *tmp_buf, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (tmp_buf)
	{
		if ((ptr_n = ft_strchr(tmp_buf, '\n')))
		{
			*ptr_n++ = '\0';
			*line = ft_strdup(tmp_buf);
			ft_strcpy(tmp_buf, ptr_n);
		}
		else
		{
			*line = ft_strdup(tmp_buf);
			free(tmp_buf);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr_n);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp_buf;
	char		*buf;
	char		*ptr_n;
	size_t		rs;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(buf = malloc(sizeof(char) *
                                                             (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, buf, 0) < 0)
    {
	    free(buf);
        return (-1);
    }
	ptr_n = next_line(tmp_buf, line);
	while (ptr_n == NULL && (rs = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rs] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n++ = '\0';
			tmp_buf = ft_strdup(ptr_n);
		}
		*line = ft_strjoin(line, buf);
	}
	free(buf);
	if (ptr_n)
		return (1);
	tmp_buf = NULL;
	return (0);
}
