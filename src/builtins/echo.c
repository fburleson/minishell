/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:42:11 by joel              #+#    #+#             */
/*   Updated: 2023/08/23 15:35:10 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_echo(char **args)
{
	unsigned int	cidx;
	t_bool			has_newline;

	cidx = 1;
	has_newline = TRUE;
	if (args[1])
		has_newline = ft_strncmp(args[1], "-n", ft_max(ft_strlen(args[1]), 2));
	if (!has_newline)
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
