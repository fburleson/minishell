/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:36:01 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:23:36 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	unsigned int	offset;
	unsigned int	sub_offset;
	char			*needle_mark;

	if (*needle == 0 || needle == hay)
		return ((char *)hay);
	offset = 0;
	while (offset < len && *(hay + offset))
	{
		if (*(hay + offset) == *needle)
		{
			needle_mark = (char *)hay + offset;
			sub_offset = 0;
			while (*(hay + offset + sub_offset) == *(needle + sub_offset)
				&& offset + sub_offset < len && *(needle + sub_offset))
				sub_offset++;
			if (!(*(needle + sub_offset)))
				return (needle_mark);
			else
				needle_mark = NULL;
		}
		offset++;
	}
	return (NULL);
}
