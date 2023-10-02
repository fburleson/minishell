/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:46:54 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/11/03 15:44:07 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	digittohex(int n, int toupper);

int	ft_puthex_fd(int n, int fd, int toupper)
{
	char	str[13];
	int		str_len;
	int		nch;
	long	longn;

	longn = (long) n;
	nch = 0;
	if (longn == 0)
		*str = '0';
	if (n == INT32_MIN)
		return (write(fd, "80000000", 8));
	if (longn < 0)
		longn = 4294967295 - ft_abs(n) + 1;
	str_len = 0;
	while (longn != 0)
	{
		*(str + str_len++) = digittohex(ft_abs(longn % 16), toupper);
		longn /= 16;
	}
	if (str_len > 0)
		str_len--;
	while (str_len >= 0)
		nch += write(fd, &*(str + str_len--), 1);
	return (nch);
}

static char	digittohex(int n, int toupper)
{
	if (toupper)
		toupper = 32;
	if (n >= 0 && n <= 9)
		return (n + 48);
	if (n >= 10 && n <= 15)
		return ('a' + n - 10 - toupper);
	return (0);
}
