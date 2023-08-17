/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:19:31 by joel          #+#    #+#                 */
/*   Updated: 2023/08/17 16:03:50 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_status	g_exit_status;

void	exec_cmd(t_cmd *cmd, char **env, t_envs *env_list)
{
	setup_redirect_out(cmd);
	setup_redirect_in(cmd);
	if (!is_builtin(cmd->args[0]))
		g_exit_status = exec_program(cmd->args, env);
	else
		g_exit_status = exec_builtin(cmd->args, env, env_list);
	reset_redirection(cmd);
}
