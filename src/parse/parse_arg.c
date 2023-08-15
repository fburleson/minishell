/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:20:49 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 11:34:44 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*copy_arg(char *line, char *delimiters)
{
	char			*copy;
	unsigned int	cidx;

	cidx = 1;
	copy = (char *)malloc((lstrlen(line + cidx, delimiters, 0) + 1)
			* sizeof(char));
	if (!copy)
		return (NULL);
	while (line[cidx] && !ft_strnchr(delimiters, line[cidx]))
	{
		copy[cidx - 1] = line[cidx];
		cidx++;
	}
	copy[cidx - 1] = '\0';
	return (copy);
}

char	*parse_arg(char *line, char *delimiters, char **env)
{
	if (*line == '\'')
		return (copy_arg(line, delimiters));
	return (expand_copy_arg(line, delimiters, env));
}
