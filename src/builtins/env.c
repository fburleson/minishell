/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:31:46 by joel              #+#    #+#             */
/*   Updated: 2023/08/12 14:31:55 by joel             ###   ########.fr       */
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
