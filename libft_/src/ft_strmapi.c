/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:38:55 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:23:06 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	offset;
	char			*str;

	offset = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str)
	{
		while (*(s + offset))
		{
			*(str + offset) = (*f)(offset, *(s + offset));
			offset++;
		}
	}
	return (str);
}
