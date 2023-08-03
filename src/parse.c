/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:25:22 by joel              #+#    #+#             */
/*   Updated: 2023/08/03 20:00:19 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	arg_len(char *start_arg)
{
	unsigned int	cidx;

	cidx = 0;
	if (start_arg[cidx] && start_arg[cidx] == '\"')
	{
		cidx++;
		while (start_arg[cidx] && start_arg[cidx] != '\"')
			cidx++;
		cidx++;
	}
	else if (start_arg[cidx] && start_arg[cidx] == '\'')
	{	
		cidx++;
		while (start_arg[cidx] && start_arg[cidx] != '\'')
			cidx++;
		cidx++;
	}
	else
	{
		while (start_arg[cidx] && start_arg[cidx] != ' '
			&& start_arg[cidx] != '\'' && start_arg[cidx] != '\"')
			cidx++;
	}
	return (cidx);
}

static unsigned int	redirection_arg_len(char *start_arg)
{
	unsigned int	cidx;

	cidx = 0;
	while (start_arg[cidx]
		&& (start_arg[cidx] == OUTRED_SYM
			|| start_arg[cidx] == INRED_SYM))
		cidx++;
	while (start_arg[cidx] && start_arg[cidx] == ' ')
		cidx++;
	while (start_arg[cidx] && start_arg[cidx] != ' ')
		cidx++;
	while (start_arg[cidx] && start_arg[cidx] == ' ')
		cidx++;
	return (cidx);
}

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
		while (line[cidx] == OUTRED_SYM || line[cidx] == INRED_SYM)
			cidx += redirection_arg_len(line + cidx);
		if (line[cidx])
		{
			cidx += arg_len(line + cidx);
			n++;
		}
	}
	return (n);
}

static char	*copy_arg(char *start_arg, unsigned int arg_len)
{
	char			*arg;
	unsigned int	cidx;

	arg = (char *)malloc((arg_len + 1) * sizeof(char));
	if (!arg)
		return (NULL);
	cidx = 0;
	while (cidx < arg_len)
	{
		arg[cidx] = start_arg[cidx];
		cidx++;
	}
	arg[cidx] = '\0';
	return (arg);
}

char	**parse_line(char *line)
{
	char			**args;
	unsigned int	current_arg;
	unsigned int	line_idx;

	args = (char **)ft_calloc((n_args(line) + 1), sizeof(char *));
	if (!args)
		return (NULL);
	current_arg = 0;
	line_idx = 0;
	while (line[line_idx] && current_arg < n_args(line))
	{
		while (line[line_idx] && line[line_idx] == ' ')
			line_idx++;
		while (line[line_idx] == OUTRED_SYM || line[line_idx] == INRED_SYM)
			line_idx += redirection_arg_len(line + line_idx);
		args[current_arg] = copy_arg(line + line_idx, arg_len(line + line_idx));
		if (!(args[current_arg]))
		{
			free_str_arr(args);
			return (NULL);
		}
		line_idx += arg_len(line + line_idx);
		current_arg++;
	}
	return (args);
}
