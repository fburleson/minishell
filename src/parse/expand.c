/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:00:29 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 14:09:24 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*envvar_value(char *line, char **env)
{
	char	*value;
	char	*name;

	name = envvar_name(line);
	value = envvar(name, env);
	free(name);
	return (value);
}

static unsigned int	expandlen(char *line, char *delimiters, char **env)
{
	unsigned int	n;
	unsigned int	cidx;
	char			*delimiters_var;
	char			*env_value;

	n = 0;
	cidx = (*line == '\"');
	delimiters_var = ft_strjoin(delimiters, "$");
	while (line[cidx] && !ft_strnchr(delimiters, line[cidx]))
	{
		n += lstrlen(line + cidx, delimiters_var, 0);
		cidx += lstrlen(line + cidx, delimiters_var, 0);
		if (line[cidx] == '$')
		{
			env_value = envvar_value(line + cidx, env);
			n += ft_strlen(env_value);
			free(env_value);
			cidx++;
			while (ft_isalnum(line[cidx]))
				cidx++;
		}
	}
	free(delimiters_var);
	return (n);
}

static unsigned int	insert_envvar(char *line, char *dst, char **env)
{
	unsigned int	n;
	char			*env_value;

	env_value = envvar_value(line, env);
	n = ft_strlcpy(dst, env_value, ft_strlen(env_value) + 1);
	free(env_value);
	return (n);
}

char	*expand_copy_arg(char *line, char *limiters, char **env)
{
	char			*copy;
	unsigned int	cidx;
	unsigned int	copy_idx;

	copy = (char *)malloc((expandlen(line, limiters, env) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	cidx = (*line == '\"');
	copy_idx = 0;
	while (line[cidx] && !ft_strnchr(limiters, line[cidx]))
	{
		if (line[cidx] == '$')
		{
			copy_idx += insert_envvar(line + cidx, copy + copy_idx, env);
			cidx++;
			while (line[cidx] != ' ')
				cidx++;
			continue ;
		}
		copy[copy_idx] = line[cidx];
		cidx++;
		copy_idx++;
	}
	copy[copy_idx] = '\0';
	return (copy);
}
