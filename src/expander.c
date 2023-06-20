/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:56:40 by joel              #+#    #+#             */
/*   Updated: 2023/06/20 15:46:59 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	var_len(char *var)
{
	unsigned int	cidx;

	cidx = 0;
	while (var[cidx] && var[cidx] != '=')
		cidx++;
	if (var[cidx] == '=')
		cidx++;
	return (ft_strlen(var + cidx));
}

static char	*get_var(char *arg, char **env)
{
	unsigned int	cidx;
	unsigned int	arg_len;
	t_bool			qouted;

	cidx = 0;
	qouted = arg[0] == '\"';
	arg_len = ft_strlen(arg + 1);
	if (qouted)
	{
		arg = arg + 1;
		arg_len -= 2;
	}
	while (env[cidx])
	{
		if (!ft_strncmp(arg + 1, env[cidx], arg_len))
			return (env[cidx]);
		cidx++;
	}
	return (NULL);
}

static char	*copy_var_value(char *var)
{
	char			*copy;
	unsigned int	cidx;
	unsigned int	copy_cidx;

	copy = (char *)malloc((var_len(var) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	cidx = 0;
	while (var[cidx] && var[cidx] != '=')
		cidx++;
	if (var[cidx] == '=')
		cidx++;
	copy_cidx = 0;
	while (var[cidx])
	{
		copy[copy_cidx] = var[cidx];
		cidx++;
		copy_cidx++;
	}
	copy[copy_cidx] = '\0';
	return (copy);
}

char	*expand(char *arg, char **env)
{
	char			*expanded;
	char			*var;

	var = get_var(arg, env);
	if (!var)
		return (NULL);
	expanded = copy_var_value(var);
	if (!expanded)
		return (NULL);
	return (expanded);
}
