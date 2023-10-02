/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:54:18 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:03:40 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	offset;
	const char		*s1_conv;
	const char		*s2_conv;

	offset = 0;
	s1_conv = s1;
	s2_conv = s2;
	while (offset < n)
	{
		if (*(s1_conv + offset) != *(s2_conv + offset))
		{
			return ((unsigned char) *(s1_conv + offset)
				- (unsigned char) *(s2_conv + offset));
		}
		offset++;
	}
	return (0);
}
