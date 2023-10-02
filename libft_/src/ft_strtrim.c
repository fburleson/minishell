/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:13:12 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:24:00 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	nchinstr(const char c, const char *s);
static unsigned int	starttrim(const char *s1, const char *set);
static unsigned int	endtrim(const char *s1, const char *set);
static unsigned int	trimlen(const char *s1, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	offset;
	unsigned int	trim_offset;
	unsigned int	end;
	char			*trim;

	trim_offset = 0;
	trim = ft_calloc(trimlen(s1, set), sizeof(char));
	if (!trim)
		return (NULL);
	if (!*s1)
		return (trim);
	offset = starttrim(s1, set);
	end = endtrim(s1, set);
	while (offset < end && *(s1 + offset))
	{
		*(trim + trim_offset) = *(s1 + offset);
		trim_offset++;
		offset++;
	}
	return (trim);
}

static unsigned int	nchinstr(const char c, const char *s)
{
	unsigned int	offset;
	unsigned int	n;

	offset = 0;
	n = 0;
	while (*(s + offset))
	{
		if (*(s + offset) == c)
			n++;
		offset++;
	}
	return (n);
}

static unsigned int	starttrim(const char *s1, const char *set)
{
	unsigned int	offset;

	offset = 0;
	while (nchinstr(*(s1 + offset), set) && *(s1 + offset))
		offset++;
	return (offset);
}

static unsigned int	endtrim(const char *s1, const char *set)
{
	unsigned int	offset;

	offset = ft_strlen(s1) - 1;
	while (nchinstr(*(s1 + offset), set) && offset != 0)
		offset--;
	return (offset + 1);
}

static unsigned int	trimlen(const char *s1, const char *set)
{
	unsigned int	offset;
	unsigned int	n;
	size_t			str_len;

	offset = 0;
	n = 0;
	str_len = ft_strlen(s1);
	if (!str_len)
		return (1);
	while (nchinstr(*(s1 + offset), set))
	{
		n++;
		offset++;
		if (!*(s1 + offset))
			return (2);
	}
	offset = str_len - 1;
	while (nchinstr(*(s1 + offset), set))
	{
		n++;
		offset--;
	}
	return (str_len - n + 1);
}
