/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:35:00 by joel              #+#    #+#             */
/*   Updated: 2023/11/14 19:38:03 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_status	g_exit_status;

static void	program_sighandler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		g_exit_status = STATUS_NEW_PROMPT;
	}
}

static t_bool	is_file(char *path)
{
	t_fstats	file_stats;

	stat(path, &file_stats);
	return (!S_ISDIR(file_stats.st_mode));
}

t_pid	exec_program(char **args, char **env)
{
	t_pid		p_id;
	char		*exec_path;

	p_id = 0;
	if (args[0][0] == '/')
		exec_path = ft_strdup(args[0]);
	else
		exec_path = get_abs_path(args[0], env);
	if (!exec_path || access(exec_path, F_OK) || !is_file(exec_path))
	{
		free(exec_path);
		g_exit_status = STATUS_CMD_NOT_FOUND;
		return (p_id);
	}
	p_id = fork();
	if (p_id == 0)
		execve(exec_path, args, env);
	free(exec_path);
	signal(SIGINT, &program_sighandler);
	return (p_id);
}
