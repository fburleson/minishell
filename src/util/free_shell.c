/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:27 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/09/19 15:09:18 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	free(shell->line);
	free_strarray(shell->args);
	free_cmds(shell->cmds);
}
