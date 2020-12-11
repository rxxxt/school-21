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

void	initialize(t_opt *opt)
{
	opt->zero = 0;
	opt->minus = 0;
	opt->f_prec = 0;
	opt->plus = 0;
	opt->space = 0;
	opt->hash = 0;
	opt->wth = 0;
	opt->prec = 0;
}

void	correction_options(t_opt *opt)
{
	if (opt->wth < 0 && (opt->minus = 1))
		opt->wth *= -1;
	if (opt->prec < 0 && !(opt->f_prec = 0))
		opt->prec = 0;
	if ((opt->prec && (opt->f_prec = 1)) || (opt->f_prec && !opt->prec))
		opt->zero = 0;
	if (opt->minus)
		opt->zero = 0;
	if (opt->plus)
		opt->space = 0;
}

int		set_options(const char *s, t_opt *o, va_list type, int deep)
{
	if (*s && *s == '-' && (o->minus = 1))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s == '0' && (o->zero = 1))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s == ' ' && (o->space = 1))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s == '+' && (o->plus = 1))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s == '#' && (o->hash = 1))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s == '*' && ((o->wth = va_arg(type, int)) || !o->wth))
		return (set_options(s + 1, o, type, deep + 1));
	else if (*s && *s >= '0' && *s <= '9' && ((o->wth = ft_atoi(s)) || !o->wth))
		return (set_options(s + strnbrlen(s, 1), o, type,
					deep + strnbrlen(s, 1)));
	else if (*s && *s == '.' && (o->f_prec = 1) && *(s + 1) == '*' &&
			((o->prec = va_arg(type, int)) || !o->prec))
		return (set_options(s + 2, o, type, deep + 2));
	else if (*s && *s == '.' && *(s + 1) >= '0' && *(s + 1) <= '9' &&
			((o->prec = ft_atoi(s + 1)) || !o->prec))
		return (set_options(s + strnbrlen(s + 1, 1) + 1, o, type, deep +
					strnbrlen(s + 1, 1) + 1));
	else if (*s == '.' && !(o->prec = 0) && (*(s + 1) < '0' || *(s + 1) > '9'))
		return (set_options(s + 1, o, type, deep + 1));
	return (deep);
}

int		parser(const char **s, va_list type, t_opt *opt, int b_p)
{
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
	t_opt	*opt;
	va_list	type;

	b_p = 0;
	if (!format || !(opt = (t_opt *)malloc(sizeof(t_opt))))
		return (b_p);
	va_start(type, format);
	while (format && *format)
	{
		while (*format && *format != '%')
			b_p += putnchar(*format++, 1);
		if (*format && *format == '%' && *(++format))
		{
			initialize(opt);
			format += set_options(format, opt, type, 0);
			correction_options(opt);
			if (*format)
				b_p += parser(&format, type, opt, 0);
		}
	}
	free(opt);
	va_end(type);
	return (b_p);
}
