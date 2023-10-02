/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:02:34 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/10/02 14:16:13 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*malloc_buff(void)
{
	char	*buff;

	buff = malloc(1);
	if (!buff)
		return (NULL);
	*buff = '\0';
	return (buff);
}

char	*gnl_strjoin(const char *line_buff, const char *next_buff)
{
	unsigned int	offset;
	unsigned int	sub_offset;
	char			*str;

	offset = 0;
	sub_offset = 0;
	str = malloc(gnl_strlen(line_buff, '\0')
			+ gnl_strlen(next_buff, '\0') + 1);
	if (!str)
		return (NULL);
	while (*(line_buff + offset))
	{
		*(str + offset) = *(line_buff + offset);
		offset++;
	}
	while (*(next_buff + sub_offset))
	{
		*(str + offset) = *(next_buff + sub_offset);
		offset++;
		sub_offset++;
	}
	*(str + offset) = '\0';
	return (str);
}

size_t	gnl_strlen(const char *s, int term)
{
	unsigned int	offset;

	offset = 0;
	while (*(s + offset) && *(s + offset) != (char)term)
		offset++;
	return (offset);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned int	offset;

	offset = 0;
	if (!(char)c)
		return ((char *)s + gnl_strlen(s, '\0'));
	while (*(s + offset))
	{
		if (*(s + offset) == (char)c)
			return ((char *)s + offset);
		offset++;
	}
	return (NULL);
}

char	*free_and_return(char **buff, char	**buff2)
{
	free(*buff);
	*buff = NULL;
	if (buff2)
	{
		free(*buff2);
		*buff = NULL;
	}
	return (NULL);
}
