/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:24:46 by joel              #+#    #+#             */
/*   Updated: 2023/07/13 10:52:25 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_pwd(char **env)
{
	char	*value;

	value = env_var("PWD", env);
	printf("%s\n", value);
	free(value);
	return (SUCCESS);
}
