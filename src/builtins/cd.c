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

char	*ft_strreplace(char *dest, int startdest, char *src, int startsrc)
{
	int		len_dest;
	int		len_src;
	int		len_replace;
	char	*new_str;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	len_replace = len_dest - startdest + len_src - startsrc;
	new_str = (char *)malloc(len_replace + 1);
	if (new_str == NULL)
		return (0);
	ft_strlcpy(new_str, dest, startdest + 1);
	ft_strlcat(new_str, src + startsrc, len_replace + 1);
	free(dest);
	return (new_str);
}

int	shortenlines(char **env, char *oldorcurrent, int sevenorfour)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], oldorcurrent, sevenorfour) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	change_directory(char *path, char **env)
{
	int		pwd_in;
	int		oldpwd_in;
	char	temp[4096];

	pwd_in = shortenlines(env, "PWD=", 4);
	oldpwd_in = shortenlines(env, "OLDPWD=", 7);
	if (!path || path[0] == '~' || path[0] == '\0')
	{
		path = getenv("HOME");
		chdir(path);
	}
	else if (path[0] == '-')
	{
		if (oldpwd_in != -1)
			chdir(&env[oldpwd_in][7]);
	}
	else if (chdir(path) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
	}
	if (oldpwd_in != -1)
		env[oldpwd_in] = ft_strreplace(env[oldpwd_in], 7, env[pwd_in] + 4, 0);
	getcwd(temp, sizeof(temp));
	env[pwd_in] = ft_strreplace(env[pwd_in], 4, temp, 0);
}

t_status	cmd_cd(char **args, char **env)
{
	char	*path;

	if (!env || !getenv("HOME"))
	{
		printf("HOME= not found in **env\n");
		return (ERROR);
	}
	path = args[1];
	change_directory(path, env);
	return (SUCCESS);
}
