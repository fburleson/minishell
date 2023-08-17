/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:23 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/08/15 10:47:59 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_envs *list_env)
{
	while (list_env != NULL)
	{
		printf("declare -x %s=\"%s\"\n", list_env->start, list_env->end);
		list_env = list_env->next;
	}
}

void	node_add(char *str, t_envs *env_list2)
{
	t_envs	*current;
	t_envs	*env_list;
	char	*env_copy;
	char	*start;
    char	*end;
    char	*fullstr;
	char	*equal_sign;

	env_copy = strdup(str);
	equal_sign = strchr(env_copy, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		start = env_copy;
		end = equal_sign + 1;
		fullstr = str;
		env_list = (t_envs *)malloc(sizeof(t_envs));
		env_list->start = strdup(start);
		env_list->end = strdup(end);
		env_list->fullstr = strdup(fullstr);
		env_list->next = NULL;
		if (!env_list2)
			env_list2 = env_list;
		else
		{
			current = env_list2;
			while (current->next)
				current = current->next;
			current->next = env_list;
		}
	}
	free(env_copy);
}

void	free_env_list(t_envs *list)
{
	t_envs	*next;

	while (list != NULL)
	{
		next = list->next;
		free(list->start);
		free(list->end);
		free(list->fullstr);
		free(list);
		list = next;
	}
}

t_envs	*list_init(char **env)
{
	t_envs	*env_list;
    t_envs	*head = NULL;
	t_envs	*tail = NULL;
	int		i;
	char	*env_copy;
	char	*start;
	char	*end;
	char	*fullstr;
	char	*equal_sign;

	i = 0;
	while (env[i] != NULL)
	{
		env_copy = strdup(env[i]);
		equal_sign = strchr(env_copy, '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			start = env_copy;
			end = equal_sign + 1;
			fullstr = env[i];
			env_list = (t_envs *)malloc(sizeof(t_envs));
			if (env_list == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			env_list->start = strdup(start);
			env_list->end = strdup(end);
			env_list->fullstr = strdup(fullstr);
			env_list->next = NULL;
			if (head == NULL)
			{
				tail = env_list;
				head = tail;
			}
			else
			{
				tail->next = env_list;
				tail = env_list;
			}
		}
		free(env_copy);
		i++;
	}
	env_list = head;
	return (env_list);
}

t_status	cmd_export(char **args, char **env, t_envs *env_list)
{
	t_envs	*current;
	int		i;
	char	*magic;

	i = 0;
	current = env_list;
	if (!env)
		printf("noenv");
	if (!args[1] || args[1][0] == '\0')
	{
		print_list(env_list);
		return (0);
	}
	magic = ft_strdup(args[1]);
	while (magic[i])
	{
		if (magic[i] == '=')
			magic[i] = '\0';
		i++;
	}
	while (current)
	{
		if (ft_strncmp(current->start, magic, ft_strlen(magic)) == 0)
		{
			ft_strlcpy(current->end, "heythisislong", 13);
			i = -1;
			printf("imin");
		}
		current = current->next;
	}
	if (i != -1 && args[1])
		node_add(args[1], env_list);
	return (0);
}
