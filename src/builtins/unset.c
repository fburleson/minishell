/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:25 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/08/15 10:58:48 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_node(t_envs **head, const char *start_to_delete)
{
	t_envs	*current;
	t_envs	*prev;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->start, start_to_delete) == 0)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->start);
			free(current->end);
			free(current->fullstr);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

t_status	cmd_unset(char **args, t_envs *env_list)
{
	if (args[1])
		delete_node(&env_list, args[1]);
	return (0);
}
