/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:09:35 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:04:31 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int		offset;
	char				*b_conv;

	b_conv = b;
	offset = 0;
	while (offset < len)
	{
		*(b_conv + offset) = (unsigned char)c;
		offset++;
	}
	return (b);
}
