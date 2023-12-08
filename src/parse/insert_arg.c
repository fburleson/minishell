/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:42 by joel              #+#    #+#             */
/*   Updated: 2023/12/08 14:49:07 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	insert_str(char *dest, char *src, unsigned int size)
{
	unsigned int	cidx;

	cidx = 0;
	while (cidx < size)
	{
		dest[cidx] = src[cidx];
		cidx++;
	}
	return (cidx);
}

static unsigned int	insert_envvar(char *dest, char *start_var, char **env)
{
	unsigned int	size;
	char			*name;
	char			*value;

	name = envvar_name(start_var);
	value = envvar(name, env);
	size = insert_str(dest, value, ft_strlen(value));
	free(name);
	free(value);
	return (size);
}

static unsigned int	insert_quotes(char *dest, char *start_phrase, char **env)
{
	unsigned int	cidx;
	unsigned int	didx;

	cidx = 1;
	didx = 0;
	while (start_phrase[cidx] && start_phrase[cidx] != '\"')
	{
		if (start_phrase[cidx] == '$')
		{
			didx += insert_envvar(dest + didx, start_phrase + cidx, env);
			cidx++;
			while (ft_isalnum(start_phrase[cidx]))
				cidx++;
		}
		else
		{
			dest[didx] = start_phrase[cidx];
			didx++;
			cidx++;
		}
	}
	return (didx);
}

unsigned int	insert_arg(char *dest, char *start_phrase, char **env)
{
	if (start_phrase[0] == '\'')
		return (insert_str(dest, start_phrase + 1,
				lstrlen(start_phrase + 1, "\'", 0)));
	else if (start_phrase[0] == '\"')
		return (insert_quotes(dest, start_phrase, env));
	else if (start_phrase[0] == '$')
		return (insert_envvar(dest, start_phrase, env));
	else
		dest[0] = start_phrase[0];
	return (1);
}
