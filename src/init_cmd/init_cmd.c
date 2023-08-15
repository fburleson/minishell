/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:27:10 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 16:48:26 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = cmd_args(args);
	cmd->outfiles = init_outfiles(args);
	cmd->infile = init_infile(args);
	cmd->fstdout = -1;
	cmd->fredirectout = -1;
	cmd->fstdin = -1;
	cmd->fredirectin = -1;
	return (cmd);
}
