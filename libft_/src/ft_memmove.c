/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:27:11 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:04:15 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	offset;

	offset = 0;
	if (dst > src)
	{
		offset = len - 1;
		while (offset >= 0)
		{
			*(char *)(dst + offset) = *(char *)(src + offset);
			offset--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
