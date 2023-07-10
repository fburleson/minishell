/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 19:42:11 by joel          #+#    #+#                 */
/*   Updated: 2023/07/10 18:10:06 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_qoutes(char *arg)
{
	unsigned int	cidx;

	cidx = 1;
	while (arg[cidx] && arg[cidx] != '\"' && arg[cidx] != '\'')
	{
		printf("%c", arg[cidx]);
		cidx++;
	}
}

unsigned int	cmd_echo(char **args)
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
		if (args[cidx][0] == '\'' || args[cidx][0] == '\"')
			print_qoutes(args[cidx]);
		else
			printf("%s", args[cidx]);
		cidx++;
		if (args[cidx])
			printf(" ");
	}
	if (has_newline)
		printf("\n");
	return (SUCCESS);
}
