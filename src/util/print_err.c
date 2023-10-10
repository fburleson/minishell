/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:44 by joel              #+#    #+#             */
/*   Updated: 2023/10/10 17:01:30 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(char *message, char *info)
{
	int	tmp_stdout;

	tmp_stdout = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("error: %s %s\n", message, info);
	dup2(tmp_stdout, STDOUT_FILENO);
	close(tmp_stdout);
}
