/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:30:23 by kaltevog          #+#    #+#             */
/*   Updated: 2023/11/22 20:35:01 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*raw_envvar_name(char *line)
{
	char			*name;
	unsigned int	len;

	len = lstrlen(line, "=", 0) + 1;
	name = (char *)malloc((len + 1) * sizeof(char));
	if (!name)
		return (NULL);
	ft_strlcpy(name, line, len);
	return (name);
}

static t_bool	is_name_unique(char *value, char **env)
{
	char			*name;
	char			*envname;
	unsigned int	cidx;

	cidx = 0;
	name = raw_envvar_name(value);
	while (env[cidx])
	{
		envname = raw_envvar_name(env[cidx]);
		if (!ft_strncmp(envname, name, ft_max(ft_strlen(envname), ft_strlen(name))))
		{
			free(envname);
			free(name);
			return (FALSE);
		}
		free(envname);
		cidx++;
	}
	free(name);
	return (TRUE);
}

t_bool	is_value_valid(char *value)
{
	unsigned int	cidx;

	cidx = 0;
	while (value[cidx] && ft_isalnum(value[cidx]))
		cidx++;
	if (value[cidx] != '=')
		return (FALSE);
	return (TRUE);
}

t_status	cmd_export(char **args, char ***env)
{
	char	**append_env;
	char	**temp_env;
	char	*raw_name;

	if (!is_value_valid(args[1]))
		return (ERROR);
	if (!is_name_unique(args[1], *env))
	{
		raw_name = raw_envvar_name(args[1]);
		temp_env = cp_remove(*env, raw_name);
		free(raw_name);
		if (!temp_env)
			return (ERROR);
		free_strarray(*env);
		*env = temp_env;
	}
	append_env = cp_append(*env, args[1]);
	if (!append_env)
		return (ERROR);
	free_strarray(*env);
	*env = append_env;
	return (SUCCESS);
}
