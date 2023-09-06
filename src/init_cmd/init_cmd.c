/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:27:10 by joel              #+#    #+#             */
/*   Updated: 2023/09/06 17:30:50 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->raw_args = args;
	cmd->args = cmd_args(args);
	cmd->fstdout = -1;
	cmd->fredirectout = -1;
	cmd->fstdin = -1;
	cmd->fredirectin = -1;
	return (cmd);
}
