/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:37:47 by joel              #+#    #+#             */
/*   Updated: 2023/12/02 17:50:29 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	n_args(char *line)
{
	unsigned int	n;
	unsigned int	cidx;

	n = 0;
	cidx = 0;
	while (line[cidx])
	{
		cidx += offset_next_arg(line + cidx);
		n++;
	}
	return (n);
}

char	**parse(char *line)
{
	char			**parsed;
	unsigned int	carg;
	unsigned int	cidx;

	parsed = (char **)malloc((n_args(line) + 1) * sizeof(char *));
	if (!parsed)
		return (NULL);
	cidx = 0;
	while (ft_isspace(line[cidx]))
		cidx++;
	carg = 0;
	while (line[cidx])
	{
		parsed[carg] = parse_arg(line + cidx);
		carg++;
		cidx += offset_next_arg(line + cidx);
	}
	parsed[carg] = NULL;
	print_strarray(parsed);
	return (parsed);
}
