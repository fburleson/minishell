/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:37:36 by joel              #+#    #+#             */
/*   Updated: 2023/11/14 15:54:20 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	exec_builtin(char **args, char ***env)
{
	if (cmpstr(args[0], CMD_EXIT))
		return (cmd_exit(args));
	else if (cmpstr(args[0], CMD_ENV))
		return (cmd_env(*env));
	else if (cmpstr(args[0], CMD_ECHO))
		return (cmd_echo(args));
	else if (cmpstr(args[0], CMD_PWD))
		return (cmd_pwd(*env));
	else if (cmpstr(args[0], CMD_EXPORT))
		return (cmd_export(args, env));
	else if (cmpstr(args[0], CMD_UNSET))
		return (cmd_unset(args, env));
	else
		return (STATUS_CMD_NOT_FOUND);
}
