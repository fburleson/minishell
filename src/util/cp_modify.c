/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:06:23 by joel              #+#    #+#             */
/*   Updated: 2023/11/14 15:07:03 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_append(char **array, char *append)
{
	char			**cp;
	unsigned int	cidx;

	cidx = 0;
	cp = (char **)malloc((strarraylen(array) + 2) * sizeof(char *));
	if (!cp)
		return (NULL);
	while (array[cidx])
	{
		cp[cidx] = ft_strdup(array[cidx]);
		cidx++;
	}
	cp[cidx] = ft_strdup(append);
	cp[cidx + 1] = NULL;
	return (cp);
}

static t_bool	cmp_envvar_name(char *line, char *cmp)
{
	unsigned int	len;

	len = lstrlen(line, "=", 0);
	return (!ft_strncmp(line, cmp, ft_max(len, ft_strlen(cmp))));
}

char	**cp_remove(char **array, char *element)
{
	char			**cp;
	unsigned int	cp_idx;
	unsigned int	cidx;

	cidx = 0;
	cp_idx = 0;
	cp = (char **)malloc(strarraylen(array) * sizeof(char *));
	if (!cp)
		return (NULL);
	while (array[cidx])
	{
		if (!cmp_envvar_name(array[cidx], element))
		{
			cp[cp_idx] = ft_strdup(array[cidx]);
			cp_idx++;
		}
		cidx++;
	}
	cp[cp_idx] = NULL;
	return (cp);
}
