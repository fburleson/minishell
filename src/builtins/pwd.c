/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:29:56 by joel              #+#    #+#             */
/*   Updated: 2023/08/12 14:30:22 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	cmd_pwd(char **env)
{
	char	*value;

	value = envvar("PWD", env);
	printf("%s\n", value);
	free(value);
	return (SUCCESS);
}
