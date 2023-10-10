/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:42:11 by joel              #+#    #+#             */
/*   Updated: 2023/10/10 16:11:42 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_echo(char **args)
{
	unsigned int	cidx;
	t_bool			has_newline;
	t_bool			n_option;

	cidx = 1;
	has_newline = TRUE;
	n_option = FALSE;
	if (args[1])
	{
		has_newline = strcmp(args[1], "-n");
		n_option = !ft_strncmp(args[1], "-n", 2);
	}
	if (!has_newline || n_option)
		cidx = 2;
	while (args[cidx])
	{
		printf("%s", args[cidx]);
		cidx++;
		if (args[cidx])
			printf(" ");
	}
	if (has_newline)
		printf("\n");
	return (SUCCESS);
}
