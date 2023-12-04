/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:35 by joel              #+#    #+#             */
/*   Updated: 2023/12/04 17:54:05 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	arglen_io(char *start_arg, char c)
{
	if (start_arg[1] == c)
		return (2);
	return (1);
}

static unsigned int	envvar_len(char *start_var, char **env)
{
	unsigned int	len;
	char			*name;
	char			*value;

	name = envvar_name(start_var);
	value = envvar(name, env);
	len = ft_strlen(value);
	free(name);
	free(value);
	return (len);
}

static unsigned int	count_quoted(char *start_quotes, char **env)
{
	unsigned int	count;
	unsigned int	cidx;

	count = 0;
	cidx = 1;
	while (start_quotes[cidx] && start_quotes[cidx] != '\"')
	{
		count += lstrlen(start_quotes + cidx, "$\"", 0);
		cidx += lstrlen(start_quotes + cidx, "$\"", 0);
		if (start_quotes[cidx] == '$')
		{
			count += envvar_len(start_quotes + cidx, env);
			cidx++;
			while (ft_isalnum(start_quotes[cidx]))
				cidx++;
		}
	}
	return (count);
}

static unsigned int	get_len_phrase(char *start_phrase, char **env)
{
	if (start_phrase[0] == '\'')
		return (lstrlen(start_phrase, "\'", 1) - 1);
	if (start_phrase[0] == '\"')
		return (count_quoted(start_phrase, env));
	if (start_phrase[0] == '$')
		return (envvar_len(start_phrase, env));
	return (0);
}

unsigned int	arglen(char *start_arg, char **env)
{
	unsigned int	len;
	unsigned int	cidx;

	cidx = 0;
	len = 0;
	if (start_arg[cidx] == '|')
		return (1);
	else if (start_arg[cidx] == '>')
		return (arglen_io(start_arg, start_arg[cidx]));
	else if (start_arg[cidx] == '<')
		return (arglen_io(start_arg, start_arg[cidx]));
	while (start_arg[cidx] && !ft_isspace(start_arg[cidx])
		&& !ft_strrchr("|<>", start_arg[cidx]))
	{
		len += get_len_phrase(start_arg + cidx, env);
		if (start_arg[cidx] == '\'')
			cidx += lstrlen(start_arg + cidx, "\'", 1);
		else if (start_arg[cidx] == '\"')
			cidx += lstrlen(start_arg + cidx, "\"", 1);
		else if (start_arg[cidx] == '$')
			cidx += lstrlen(start_arg + cidx, " $|<>\'\"", 1) - 1;
		else
			len++;
		cidx++;
	}
	return (len);
}
