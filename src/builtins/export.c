/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:23 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/09/14 18:00:46 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_node_add(char *str, t_envs **env_list)
{
	t_envs	*current;
	char	*env_copy;
	char	*start;
	char	*end;
	char	*equal_sign;

	env_copy = ft_strdup(str);
	equal_sign = ft_strchr(env_copy, '=');
	if (!equal_sign)
		return ;
	*equal_sign = '\0';
	start = env_copy;
	end = equal_sign + 1;
	if (!*env_list)
		*env_list = create_node(start, end, str);
	else
	{
		current = *env_list;
		while (current->next)
			current = current->next;
		current->next = create_node(start, end, str);
	}
	free(env_copy);
}

static t_envs	*create_env_list(char *env_copy, char *fullstr)
{
	t_envs	*env_list;
	char	*start;
	char	*end;
	char	*equal_sign;

	equal_sign = ft_strchr(env_copy, '=');
	*equal_sign = '\0';
	start = env_copy;
	end = equal_sign + 1;
	env_list = create_node(start, end, fullstr);
	return (env_list);
}

static void	add_to_list(t_envs **head, t_envs **tail, char *str)
{
	t_envs	*env_list;
	char	*env_copy;

	env_copy = ft_strdup(str);
	env_list = create_env_list(env_copy, str);
	if (*head == NULL)
	{
		*head = env_list;
		*tail = *head;
	}
	else
	{
		(*tail)->next = env_list;
		*tail = env_list;
	}
	free(env_copy);
}

t_envs	*list_init(char **env)
{
	t_envs	*head;
	t_envs	*tail;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (env[i])
	{
		add_to_list(&head, &tail, env[i]);
		i++;
	}
	return (head);
}

t_status	cmd_export(char **args, char **env, t_envs *env_list)
{
	t_envs	*current;
	t_envs	*next;
	char	*prefix;

	if (args_null_or_empty(args, env, env_list) == 1)
		return (0);
	prefix = get_prefix(args[1]);
	if (!prefix)
	{
		handle_node_add(args[1], &env_list);
		return (0);
	}
	current = env_list;
	while (current)
	{
		next = current->next;
		if (!ft_strncmp(current->start, prefix, ft_strlen(prefix)))
			delete_node(&env_list, prefix);
		current = next;
	}
	handle_node_add(args[1], &env_list);
	free(prefix);
	return (0);
}
