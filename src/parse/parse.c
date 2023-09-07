/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:09:07 by joel              #+#    #+#             */
/*   Updated: 2023/09/07 14:19:52 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	offset_next_arg(char *line, char *delimiters)
{
	if (ft_strnchr("\'\"", *line))
		return (lstrlen(line, delimiters, 1) + 1);
	else
		return (lstrlen(line, delimiters, 0));
}

static unsigned int	n_args(char *line)
{
	unsigned int	n;
	unsigned int	cidx;
	char			*delimiters;

	n = 0;
	cidx = 0;
	while (line[cidx])
	{
		while (line[cidx] == ' ')
			cidx++;
		if (line[cidx])
			n++;
		delimiters = get_delimiters(line[cidx]);
		cidx += offset_next_arg(line + cidx, delimiters);
		free(delimiters);
	}
	return (n);
}

char	**parse(char *line, char **env)
{
	char			**parsed;
	unsigned int	cidx;
	unsigned int	current_arg;
	char			*delimiters;

	parsed = (char **)malloc((n_args(line) + 1) * sizeof(char *));
	if (!parsed)
		return (NULL);
	cidx = 0;
	current_arg = 0;
	while (line[cidx] == ' ')
		cidx++;
	while (line[cidx])
	{
		delimiters = get_delimiters(line[cidx]);
		parsed[current_arg] = parse_arg(line + cidx, delimiters, env);
		cidx += offset_next_arg(line + cidx, delimiters);
		current_arg++;
		while (line[cidx] == ' ')
			cidx++;
		free(delimiters);
	}
	parsed[current_arg] = NULL;
	return (parsed);
}
