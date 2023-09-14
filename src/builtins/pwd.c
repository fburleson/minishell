/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 16:24:46 by joel          #+#    #+#                 */
/*   Updated: 2023/09/14 17:30:59 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_pwd(t_envs *env_list)
{
	t_envs	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strncmp(current->start, "PWD", 3) == 0)
		{
			printf("%s\n", current->end);
			return (SUCCESS);
		}
		current = current->next;
	}
	return (ERROR);
}
