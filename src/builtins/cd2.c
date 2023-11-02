/* ************************************************************************** */
/*																			*/
/*													    ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 15:30:21 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/07/20 20:05:28 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envs	*find_in_env_list(t_envs *env_list, const char *key)
{
	t_envs	*current;

	current = env_list;
	while (current)
	{
		if (ft_strncmp(current->start, key, ft_strlen(key)) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	updatelistentry(t_envs *entry, const char *new_end)
{
	if (entry && entry->end)
	{
		free(entry->end);
		entry->end = ft_strdup(new_end);
		if (entry->fullstr)
		{
			free(entry->fullstr);
			entry->fullstr = ft_strjoin(entry->start, entry->end);
		}
	}
}

char	*expand_tilde_path(char *path, char *home)
{
	char	*expanded_path;
	size_t	size_needed;

	if (!path)
		return (NULL);
	if (path[0] != '~' || (path[1] != '/' && path[1] != '\0'))
		return (ft_strdup(path));
	if (!home)
		return (ft_strdup(path));
	size_needed = ft_strlen(home) + ft_strlen(path);
	expanded_path = (char *)malloc(size_needed + 1);
	if (!expanded_path)
		return (NULL);
	ft_strlcpy(expanded_path, home, size_needed);
	ft_strlcat(expanded_path, path + 1, size_needed);
	return (expanded_path);
}

int	is_home_set(t_envs *env_list)
{
	t_envs	*current;

	current = env_list;
	while (current)
	{
		if (ft_strncmp(current->fullstr, "HOME", 4) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}
