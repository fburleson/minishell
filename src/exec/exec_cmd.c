/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:19:31 by joel              #+#    #+#             */
/*   Updated: 2023/11/30 18:20:36 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_status	g_exit_status;

static t_pid	exec_pipe_node(t_cmd *cmd, char ***env)
{
	t_pid	pid;

	pid = 0;
	if (!cmd->args[0])
		return (0);
	setup_redirect_in(cmd);
	setup_redirect_out(cmd);
	if (!is_builtin(cmd->args[0]))
		pid = exec_program(cmd->args, *env);
	else
		g_exit_status = exec_builtin(cmd->args, env);
	if (g_exit_status == STATUS_CMD_NOT_FOUND)
		print_err("command not found: ", cmd->args[0]);
	reset_redirection(cmd);
	return (pid);
}

static unsigned int	get_n_pids(t_cmd **cmds)
{
	unsigned int	cidx;

	cidx = 0;
	while (cmds[cidx])
		cidx++;
	return (cidx);
}

static void	exec_pipe_nodes(t_cmd **cmds, t_pid *pids,
		unsigned int n_pids, char ***env)
{
	unsigned int	cidx;

	cidx = 0;
	while (cidx < n_pids)
	{
		pids[cidx] = exec_pipe_node(cmds[cidx], env);
		cidx++;
	}
}

void	exec_pipe(t_cmd **cmds, char ***env)
{
	t_pid			*pids;
	unsigned int	n_pids;
	unsigned int	cidx;

	cidx = 0;
	n_pids = get_n_pids(cmds);
	pids = (t_pid *)malloc(n_pids * sizeof(t_pid));
	if (!pids)
		return ;
	exec_pipe_nodes(cmds, pids, n_pids, env);
	cidx = 0;
	while (cidx < n_pids)
	{
		if (!pids[cidx])
		{
			cidx++;
			continue ;
		}
		waitpid(pids[cidx], &g_exit_status, 0);
		g_exit_status = g_exit_status % 255;
		cidx++;
	}
	signal(SIGINT, &signalhandler);
	free(pids);
}
