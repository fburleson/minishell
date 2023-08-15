/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:51:10 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 13:55:05 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_status	g_exit_status;

char	*envvar(char *name, char **env)
{
	unsigned int	cidx;

	if (cmpstr(name, "?"))
		return (ft_itoa(g_exit_status));
	cidx = 0;
	while (env[cidx])
	{
		if (!ft_strncmp(name, env[cidx],
				ft_max(ft_strlen(name), lstrlen(env[cidx], "=", 0))))
			return (ft_strdup(env[cidx] + lstrlen(env[cidx], "=", 0) + 1));
		cidx++;
	}
	return (ft_strdup(""));
}
