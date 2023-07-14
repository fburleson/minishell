/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_file_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:28:31 by joel              #+#    #+#             */
/*   Updated: 2023/07/14 11:30:56 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	does_file_exist(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
