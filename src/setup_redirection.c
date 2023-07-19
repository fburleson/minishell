/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:09:02 by joel              #+#    #+#             */
/*   Updated: 2023/07/19 16:44:47 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_redirect_out(t_cmd *cmd)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (cmd->append_mode)
		flags = flags | O_APPEND;
	else
		flags = flags | O_TRUNC;
	cmd->fd_stdout = dup(STDOUT_FILENO);
	cmd->fd_redout = open(cmd->output_file, flags, 0644);
	dup2(cmd->fd_redout, STDOUT_FILENO);
}

void	reset_redirection(t_cmd *cmd)
{
	dup2(cmd->fd_stdout, STDOUT_FILENO);
	close(cmd->fd_redout);
	close(cmd->fd_stdout);
}
