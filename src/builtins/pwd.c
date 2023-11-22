/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:24:46 by joel              #+#    #+#             */
/*   Updated: 2023/11/22 21:02:41 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_pwd(char **env)
{
	char	*pwd;

	pwd = envvar("PWD", env);
	if (!pwd || ft_isempty(pwd))
	{
		free(pwd);
		return (ERROR);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (SUCCESS);
}
