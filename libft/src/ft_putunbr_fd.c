/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:42:58 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/11/02 17:54:29 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	str[13];
	int		str_len;
	int		nch;

	nch = 0;
	if (n == 0)
		*str = '0';
	str_len = 0;
	while (n != 0)
	{
		*(str + str_len++) = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (str_len > 0)
		str_len--;
	while (str_len >= 0)
		nch += write(fd, &*(str + str_len--), 1);
	return (nch);
}
