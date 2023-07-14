/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:44:17 by joel              #+#    #+#             */
/*   Updated: 2023/07/14 11:09:55 by joel             ###   ########.fr       */
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
		while (line[cidx] && line[cidx] == ' ')
			cidx++;
		if (line[cidx] && (line[cidx] == '\"' || line[cidx] == '\''))
		{
			while (line[cidx] && (line[cidx] != '\"' || line[cidx] != '\''))
				cidx++;
			n++;
		}
		else if (line[cidx])
			n++;
		while (line[cidx] && line[cidx] != ' ')
			cidx++;
	}
	return (n);
}

static unsigned int	arg_len(char *line)
{
	unsigned int	cidx;

	cidx = 0;
	if (line[cidx] && line[cidx] != ' ')
	{
		if (line[cidx] && (line[cidx] == '\"' || line[cidx] == '\''))
		{
			cidx = 1;
			while (line[cidx] && line[cidx] != '\"' && line[cidx] != '\'')
				cidx++;
			cidx++;
		}
		else
		{
			while (line[cidx] && line[cidx] != ' ')
				cidx++;
		}
	}
	return (cidx);
}

static char	*copy_arg(char *line, unsigned int arg_len)
{
	char			*arg;
	unsigned int	cidx;

	arg = (char *)malloc((arg_len + 1) * sizeof(char));
	if (!arg)
		return (NULL);
	cidx = 0;
	while (cidx < arg_len)
	{
		arg[cidx] = line[cidx];
		cidx++;
	}
	arg[cidx] = '\0';
	return (arg);
}

char	**parse_line(char *line)
{
	char			**args;
	unsigned int	current_arg;
	unsigned int	arg_l;
	unsigned int	cidx;

	args = (char **)malloc((n_args(line) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	cidx = 0;
	current_arg = 0;
	while (line[cidx])
	{
		while (line[cidx] && line[cidx] == ' ')
			cidx++;
		arg_l = arg_len(line + cidx);
		args[current_arg] = copy_arg(line + cidx, arg_l);
		while (line[cidx] && line[cidx] != ' ')
			cidx++;
		current_arg++;
	}
	args[current_arg] = NULL;
	return (args);
}
