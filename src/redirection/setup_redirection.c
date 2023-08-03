/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:09:02 by joel              #+#    #+#             */
/*   Updated: 2023/08/03 20:50:17 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_outfile(t_redir_file *file)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (file->mode == APPEND_MODE)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (open(file->file_path, flags, 0644));
}

static int	open_infile(t_redir_file *file)
{
	int	flags;

	flags = O_RDONLY;
	return (open(file->file_path, flags));
}

void	setup_redirect_out(t_cmd *cmd)
{
	unsigned int	file_idx;
	int				current_file;

	file_idx = 0;
	if (!cmd->output_files[0])
		return ;
	while (cmd->output_files[file_idx + 1])
	{
		current_file = open_outfile(cmd->output_files[file_idx]);
		close(current_file);
		file_idx++;
	}
	cmd->fd_stdout = dup(STDOUT_FILENO);
	current_file = open_outfile(cmd->output_files[file_idx]);
	cmd->fd_redout = current_file;
	dup2(cmd->fd_redout, STDOUT_FILENO);
}

void	setup_redirect_in(t_cmd *cmd)
{
	unsigned int	file_idx;

	file_idx = 0;
	if (!cmd->input_files[0])
		return ;
	while (cmd->input_files[file_idx + 1])
		file_idx++;
	cmd->fd_stdin = dup(STDIN_FILENO);
	cmd->fd_redin = open_infile(cmd->input_files[file_idx]);
	dup2(cmd->fd_redin, STDIN_FILENO);
}

void	reset_redirection(t_cmd *cmd)
{
	dup2(cmd->fd_stdout, STDOUT_FILENO);
	close(cmd->fd_redout);
	close(cmd->fd_stdout);
	dup2(cmd->fd_stdin, STDIN_FILENO);
	close(cmd->fd_redin);
	close(cmd->fd_stdin);
}
