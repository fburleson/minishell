/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:01:05 by joel              #+#    #+#             */
/*   Updated: 2023/08/12 15:07:10 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	unsigned int	cidx;

	cidx = 0;
	while (cmd->outfiles[cidx])
	{
		free_iofile(cmd->outfiles[cidx]);
		cidx++;
	}
	free(cmd->outfiles);
	free_strarray(cmd->args);
	if (cmd->infile)
		free_iofile(cmd->infile);
	free(cmd);
}

void	free_cmds(t_cmd **cmds)
{
	unsigned int	cidx;

	cidx = 0;
	while (cmds[cidx])
	{
		free_cmd(cmds[cidx]);
		cidx++;
	}
	free(cmds);
}
