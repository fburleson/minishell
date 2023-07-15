/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:11:30 by joel              #+#    #+#             */
/*   Updated: 2023/07/15 12:33:37 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_file(char *path)
{
	t_fstats	file_stats;

	stat(path, &file_stats);
	return (!S_ISDIR(file_stats.st_mode));
}

t_status	exec_program(char *path, char **args, char **env)
{
	t_pid		p_id;
	int			status;
	char		*exec_path;

	status = SUCCESS;
	if (path[0] == '/')
		exec_path = ft_strdup(path);
	else
		exec_path = get_abs_path(path, env);
	if (!exec_path || access(exec_path, F_OK) || !is_file(exec_path))
	{
		free(exec_path);
		return (CMD_NOT_FOUND_STATUS);
	}
	p_id = fork();
	if (p_id == 0)
		execve(exec_path, args, env);
	else
		wait(&status);
	free(exec_path);
	return ((t_status) status);
}
