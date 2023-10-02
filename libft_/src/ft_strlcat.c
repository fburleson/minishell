/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:29:36 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:22:21 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	
	ft_clampui(unsigned int x, unsigned int min, unsigned int max);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	start_cat;
	unsigned int	offset;
	size_t			out;

	out = ft_clampui(dstsize, 0, ft_strlen(dst)) + ft_strlen(src);
	if (dstsize <= 0)
		return (out);
	start_cat = ft_strlen(dst);
	offset = 0;
	while (start_cat + offset < dstsize - 1 && *(src + offset))
	{
		*(dst + start_cat + offset) = *(src + offset);
		offset++;
	}
	if (start_cat + offset != dstsize)
		*(dst + start_cat + offset) = 0;
	return (out);
}

static unsigned int	
	ft_clampui(unsigned int x, unsigned int min, unsigned int max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	return (x);
}
