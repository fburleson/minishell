/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:52:07 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 17:49:28 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_strcmp(char *s1, char *s2)
{
	return (!ft_strncmp(s1, s2, ft_max(ft_strlen(s1), ft_strlen(s2))));
}

t_bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "exit"))
		return (TRUE);
	if (ft_strcmp(cmd, "pwd"))
		return (TRUE);
	if (ft_strcmp(cmd, "cd"))
		return (TRUE);
	if (ft_strcmp(cmd, "env"))
		return (TRUE);
	if (ft_strcmp(cmd, "export"))
		return (TRUE);
	if (ft_strcmp(cmd, "unset"))
		return (TRUE);
	if (ft_strcmp(cmd, "echo"))
		return (TRUE);
	return (FALSE);
}
