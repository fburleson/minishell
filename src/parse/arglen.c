/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:35 by joel              #+#    #+#             */
/*   Updated: 2023/12/08 14:38:58 by joel             ###   ########.fr       */
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

unsigned int	arglen(char *sa, char **env)
{
	unsigned int	len;
	unsigned int	cidx;

	cidx = 0;
	len = 0;
	if (sa[cidx] == '|')
		return (1);
	else if (sa[cidx] == '>')
		return (arglen_io(sa, sa[cidx]));
	else if (sa[cidx] == '<')
		return (arglen_io(sa, sa[cidx]));
	while (!ft_isspace(sa[cidx]) && !ft_strrchr("|<>\0", sa[cidx]))
	{
		len += get_len_phrase(sa + cidx, env);
		if (sa[cidx] == '\'')
			cidx += lstrlen(sa + cidx, "\'", 1);
		else if (sa[cidx] == '\"')
			cidx += lstrlen(sa + cidx, "\"", 1);
		else if (sa[cidx] == '$')
			cidx += lstrlen(sa + cidx, " $|<>\'\"", 1) - 1;
		else
			len++;
		cidx++;
	}
	return (len);
}
