/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:11:30 by joel              #+#    #+#             */
/*   Updated: 2023/07/12 15:26:42 by fsarkoh          ###   ########.fr       */
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

	env_paths = ft_split(env_var("PATH", env), ':');
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
				return (join_paths(env_paths[current_env_path], path));
			ent = readdir(current_dir);
		}
		current_env_path++;
	}
	return (NULL);
}

t_status	exec_program(char *path, char **args, char **env)
{
	t_pid		p_id;
	int			status;
	char		*abs_path;
	char		*exec_path;

	status = SUCCESS;
	abs_path = get_abs_path(path, env);
	exec_path = abs_path;
	if (path[0] == '/')
		exec_path = path;
	p_id = fork();
	if (p_id != 0)
		waitpid(p_id, &status, WUNTRACED);
	else
		execve(exec_path, args, env);
	return ((t_status) status);
}
