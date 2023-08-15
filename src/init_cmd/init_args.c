/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:09:20 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 21:21:06 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	n_skip(char **args)
{
	unsigned int	cidx;

	cidx = 0;
	if (cmpstr(args[cidx], ">>") || cmpstr(args[cidx], ">")
		|| cmpstr(args[cidx], "<"))
	{
		while (args[cidx] && !cmpstr(args[cidx], "|") && cidx < 2)
			cidx++;
	}
	else if (cmpstr(args[cidx], "<<"))
	{
		while (args[cidx] && !cmpstr(args[cidx], "|") && cidx < 3)
			cidx++;
	}
	return (cidx);
}

static unsigned int	n_args(char **args)
{
	unsigned int	n;
	unsigned int	cidx;
	unsigned int	skip;

	n = 0;
	cidx = 0;
	while (args[cidx] && !cmpstr(args[cidx], "|"))
	{	
		skip = n_skip(args + cidx);
		cidx += skip;
		if (skip)
			continue ;
		n++;
		cidx++;
	}
	return (n);
}

char	**cmd_args(char **args)
{
	char			**cmd_args;
	unsigned int	arg_idx;
	unsigned int	cidx;
	unsigned int	skip;

	cmd_args = (char **)malloc((n_args(args) + 1) * sizeof(char *));
	if (!cmd_args)
		return (NULL);
	arg_idx = 0;
	cidx = 0;
	while (args[cidx] && !cmpstr(args[cidx], "|"))
	{	
		skip = n_skip(args + cidx);
		cidx += skip;
		if (skip)
			continue ;
		cmd_args[arg_idx] = ft_strdup(args[cidx]);
		arg_idx++;
		cidx++;
	}
	cmd_args[arg_idx] = NULL;
	return (cmd_args);
}
