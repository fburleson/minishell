/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:22:39 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:28:49 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		offset;
	char				*dst_conv;
	const char			*src_conv;

	dst_conv = dst;
	src_conv = src;
	offset = 0;
	if (dst || src)
	{
		while (offset < n)
		{
			*(dst_conv + offset) = *(src_conv + offset);
			offset++;
		}
	}
	return (dst);
}
