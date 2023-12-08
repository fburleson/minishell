/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:11:17 by joel              #+#    #+#             */
/*   Updated: 2023/12/08 15:11:29 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_builtin(char *cmd)
{
	if (cmpstr(cmd, "exit"))
		return (TRUE);
	if (cmpstr(cmd, "pwd"))
		return (TRUE);
	if (cmpstr(cmd, "cd"))
		return (TRUE);
	if (cmpstr(cmd, "env"))
		return (TRUE);
	if (cmpstr(cmd, "export"))
		return (TRUE);
	if (cmpstr(cmd, "unset"))
		return (TRUE);
	if (cmpstr(cmd, "echo"))
		return (TRUE);
	return (FALSE);
}
