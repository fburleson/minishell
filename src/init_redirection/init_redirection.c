/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:08:10 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/11/30 17:40:01 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_single(t_cmd *cmd)
{
	cmd->outfiles = init_outfiles(cmd->raw_args);
	cmd->infile = init_infile(cmd->raw_args);
}

static t_iofile	*init_outfile(unsigned int idx)
{
	t_iofile	*iofile;

	iofile = (t_iofile *)malloc(sizeof(t_iofile));
	if (!iofile)
		return (NULL);
	iofile->path = iofile_name(idx);
	iofile->mode = OUTPUT_MODE;
	iofile->limit_str = ft_strdup("");
	return (iofile);
}

static t_iofile	**create_pipefile(unsigned int idx)
{
	t_iofile	**pipefile;
	int			fd;

	pipefile = (t_iofile **)malloc(2 * sizeof(t_iofile));
	if (!pipefile)
		return (NULL);
	pipefile[0] = init_outfile(idx);
	pipefile[1] = NULL;
	fd = ft_open(pipefile[0]->path, O_TRUNC);
	close(fd);
	return (pipefile);
}

static void	init_pipe(t_cmd **cmds)
{
	unsigned int	cidx;

	if (!cmds[0])
		return ;
	cmds[0]->infile = init_infile(cmds[0]->raw_args);
	cmds[0]->outfiles = create_pipefile(0);
	cidx = 1;
	while (cmds[cidx])
	{
		cmds[cidx]->infile = copy_iofile(cmds[cidx - 1]->outfiles[0]);
		cmds[cidx]->infile->mode = INPUT_MODE;
		if (cmds[cidx + 1])
			cmds[cidx]->outfiles = create_pipefile(cidx);
		else
			cmds[cidx]->outfiles = init_outfiles(cmds[cidx]->raw_args);
		cidx++;
	}
}

static void	init_explicit_redirections(t_cmd **cmds)
{
	t_iofile		*infile;
	t_iofile		**outfiles;
	unsigned int	cidx;

	cidx = 0;
	while (cmds[cidx])
	{
		infile = init_infile(cmds[cidx]->raw_args);
		outfiles = init_outfiles(cmds[cidx]->raw_args);
		if (infile)
		{
			free_iofile(cmds[cidx]->infile);
			cmds[cidx]->infile = infile;
		}
		if (outfiles[0])
		{
			free_iofilearr(cmds[cidx]->outfiles);
			cmds[cidx]->outfiles = outfiles;
		}
		else
			free_iofilearr(outfiles);
		cidx++;
	}
}

void	init_redirection(t_cmd **cmds)
{
	if (parraylen((void *)cmds) == 1)
		init_single(cmds[0]);
	else
		init_pipe(cmds);
	init_explicit_redirections(cmds);
}
