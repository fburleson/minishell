/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:27:07 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/06/21 15:32:21 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	env_var_len(char *var)
{
	unsigned int	cidx;

	cidx = 0;
	while (var[cidx] != '=')
		cidx++;
	return (cidx);
}

static char	*copy_env_var(char *var)
{
	char			*copy;
	unsigned int	cidx;
	unsigned int	copy_cidx;

	cidx = 0;
	while (var[cidx] != '=')
		cidx++;
	cidx++;
	copy = (char *)malloc((ft_strlen(var + cidx) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
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

char	*env_var(char *var_name, char **env)
{
	char			*value;
	unsigned int	cidx;

	cidx = 0;
	value = ft_strdup("");
	while (env[cidx])
	{
		if (!ft_strncmp(var_name, env[cidx],
				ft_max(ft_strlen(var_name), env_var_len(env[cidx]))))
		{
			free(value);
			value = copy_env_var(env[cidx]);
		}
		cidx++;
	}
	return (value);
}
