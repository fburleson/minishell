/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:22:33 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/11/02 17:54:22 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		is_neg;
	int		str_len;
	int		nch;

	nch = 0;
	is_neg = n < 0;
	if (n == 0)
		*str = '0';
	str_len = 0;
	while (n != 0)
	{
		*(str + str_len++) = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (is_neg)
		*(str + str_len) = '-';
	else if (str_len > 0)
		str_len--;
	while (str_len >= 0)
		nch += write(fd, &*(str + str_len--), 1);
	return (nch);
}
