/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_relative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:12:11 by kaltevog          #+#    #+#             */
/*   Updated: 2023/12/08 13:48:42 by joel             ###   ########.fr       */
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

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (NULL);
	expanded_path = resolve_path(args[0], current_dir);
	free(current_dir);
	return (expanded_path);
}
