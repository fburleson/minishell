/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:30:25 by kaltevog          #+#    #+#             */
/*   Updated: 2023/11/22 20:59:12 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_envvar(char *name, char *envvar)
{
	unsigned int	len;

	len = lstrlen(envvar, "=", 0);
	return (!ft_strncmp(name, envvar, ft_max(len, ft_strlen(name))));
}

static t_bool	contains_var(char *name, char **env)
{
	unsigned int	cidx;

	cidx = 0;
	while (env[cidx])
	{
		if (is_envvar(name, env[cidx]))
			return (TRUE);
		cidx++;
	}
	return (FALSE);
}

t_status	cmd_unset(char **args, char ***env)
{
	char	**rm_env;

	if (!contains_var(args[1], *env))
		return (ERROR);
	rm_env = cp_remove(*env, args[1]);
	if (!rm_env)
		return (ERROR);
	free_strarray(*env);
	*env = rm_env;
	return (SUCCESS);
}
