/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:52:28 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:03:23 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			offset;
	const unsigned char		*s_conv;
	unsigned char			c_conv;

	offset = 0;
	s_conv = s;
	c_conv = c;
	while (offset < n)
	{
		if (*(s_conv + offset) == c_conv)
			return ((void *)s_conv + offset);
		offset++;
	}
	return (NULL);
}
