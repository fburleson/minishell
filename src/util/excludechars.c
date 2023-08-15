/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excludechars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:00:27 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 14:23:55 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*concatchar(char *str, char c)
{
	char			*concat;
	unsigned int	cidx;

	concat = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!concat)
		return (NULL);
	cidx = 0;
	while (str[cidx])
	{
		concat[cidx] = str[cidx];
		cidx++;
	}
	concat[cidx] = c;
	concat[cidx + 1] = '\0';
	return (concat);
}

char	*excludechars(char *exclude)
{
	char			*excluded;
	char			*temp;
	unsigned int	cidx;

	excluded = ft_strdup("");
	if (!excluded)
		return (NULL);
	cidx = 0;
	while (cidx < (126 - 32) + 1)
	{
		if (!ft_strnchr(exclude, cidx + 32))
		{
			temp = concatchar(excluded, cidx + 32);
			free(excluded);
			excluded = temp;
		}
		cidx++;
	}
	return (excluded);
}
