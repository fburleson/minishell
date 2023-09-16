/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:19:31 by joel              #+#    #+#             */
/*   Updated: 2023/09/16 20:30:43 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_status	g_exit_status;

static void	exec_cmd(t_cmd *cmd, char **env, t_envs *env_list)
{
	if (!cmd->args[0])
		return ;
	setup_redirect_out(cmd);
	setup_redirect_in(cmd);
	if (!is_builtin(cmd->args[0]))
		g_exit_status = exec_program(cmd->args, env);
	else
		g_exit_status = exec_builtin(cmd->args, env, env_list);
	if (g_exit_status == STATUS_CMD_NOT_FOUND)
		printf("minishell:	command not found:	%s\n", cmd->args[0]);
	reset_redirection(cmd);
}

void	exec_pipe(t_cmd **cmds, char **env, t_envs *env_list)
{
	unsigned int	cidx;

	cidx = 0;
	while (cmds[cidx])
	{
		exec_cmd(cmds[cidx], env, env_list);
		cidx++;
	}
}
