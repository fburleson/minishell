/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:20:25 by joel              #+#    #+#             */
/*   Updated: 2023/11/13 19:53:42 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_exit(char **args)
{
	printf("exit\n");
	if (strarraylen(args) > 2)
	{
		print_err("too many arguments", "");
		exit(STATUS_TOO_MANY_ARGS);
	}
	else if (strarraylen(args) == 2)
		exit(ft_atoi(args[1]));
	exit(SUCCESS);
}
