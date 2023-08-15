/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:17:22 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 21:48:04 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	n_cmds(char **args)
{
	unsigned int	n;
	unsigned int	cidx;

	n = 1;
	cidx = 0;
	while (args[cidx])
	{
		if (cmpstr(args[cidx], "|"))
			n++;
		cidx++;
	}
	return (n);
}

t_cmd	**init_cmds(char **args)
{
	t_cmd			**cmds;
	unsigned int	cmd_idx;
	unsigned int	cidx;

	cmds = (t_cmd **)malloc((n_cmds(args) + 1) * sizeof(t_cmd *));
	if (!cmds)
		return (NULL);
	cmd_idx = 0;
	cidx = 0;
	while (args[cidx])
	{
		if (cmpstr(args[cidx], "|"))
			cidx++;
		if (!args[cidx])
			break ;
		cmds[cmd_idx] = init_cmd(args + cidx);
		while (args[cidx] && !cmpstr(args[cidx], "|"))
			cidx++;
		cmd_idx++;
	}
	cmds[cmd_idx] = NULL;
	return (cmds);
}
