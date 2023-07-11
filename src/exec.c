/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:11:30 by joel              #+#    #+#             */
/*   Updated: 2023/07/11 13:42:22 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	exec_program(char *path, char **args, char **env)
{
	t_pid		p_id;
	int			status;

	p_id = fork();
	waitpid(p_id, &status, WUNTRACED);
	if (p_id != 0)
		return ((t_status) status);
	if (execve(path, args, env) == -1)
		exit (EXEC_FAILED_ERR);
	return ((t_status) status);
}
