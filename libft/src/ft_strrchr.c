/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:38:56 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:23:50 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		offset;
	char	*marked_ptr;

	offset = 0;
	marked_ptr = (char *) 0;
	if (!(char)c)
		return ((char *)s + ft_strlen(s));
	while (*(s + offset))
	{
		if (*(s + offset) == (char)c)
		{
			marked_ptr = (char *)s + offset;
		}
		offset++;
	}
	return (marked_ptr);
}
