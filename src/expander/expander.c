/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:56:40 by joel              #+#    #+#             */
/*   Updated: 2023/07/16 13:11:22 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	n_args(char	**args)
{
	unsigned int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

static char	*expand_arg(char *arg, char **env)
{
	char			*expanded;

	if (arg[0] == '$')
		expanded = env_var(arg + 1, env);
	else if (arg[0] == '\"')
		expanded = expand_str(arg, env);
	else
		expanded = ft_strdup(arg);
	if (!expanded)
		return (NULL);
	return (expanded);
}

char	**expand_args(char **args, char **env, t_status status)
{
	char			**expanded;
	unsigned int	cidx;

	expanded = (char **)malloc((n_args(args) + 1) * sizeof(char *));
	if (!expanded)
		return (NULL);
	cidx = 0;
	while (args[cidx])
	{
		if (!ft_strncmp(args[cidx], CMD_STATUS, 2))
			expanded[cidx] = ft_itoa((int) status);
		else if (!ft_strncmp(args[cidx], "\""CMD_STATUS"\"", 4))
			expanded[cidx] = ft_itoa((int) status);
		else
			expanded[cidx] = expand_arg(args[cidx], env);
		if (!(expanded[cidx]))
		{
			free_str_arr(expanded);
			return (NULL);
		}
		cidx++;
	}
	expanded[cidx] = NULL;
	return (expanded);
}
