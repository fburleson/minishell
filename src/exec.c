/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:11:30 by joel              #+#    #+#             */
/*   Updated: 2023/07/14 12:11:03 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (!exec_path || access(exec_path, F_OK))
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
