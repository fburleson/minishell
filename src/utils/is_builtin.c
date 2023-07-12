/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:52:07 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 15:58:32 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	strcmp(char *s1, char *s2)
{
	return (!ft_strncmp(s1, s2, ft_max(ft_strlen(s1), ft_strlen(s2))));
}

t_bool	is_builtin(char *cmd)
{
	if (strcmp(cmd, "exit"))
		return (TRUE);
	if (strcmp(cmd, "pwd"))
		return (TRUE);
	if (strcmp(cmd, "cd"))
		return (TRUE);
	if (strcmp(cmd, "env"))
		return (TRUE);
	if (strcmp(cmd, "export"))
		return (TRUE);
	if (strcmp(cmd, "unset"))
		return (TRUE);
	if (strcmp(cmd, "echo"))
		return (TRUE);
	return (FALSE);
}
