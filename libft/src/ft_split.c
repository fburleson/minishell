/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:20:56 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:12:41 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	nelements(const char *s, char c);
static char			*allocstr(const char *s, char c);
static size_t		ft_splitlen(const char *s, const char c);
static char			**freearr(char **strarr, unsigned int size);

char	**ft_split(const char *s, char c)
{
	char			**strarr;
	unsigned int	offset;
	unsigned int	s_offset;
	char			*next;

	strarr = ft_calloc(nelements(s, c), sizeof(char *));
	if (!strarr)
		return (NULL);
	offset = 0;
	s_offset = 0;
	next = (char *)s + s_offset;
	while (offset < nelements(s, c) - 1)
	{
		while (*(s + s_offset) && *(s + s_offset) == c)
			s_offset++;
		next = (char *)s + s_offset;
		*(strarr + offset) = allocstr(next, c);
		if (!*(strarr + offset))
			return (freearr(strarr, offset));
		while (*(s + s_offset) && *(s + s_offset) != c)
			s_offset++;
		offset++;
	}
	return (strarr);
}

static unsigned int	nelements(const char *s, char c)
{
	unsigned int	offset;
	unsigned int	n;

	offset = 0;
	n = 0;
	while (*(s + offset))
	{
		if (*(s + offset) != c)
			n++;
		while (*(s + offset) != c && *(s + offset))
			offset++;
		while (*(s + offset) == c && *(s + offset))
			offset++;
	}
	return (n + 1);
}

static char	*allocstr(const char *s, char c)
{
	char			*str;
	unsigned int	offset;

	offset = 0;
	str = ft_calloc(ft_splitlen(s, c) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (*(s + offset) && *(s + offset) != c)
	{
		*(str + offset) = *(s + offset);
		offset++;
	}
	return (str);
}

static size_t	ft_splitlen(const char *s, const char c)
{
	unsigned int	offset;

	offset = 0;
	while (*(s + offset) && *(s + offset) != c)
		offset++;
	return (offset);
}

static char	**freearr(char **strarr, unsigned int size)
{
	unsigned int	offset;

	offset = 0;
	while (offset < size)
	{
		free(*(strarr + offset));
		offset++;
	}
	free(strarr);
	return (NULL);
}
