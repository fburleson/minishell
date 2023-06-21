/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:56:40 by joel              #+#    #+#             */
/*   Updated: 2023/06/21 16:23:42 by joel             ###   ########.fr       */
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

static char	*get_var_name(char *arg)
{
	char			*var_name;
	unsigned int	cidx;

	var_name = (char *)malloc(ft_strlen(arg) * sizeof(char));
	if (!var_name)
		return (NULL);
	cidx = 0;
	while (arg[cidx] != '\"')
	{
		var_name[cidx] = arg[cidx];
		cidx++;
	}
	var_name[cidx] = '\0';
	return (var_name);
}

char	**expand_args(char **args, char **env)
{
	char			**expanded;
	char			*var_name;
	unsigned int	cidx;

	expanded = (char **)malloc((n_args(args) + 1) * sizeof(char *));
	if (!expanded)
		return (NULL);
	cidx = 0;
	while (args[cidx])
	{
		if (args[cidx][0] == '$')
			expanded[cidx] = env_var(args[cidx] + 1, env);
		else if (args[cidx][0] == '\"' && args[cidx][1] == '$')
		{
			var_name = get_var_name(args[cidx] + 2);
			expanded[cidx] = env_var(var_name, env);
			free(var_name);
		}
		else
			expanded[cidx] = ft_strdup(args[cidx]);
		cidx++;
	}
	expanded[cidx] = NULL;
	return (expanded);
}
