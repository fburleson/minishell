/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:52:14 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:13:21 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s1cpy;
	unsigned int	offset;

	s1cpy = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!s1cpy)
		return (NULL);
	offset = 0;
	while (*(s1 + offset))
	{
		*(s1cpy + offset) = *(s1 + offset);
		offset++;
	}
	return (s1cpy);
}
