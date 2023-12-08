/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:44:40 by joel              #+#    #+#             */
/*   Updated: 2023/12/08 15:12:56 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_paths(char *path1, char *path2)
{
	char			*joined;

	joined = (char *)malloc((ft_strlen(path1) + ft_strlen(path2) + 2)
			* sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, path1, ft_strlen(path1) + 1);
	joined[ft_strlen(path1)] = '/';
	ft_strlcpy(joined + ft_strlen(path1) + 1, path2, ft_strlen(path2) + 1);
	return (joined);
}

static char	**get_env_paths(char **env)
{
	char	**env_paths;
	char	*path_var;

	path_var = envvar("PATH", env);
	if (!path_var)
		return (NULL);
	if (ft_isempty(path_var))
	{
		env_paths = (char **)malloc(2 * sizeof(char *));
		env_paths[0] = NULL;
		env_paths[1] = NULL;
	}
	else
		env_paths = ft_split(path_var, ':');
	if (!env_paths)
		return (NULL);
	free(path_var);
	return (env_paths);
}

static t_bool	dir_has_file(t_dir	*dir, char *file_name)
{
	t_dirent	*entry;

	if (!dir)
		return (FALSE);
	entry = readdir(dir);
	while (entry)
	{
		if (!ft_strncmp(file_name, entry->d_name,
				ft_max(ft_strlen(file_name), ft_strlen(entry->d_name))))
			return (TRUE);
		entry = readdir(dir);
	}
	return (FALSE);
}

static char	*return_abs_path(char *path, char **env_paths,
		unsigned int env_path_idx)
{
	char	*abs_path;

	abs_path = join_paths(env_paths[env_path_idx], path);
	free_strarray(env_paths);
	return (abs_path);
}

char	*get_abs_path(char *path, char **env)
{
	char			**env_paths;
	t_dir			*current_dir;
	unsigned int	current_env_path;

	env_paths = get_env_paths(env);
	if (!env_paths)
		return (NULL);
	if (!env_paths[0])
		env_paths[0] = envvar("PWD", env);
	current_env_path = 0;
	while (env_paths[current_env_path])
	{
		current_dir = opendir(env_paths[current_env_path]);
		if (dir_has_file(current_dir, path) && current_dir)
		{
			closedir(current_dir);
			return (return_abs_path(path, env_paths, current_env_path));
		}
		if (current_dir)
			closedir(current_dir);
		current_env_path++;
	}
	free_strarray(env_paths);
	return (NULL);
}
