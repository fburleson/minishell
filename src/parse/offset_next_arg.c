/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_next_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:07:37 by joel              #+#    #+#             */
/*   Updated: 2023/12/04 12:54:29 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	offset_pipe(char *start_arg)
{
	unsigned int	cidx;

	cidx = 1;
	while (ft_isspace(start_arg[cidx]))
		cidx++;
	return (cidx);
}

static unsigned int	offset_io(char *start_arg, char c)
{
	unsigned int	cidx;

	cidx = 1;
	if (start_arg[cidx] == c)
		cidx++;
	while (ft_isspace(start_arg[cidx]))
		cidx++;
	return (cidx);
}

unsigned int	offset_next_arg(char *start_arg)
{
	unsigned int	cidx;

	cidx = 0;
	if (start_arg[cidx] == '|')
		return (offset_pipe(start_arg));
	else if (start_arg[cidx] == '>')
		return (offset_io(start_arg, start_arg[cidx]));
	else if (start_arg[cidx] == '<')
		return (offset_io(start_arg, start_arg[cidx]));
	while (start_arg[cidx] && !ft_isspace(start_arg[cidx]))
	{
		if (start_arg[cidx] == '\'')
			cidx += lstrlen(start_arg + cidx, "\'", 1) + 1;
		else if (start_arg[cidx] == '\"')
			cidx += lstrlen(start_arg + cidx, "\"", 1) + 1;
		else
		{
			cidx++;
			if (ft_strrchr("|<>", start_arg[cidx]))
				return (cidx);
		}
	}
	while (start_arg[cidx] && ft_isspace(start_arg[cidx]))
		cidx++;
	return (cidx);
}
