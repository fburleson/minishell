/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:28:36 by joel              #+#    #+#             */
/*   Updated: 2023/07/11 13:12:16 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_env(char **env)
{
	unsigned int	cidx;

	cidx = 0;
	while (env[cidx])
	{
		printf("%s\n", env[cidx]);
		cidx++;
	}
	return (SUCCESS);
}
