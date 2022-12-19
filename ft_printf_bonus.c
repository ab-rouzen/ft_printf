/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:27:38 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/19 16:40:39 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putchar_fd(char c, int fd)
{
	static int	i = 0;
	int			hol;

	if (fd == 1)
	{
		write(fd, &c, 1);
		i++;
		return (0);
	}
	return (hol = i, i = 0, hol);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	else
		ft_putstr_fd("(null)", fd);
}

void	p_uint(char c, va_list args, int *flags)
{
	unsigned int	m;

	if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
	{
		m = va_arg(args, unsigned int);
		if (flags[2] == 1 && m)
			ft_putstr_fd("0x", FD);
		ft_putnbr_base(m, "0123456789abcdef");
	}
	if (c == 'X')
	{
		m = va_arg(args, unsigned int);
		if (flags[2] == 1 && m)
			ft_putstr_fd("0X", FD);
		ft_putnbr_base(m, "0123456789ABCDEF");
	}
	if (c == 'p')
	{
		ft_putstr_fd("0x", FD);
		ft_uputnbr_base(va_arg(args, unsigned long int), "0123456789abcdef");
	}
}

void	p_int(char c, va_list args, int *flags)
{
	int	m;

	m = va_arg(args, int);
	if (c == 'i' || c == 'd')
	{
		if (m >= 0 && flags[1] == 1)
			ft_putchar_fd('+', FD);
		else if (m >= 0 && flags[0] == 1)
			ft_putchar_fd(' ', FD);
		ft_putnbr_base(m, "0123456789");
	}
	if (c == 'c')
		ft_putchar_fd(m, FD);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		flags[3];

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_putchar_fd(str[i++], FD);
		if (!str[i++])
			break ;
		init(flags);
		if (str[i] == '+' || str[i] == ' ' || str[i] == '#')
			i += dflags((char *)&str[i], &flags[0]);
		if (str[i] == 'i' || str[i] == 'd' || str[i] == 'c')
			p_int(str[i], args, flags);
		if (str[i] == 's')
			ft_putstr_fd(va_arg(args, char *), FD);
		if (str[i] == 'u' || str[i] == 'x' || str[i] == 'p' || str[i] == 'X')
			p_uint(str[i], args, flags);
		if (str[i++] == '%')
			ft_putchar_fd('%', FD);
	}
	return (va_end(args), ft_putchar_fd('\0', 2));
}
