/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:30:25 by kaltevog          #+#    #+#             */
/*   Updated: 2023/11/14 15:52:44 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_unset(char **args, char ***env)
{
	char	**rm_env;

	rm_env = cp_remove(*env, args[1]);
	if (!rm_env)
		return (ERROR);
	free_strarray(*env);
	*env = rm_env;
	return (SUCCESS);
}
