/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:25 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/09/14 17:06:34 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_node(t_envs **head, const char *start_to_delete)
{
	t_envs	*current;
	t_envs	*prev;
	size_t	len;

	current = *head;
	prev = NULL;
	len = ft_strlen(start_to_delete);
	while (current != NULL)
	{
		if (ft_strncmp(current->start, start_to_delete, len) == 0)
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

void	remove_env_var(char ***env_array, int remove_index)
{
	int	shift_index;

	free((*env_array)[remove_index]);
	shift_index = remove_index;
	while ((*env_array)[shift_index])
	{
		(*env_array)[shift_index] = (*env_array)[shift_index + 1];
		shift_index++;
	}
}

void	unset_env(char ***env_array, const char *variable_name)
{
	int		index;
	char	*current_var_prefix;
	size_t	var_length;

	var_length = strlen(variable_name);
	index = 0;
	while ((*env_array)[index])
	{
		current_var_prefix = strndup((*env_array)[index], var_length);
		if (strcmp(current_var_prefix, variable_name) == 0 && \
			((*env_array)[index][var_length] == '=' || \
			(*env_array)[index][var_length] == '\0'))
		{
			free(current_var_prefix);
			remove_env_var(env_array, index);
			return ;
		}
		free(current_var_prefix);
		index++;
	}
}

t_status	cmd_unset(char **args, t_envs *env_list, char **env)
{
	if (args[1])
	{
		delete_node(&env_list, args[1]);
		unset_env(&env, args[1]);
	}
	return (0);
}
