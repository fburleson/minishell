/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_builtin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 14:37:36 by joel          #+#    #+#                 */
/*   Updated: 2023/09/14 17:29:37 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	exec_builtin(char **args, char **env, t_envs *env_list)
{
	if (cmpstr(args[0], CMD_EXIT))
		return (cmd_exit());
	else if (cmpstr(args[0], CMD_ENV))
		return (cmd_env(env_list));
	else if (cmpstr(args[0], CMD_ECHO))
		return (cmd_echo(args));
	else if (cmpstr(args[0], CMD_PWD))
		return (cmd_pwd(env_list));
	else if (cmpstr(args[0], CMD_CD))
		return (cmd_cd(args, env, env_list));
	else if (cmpstr(args[0], CMD_EXPORT))
		return (cmd_export(args, env, env_list));
	else if (cmpstr(args[0], CMD_UNSET))
		return (cmd_unset(args, env_list));
	else
		return (STATUS_CMD_NOT_FOUND);
}
