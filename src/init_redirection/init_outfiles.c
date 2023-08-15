/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_outfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:28:06 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 16:42:24 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	n_files(char **args)
{
	unsigned int	n;
	unsigned int	cidx;

	n = 0;
	cidx = 0;
	while (args[cidx] && !cmpstr(args[cidx], "|"))
	{
		if (cmpstr(args[cidx], ">") || cmpstr(args[cidx], ">>"))
			n++;
		cidx++;
	}
	return (n);
}

t_iofile	**init_outfiles(char **args)
{
	t_iofile		**outfiles;
	t_iofile		*current_outfile;
	unsigned int	file_idx;
	unsigned int	cidx;

	outfiles = (t_iofile **)malloc((n_files(args) + 1) * sizeof(t_iofile *));
	if (!outfiles)
		return (NULL);
	file_idx = 0;
	cidx = 0;
	while (args[cidx] && !cmpstr(args[cidx], "|"))
	{
		if (cmpstr(args[cidx], ">") || cmpstr(args[cidx], ">>"))
		{
			current_outfile = init_iofile(args + cidx);
			outfiles[file_idx] = current_outfile;
			file_idx++;
		}
		cidx++;
	}
	outfiles[file_idx] = NULL;
	return (outfiles);
}
