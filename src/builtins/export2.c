/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:23 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/09/10 20:14:09 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_add(char *str, t_envs *env_list2)
{
	handle_node_add(str, &env_list2);
}

void	free_env_list(t_envs *list)
{
	t_envs	*next;

	while (list)
	{
		next = list->next;
		free(list->start);
		free(list->end);
		free(list->fullstr);
		free(list);
		list = next;
	}
}

void	print_list(t_envs *list_env)
{
	while (list_env)
	{
		printf("declare -x %s=\"%s\"\n", list_env->start, list_env->end);
		list_env = list_env->next;
	}
}

t_envs	*create_node(char *s, char *e, char *f)
{
	t_envs	*node;

	node = malloc(sizeof(t_envs));
	if (!node)
		exit(EXIT_FAILURE);
	node->start = strdup(s);
	node->end = strdup(e);
	node->fullstr = strdup(f);
	node->next = NULL;
	return (node);
}
