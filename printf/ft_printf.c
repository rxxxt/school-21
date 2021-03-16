/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:32:31 by tredfort          #+#    #+#             */
/*   Updated: 2020/12/10 23:55:37 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(const char **str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*(*str) && ((*(*str) >= '\t' && *(*str) <= '\r') || *(*str) == ' '))
		(*str)++;
	if (*(*str) == '-')
		sign = -1;
	if (*(*str) == '-' || *(*str) == '+')
		(*str)++;
	while (*(*str) && *(*str) >= '0' && *(*str) <= '9')
		nb = nb * 10 + *(*str)++ - '0';
	return (sign * nb);
}

void	initialize(t_opt *opt)
{
	opt->zero = 0;
	opt->minus = 0;
	opt->plus = 0;
	opt->space = 0;
	opt->hash = 0;
	opt->width = 0;
	opt->precision = -1;
}

void	parser(const char **s, t_opt *opt, va_list type)
{
	while (*(*s) && (*(*s) == '-' || *(*s) == '+' || *(*s) == ' ' || *(*s) ==
	'.' || *(*s) == '#' || *(*s) == '*' || (*(*s) >= '0' && *(*s) <= '9')))
	{
		if (*(*s) == '0' && ++(*s))
			opt->zero = 1;
		else if (*(*s) == '-' && ++(*s))
			opt->minus = 1;
		else if (*(*s) == ' ' && ++(*s))
			opt->space = 1;
		else if (*(*s) == '+' && !(opt->space = 0) && ++(*s))
			opt->plus = 1;
		else if (*(*s) == '#' && ++(*s))
			opt->hash = 1;
		else if (*(*s) == '*' && ++(*s))
			opt->width = va_arg(type, int);
		else if (*(*s) >= '0' && *(*s) <= '9')
			opt->width = ft_atoi(s);
		else if (*(*s) == '.' && *((*s) + 1) == '*' && (*s += 2))
			opt->precision = va_arg(type, int);
		else if (*(*s) == '.' && *((*s) + 1) >= '0' && *((*s) + 1) <= '9' && ++(*s))
			opt->precision = ft_atoi(s);
		else if (*(*s) == '.' && ++(*s))
			opt->precision = 0;
	}
}

/*
void	parser(const char **s, t_opt *opt, va_list type)
{
	if (*(*s) == '0' && (opt->zero = 1) && ++(*s))
		parser(s, opt, type);
	else if (*(*s) == '-' && (opt->minus = 1) && ++(*s))
		parser(s, opt, type);
	else if (*(*s) == ' ' && (opt->space = 1) && ++(*s))
		parser(s, opt, type);
	else if (*(*s) == '+' && (opt->plus = 1) && ++(*s))
		parser(s, opt, type);
	else if (*(*s) == '#' && (opt->hash = 1) && ++(*s))
		parser(s, opt, type);
	else if (*(*s) == '*' && ++(*s) && ((opt->width = va_arg(type, int)) ||
		!opt->width))
		parser(s, opt, type);
	else if (*(*s) >= '0' && *(*s) <= '9' && ((opt->width = ft_atoi(s)) ||
		!opt->width))
		parser(s, opt, type);
	else if (*(*s) == '.' && *((*s) + 1) == '*' && (*s += 2) &&
		((opt->precision = va_arg(type, int)) || !opt->precision))
		parser(s, opt, type);
	else if (*(*s) == '.' && *((*s) + 1) >= '0' && *((*s) + 1) <= '9' && ++(*s)
		&& ((opt->precision = ft_atoi(s)) || !opt->precision))
		parser(s, opt, type);
	else if (*(*s) == '.' && !(opt->precision = 0) && ++(*s))
		parser(s, opt, type);
}
*/

int		processing(const char **s, va_list type, t_opt *opt)
{
	int	b_p;

	b_p = 0;
	if (opt->plus)
		opt->space = 0;
	if (opt->width < 0 && (opt->minus = 1))
		opt->width *= -1;
	if (opt->precision >= 0 || opt->minus)
		opt->zero = 0;
	if (*(*s) && *(*s) == '%' && *(*s)++)
		b_p += printchar('%', opt);
	else if (*(*s) && *(*s) == 'c' && *(*s)++)
		b_p += printchar(va_arg(type, int), opt);
	else if (*(*s) && *(*s) == 's' && *(*s)++)
		b_p += printstr(va_arg(type, char *), opt);
	else if (*(*s) && (*(*s) == 'd' || *(*s) == 'i') && *(*s)++)
		b_p += printnbr(va_arg(type, int), opt, 0);
	else if (*(*s) && (*(*s) == 'u' || *(*s) == 'x' || *(*s) == 'X'))
		b_p += printunbr(va_arg(type, unsigned int), *(*s)++, opt);
	else if (*(*s) && *(*s) == 'p' && *(*s)++)
		b_p += printadr(va_arg(type, size_t), opt);
	return (b_p);
}

int		ft_printf(const char *format, ...)
{
	int		b_p;
	t_opt	opt;
	va_list	type;

	b_p = 0;
	if (!format)
		return (b_p);
	va_start(type, format);
	while (format && *format)
	{
		while (*format && *format != '%')
			b_p += putnchar(*format++, 1);
		if (*format && *format == '%' && *(++format))
		{
			initialize(&opt);
			parser(&format, &opt, type);
			if (*format)
				b_p += processing(&format, type, &opt);
		}
	}
	va_end(type);
	return (b_p);
}
