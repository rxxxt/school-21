/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:32:46 by tredfort          #+#    #+#             */
/*   Updated: 2020/12/10 23:24:13 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_opt
{
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			width;
	int			precision;
}				t_opt;

int				printadr(size_t n, t_opt *opt);
int				printchar(char c, t_opt *opt);
int				printnbr(int n, t_opt *opt, int count);
int				printunbr(unsigned int n, char x, t_opt *opt);
int				printstr(char *s, t_opt *opt);
int				putadr(size_t n);
int				putnchar(char c, int max);
int				puthex_un(unsigned int n, char x);
int				strnbrlen(const char *s, int p);
int				nbrlen(size_t nb, char x);
int				ft_atoi(const char **str);
int				ft_printf(const char *format, ...);
int				processing(const char **s, va_list type, t_opt *opt);
void			parser(const char **s, t_opt *opt, va_list type);
void			initialize(t_opt *opt);

#endif
