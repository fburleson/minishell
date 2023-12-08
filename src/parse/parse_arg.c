/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:06:41 by joel              #+#    #+#             */
/*   Updated: 2023/12/08 14:48:58 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	skip_envvar(char *start_var)
{
	unsigned int	cidx;

	cidx = 1;
	while (ft_isalnum(start_var[cidx]))
		cidx++;
	return (cidx);
}

char	*parse_arg(char *start_arg, char **env)
{
	char			*arg;
	unsigned int	aidx;
	unsigned int	len;
	unsigned int	cidx;

	len = arglen(start_arg, env);
	arg = (char *)malloc((len + 1) * sizeof(char));
	if (!arg)
		return (NULL);
	cidx = 0;
	aidx = 0;
	while (start_arg[cidx] && aidx < len)
	{
		aidx += insert_arg(arg + aidx, start_arg + cidx, env);
		if (start_arg[cidx] == '\'')
			cidx += lstrlen(start_arg + cidx, "\'", 1) + 1;
		else if (start_arg[cidx] == '\"')
			cidx += lstrlen(start_arg + cidx, "\"", 1) + 1;
		else if (start_arg[cidx] == '$')
			cidx += skip_envvar(start_arg + cidx);
		else
			cidx++;
	}
	arg[aidx] = '\0';
	return (arg);
}
