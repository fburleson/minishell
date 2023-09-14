/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 14:28:36 by joel          #+#    #+#                 */
/*   Updated: 2023/09/14 17:18:43 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_env(t_envs *env_list)
{
	t_envs	*current;

	current = env_list;
	while (current != NULL)
	{
		if (current->fullstr)
			printf("%s\n", current->fullstr);
		current = current->next;
	}
	return (SUCCESS);
}
