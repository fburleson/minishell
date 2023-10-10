/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:50:42 by joel              #+#    #+#             */
/*   Updated: 2023/10/10 17:34:08 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_outfile(t_iofile *file)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (file->mode == APPEND_MODE)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = ft_mopen(file->path, flags, 0644);
	return (fd);
}

static int	open_infile(t_iofile *file)
{
	int	fd;

	if (file->mode == HEREDOC_MODE)
		return (create_heredoc(file));
	fd = ft_open(file->path, O_RDONLY);
	return (fd);
}

void	setup_redirect_in(t_cmd *cmd)
{
	if (!cmd->infile)
		return ;
	cmd->fstdin = dup(STDIN_FILENO);
	cmd->fredirectin = open_infile(cmd->infile);
	dup2(cmd->fredirectin, STDIN_FILENO);
}

void	setup_redirect_out(t_cmd *cmd)
{
	unsigned int	file_idx;
	int				current_file;

	file_idx = 0;
	if (!cmd->outfiles[0])
		return ;
	while (cmd->outfiles[file_idx + 1])
	{
		current_file = open_outfile(cmd->outfiles[file_idx]);
		close(current_file);
		file_idx++;
	}
	cmd->fstdout = dup(STDOUT_FILENO);
	current_file = open_outfile(cmd->outfiles[file_idx]);
	cmd->fredirectout = current_file;
	dup2(cmd->fredirectout, STDOUT_FILENO);
}

void	reset_redirection(t_cmd *cmd)
{
	dup2(cmd->fstdout, STDOUT_FILENO);
	close(cmd->fredirectout);
	close(cmd->fstdout);
	dup2(cmd->fstdin, STDIN_FILENO);
	close(cmd->fredirectin);
	close(cmd->fstdin);
}
