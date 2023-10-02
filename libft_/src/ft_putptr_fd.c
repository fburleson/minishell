/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:26:37 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/11/03 15:54:00 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	digittohex(int n);

int	ft_putptr_fd(void *ptr, int fd)
{
	char				str[16];
	int					str_len;
	int					nch;
	unsigned long long	address;

	address = (unsigned long long) ptr;
	nch = 0;
	if (address == 0)
		*str = '0';
	str_len = 0;
	while (address != 0)
	{
		*(str + str_len++) = digittohex(ft_abs(address % 16));
		address /= 16;
	}
	nch += write(fd, "0x", 2);
	if (str_len > 0)
		str_len--;
	while (str_len >= 0)
		nch += write(fd, &*(str + str_len--), 1);
	return (nch);
}

static char	digittohex(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	if (n >= 10 && n <= 15)
		return ('a' + n - 10);
	return (0);
}
