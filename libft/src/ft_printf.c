/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:55:19 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:28:53 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

static int	printformat(const char format, va_list args);
static int	printstrf(va_list args);

int	ft_printf(const char *format, ...)
{
	unsigned int	offset;
	int				nch;
	va_list			args;

	offset = 0;
	nch = 0;
	va_start(args, format);
	while (*(format + offset))
	{
		if (*(format + offset) == '%' && *(format + offset + 1))
		{
			offset++;
			nch += printformat(*(format + offset), args);
		}
		else if (*(format + offset) != '%')
			nch += write(STDOUT_FILENO, format + offset, 1);
		offset++;
	}
	va_end(args);
	return (nch);
}

static int	printformat(const char format, va_list args)
{
	if (format == '%')
		return (write(STDOUT_FILENO, "%", 1));
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), STDOUT_FILENO));
	if (format == 's')
		return (printstrf(args));
	if (format == 'i' || format == 'd')
		return (ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO));
	if (format == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), STDOUT_FILENO));
	if (format == 'x' || format == 'X')
		return (ft_puthex_fd(va_arg(args, int), STDOUT_FILENO, format == 'X'));
	if (format == 'p')
		return (ft_putptr_fd(va_arg(args, void *), STDOUT_FILENO));
	return (0);
}

static int	printstrf(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
		return (ft_putstr_fd(str, STDOUT_FILENO));
	return (ft_putstr_fd("(null)", STDOUT_FILENO));
}
