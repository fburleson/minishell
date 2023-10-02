/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:14:26 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:24:10 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	substrlen(const char *s, unsigned int start, size_t len);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	offset;
	char			*substr;

	offset = 0;
	substr = ft_calloc(substrlen(s, start, len) + 1, sizeof(char));
	if (start >= ft_strlen(s))
		return (substr);
	if (substr)
	{
		while (*(s + start + offset) && offset < len)
		{
			*(substr + offset) = *(s + start + offset);
			offset++;
		}
	}
	return (substr);
}

static unsigned int	substrlen(const char *s, unsigned int start, size_t len)
{
	unsigned int	offset;

	offset = 0;
	if (start >= ft_strlen(s))
		return (0);
	while (offset < len && *(s + start + offset))
		offset++;
	return (offset);
}
