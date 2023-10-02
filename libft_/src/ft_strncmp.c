/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:11 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:23:18 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	offset;
	unsigned char	*s1_conv;
	unsigned char	*s2_conv;

	offset = 0;
	s1_conv = (unsigned char *)s1;
	s2_conv = (unsigned char *)s2;
	while (offset < n && (*(s1_conv + offset) || *(s2_conv + offset)))
	{
		if (*(s1_conv + offset) != *(s2_conv + offset))
			return (*(s1_conv + offset) - *(s2_conv + offset));
		offset++;
	}
	return (0);
}
