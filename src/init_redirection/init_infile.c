/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:33:37 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 17:15:43 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_iofile	*init_infile(char **args)
{
	t_iofile		*infile;
	unsigned int	cidx;

	infile = NULL;
	cidx = 0;
	while (args[cidx] && !cmpstr(args[cidx], "|"))
	{
		if (cmpstr(args[cidx], "<") || cmpstr(args[cidx], "<<"))
		{
			if (infile)
				free_iofile(infile);
			infile = init_iofile(args + cidx);
		}
		cidx++;
	}
	return (infile);
}
