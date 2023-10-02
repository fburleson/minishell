/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:15:58 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:29:15 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	offset;
	unsigned int	sub_offset;
	char			*str;

	offset = 0;
	sub_offset = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (str)
	{
		while (*(s1 + offset))
		{
			*(str + offset) = *(s1 + offset);
			offset++;
		}
		while (*(s2 + sub_offset))
		{
			*(str + offset) = *(s2 + sub_offset);
			offset++;
			sub_offset++;
		}
	}
	return (str);
}
