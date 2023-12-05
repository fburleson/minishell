/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_relative.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 14:12:11 by kaltevog      #+#    #+#                 */
/*   Updated: 2023/12/05 14:16:45 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*resolve_path(const char *relative_path, const char *current_dir)
{
	char	*temp_path;
	char	*resolved_path;

	temp_path = ft_strjoin(current_dir, "/");
	resolved_path = ft_strjoin(temp_path, relative_path);
	free(temp_path);
	return (resolved_path);
}

char	*expand_period(char **args, char **env)
{
	char	*current_dir;
	char	*expanded_path;

	current_dir = envvar("PWD", env);
	if (!current_dir)
		current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (NULL);
	expanded_path = resolve_path(args[0], current_dir);
	free(current_dir);
	return (expanded_path);
}
