#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
ssize_t	ft_read(int fd, void *buf, size_t count);
ssize_t	ft_write(int fd, const void *buf, size_t count);

#endif