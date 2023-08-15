/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:35:00 by joel              #+#    #+#             */
/*   Updated: 2023/08/15 19:19:30 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_file(char *path)
{
	t_fstats	file_stats;

	stat(path, &file_stats);
	return (!S_ISDIR(file_stats.st_mode));
}

t_status	exec_program(char **args, char **env)
{
	t_pid		p_id;
	int			status;
	char		*exec_path;

	status = SUCCESS;
	if (args[0][0] == '/')
		exec_path = ft_strdup(args[0]);
	else
		exec_path = get_abs_path(args[0], env);
	if (!exec_path || access(exec_path, F_OK) || !is_file(exec_path))
	{
		free(exec_path);
		return (STATUS_CMD_NOT_FOUND);
	}
	p_id = fork();
	if (p_id == 0)
		execve(exec_path, args, env);
	else
		wait(&status);
	free(exec_path);
	return ((t_status) status);
}
