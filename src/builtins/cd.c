/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:26:10 by joel              #+#    #+#             */
/*   Updated: 2023/11/22 20:26:44 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_envvar_name(char *name, char *envvar)
{
	unsigned int	len;

	len = lstrlen(envvar, "=", 0);
	return (!ft_strncmp(name, envvar, ft_max(len, ft_strlen(name))));
}

static char	*join_value(char *name, char *value)
{
	char	*envvar;
	char	*temp;

	temp = ft_strjoin(name, "=");
	envvar = ft_strjoin(temp, value);
	free(temp);
	return (envvar);
}

static void	mod_var(char *name, char *value, char **env)
{
	unsigned int	cidx;

	cidx = 0;
	while (env[cidx])
	{
		if (is_envvar_name(name, env[cidx]))
		{
			free(env[cidx]);
			env[cidx] = join_value(name, value);
			break ;
		}
		cidx++;
	}
}

t_status	cmd_cd(char **args, char **env)
{
	char	*path;
	char	*old_pwd;
	char	*pwd;

	old_pwd = envvar("PWD", env);
	if (!old_pwd)
		return (ERROR);
	path = ft_strdup(args[1]);
	if (cmpstr(args[1], "~"))
		path = envvar("HOME", env);
	if (chdir(path) == -1)
	{
		print_err("No such file or directory", args[1]);
		return (ERROR);
	}
	pwd = getcwd(NULL, 0);
	mod_var("OLDPWD", old_pwd, env);
	free(old_pwd);
	mod_var("PWD", pwd, env);
	free(pwd);
	free(path);
	return (SUCCESS);
}
