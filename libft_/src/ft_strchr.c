/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:34:48 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:12:54 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	offset;

	offset = 0;
	if (!(char)c)
		return ((char *)s + ft_strlen(s));
	while (*(s + offset))
	{
		if (*(s + offset) == (char)c)
			return ((char *)s + offset);
		offset++;
	}
	return (NULL);
}
