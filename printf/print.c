/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:36:39 by tredfort          #+#    #+#             */
/*   Updated: 2020/12/10 23:08:41 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printadr(size_t n, t_opt *opt)
{
	int count;
	int wth;
	int pre;
	int len;

	count = 0;
	len = (opt->f_prec && !opt->prec && !n ? 0 : nbrlen(n, 'x'));
	pre = opt->prec - len;
	wth = opt->wth - 2 - len;
	if (!opt->minus && !opt->zero && wth > 0)
		count += putnchar(' ', wth);
	count += putnstr("0x", 2);
	if (opt->f_prec)
		count += putnchar('0', pre);
	if (opt->zero && !opt->f_prec && wth > 0)
		count += putnchar('0', wth);
	if (!(opt->f_prec && !opt->prec && !n))
		count += putadr(n);
	if (opt->minus && wth > 0)
		count += putnchar(' ', wth);
	return (count);
}

int		printchar(char c, t_opt *opt)
{
	int count;
	int wth;

	count = 0;
	wth = opt->wth - 1;
	if (!opt->minus && !opt->zero && wth > 0)
		count += putnchar(' ', wth);
	if (opt->zero && wth > 0)
		count += putnchar('0', wth);
	count += putnchar(c, 1);
	if (opt->minus && wth > 0)
		count += putnchar(' ', wth);
	return (count);
}

int		printnbr(int n, t_opt *opt, int count)
{
	unsigned int	nb;
	int				pre;
	int				wth;
	int				sign;

	sign = (n < 0 ? 1 : 0);
	nb = (unsigned int)((n < 0 ? -1 : 1) * n);
	pre = opt->prec - nbrlen(nb, 'u');
	wth = opt->wth - opt->prec + (pre < 0 ? pre : 0) - opt->space;
	wth += (opt->f_prec && !opt->prec && !n ? 1 : 0) - (opt->plus ? 1 : sign);
	if (opt->space)
		count += putnchar(' ', 1);
	if (!opt->minus && !opt->zero && wth > 0)
		count += putnchar(' ', wth);
	if (n < 0 || opt->plus)
		count += putnchar('-', sign) + putnchar('+', opt->plus - sign);
	if (opt->zero && !opt->f_prec && wth > 0)
		count += putnchar('0', wth);
	if (opt->f_prec && pre > 0)
		count += putnchar('0', pre);
	if (!(opt->f_prec && !opt->prec && !nb))
		count += puthex_un(nb, 'u');
	if (opt->minus && wth > 0)
		count += putnchar(' ', wth);
	return (count);
}

int		printunbr(unsigned int n, char x, t_opt *opt)
{
	int pre;
	int wth;
	int count;

	count = 0;
	pre = opt->prec - nbrlen(n, x);
	wth = opt->wth - opt->prec + (pre < 0 ? pre : 0);
	wth += (opt->f_prec && !opt->prec && !n ? 1 : 0);
	wth -= (opt->hash && x != 'u' && n? 2 : 0);
	if (!opt->minus && !opt->zero && wth > 0)
		count += putnchar(' ', wth);
	if (opt->hash && n && x != 'u')
		count += putnchar('0', 1) + putnchar(x, 1);
	if (opt->zero && !opt->f_prec && wth > 0)
		count += putnchar('0', wth);
	if (opt->f_prec && pre > 0)
		count += putnchar('0', pre);
	if (!(opt->f_prec && !opt->prec && !n))
		count += puthex_un(n, x);
	if (opt->minus && wth > 0)
		count += putnchar(' ', wth);
	return (count);
}

int		printstr(char *s, t_opt *opt)
{
	int count;
	int pre;
	int wth;
	int len;

	if (!s)
		s = "(null)";
	count = 0;
	len = strnbrlen(s, 2);
	pre = (opt->f_prec && opt->prec < len) ? opt->prec : len;
	wth = opt->wth - pre;
	if (!opt->minus && !opt->zero && wth > 0)
		count += putnchar(' ', wth);
	if (opt->zero && !opt->f_prec && wth > 0)
		count += putnchar('0', wth);
	if (pre > 0)
		count += putnstr(s, pre);
	if (opt->minus && wth > 0)
		count += putnchar(' ', wth);
	return (count);
}
