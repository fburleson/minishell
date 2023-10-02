/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:58:00 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:27:26 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	nchars(int n);

char	*ft_itoa(int n)
{
	int		is_neg;
	char	*str;
	size_t	str_len;

	is_neg = n < 0;
	str = ft_calloc(nchars(n) + is_neg, sizeof(char));
	if (!str)
		return (NULL);
	*str = '0';
	str_len = 0;
	while (n != 0)
	{
		*(str + str_len) = ft_abs(n % 10) + 48;
		n /= 10;
		str_len++;
	}
	if (is_neg)
		*(str + str_len) = '-';
	ft_strrev(str);
	return (str);
}

static unsigned int	nchars(int n)
{
	unsigned int	count;

	count = 0;
	n = ft_abs(n);
	if (!n)
		return (2);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}
