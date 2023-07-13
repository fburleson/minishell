/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:11:30 by joel              #+#    #+#             */
/*   Updated: 2023/07/13 11:04:49 by joel             ###   ########.fr       */
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

static char	*get_abs_path(char *path, char **env)
{
	char			**env_paths;
	t_dir			*current_dir;
	unsigned int	current_env_path;
	t_dirent		*ent;
	char			*abs_path;
	char			*path_var;

	path_var = env_var("PATH", env);
	env_paths = ft_split(path_var, ':');
	free(path_var);
	if (!env_paths)
		return (NULL);
	current_env_path = 0;
	while (env_paths[current_env_path])
	{
		current_dir = opendir(env_paths[current_env_path]);
		ent = readdir(current_dir);
		while (ent)
		{
			if (!ft_strncmp(path, ent->d_name,
					ft_max(ft_strlen(path), ft_strlen(ent->d_name))))
			{
				closedir(current_dir);
				abs_path = join_paths(env_paths[current_env_path], path);
				free_str_arr(env_paths);
				return (abs_path);
			}
			ent = readdir(current_dir);
		}
		closedir(current_dir);
		current_env_path++;
	}
	free_str_arr(env_paths);
	return (NULL);
}

t_status	exec_program(char *path, char **args, char **env)
{
	t_pid		p_id;
	int			status;
	char		*exec_path;
	int			fd;

	status = SUCCESS;
	if (path[0] == '/')
	{
		exec_path = ft_strdup(path);
		fd = open(exec_path, O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			free(exec_path);
			return (CMD_NOT_FOUND_STATUS);
		}
		close(fd);
	}
	else
	{
		exec_path = get_abs_path(path, env);
		if (!exec_path)
		{
			free(exec_path);
			return (CMD_NOT_FOUND_STATUS);
		}
	}
	p_id = fork();
	if (p_id == 0)
		execve(exec_path, args, env);
	else
		wait(&status);
	free(exec_path);
	return ((t_status) status);
}
