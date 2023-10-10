/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:17:11 by joel              #+#    #+#             */
/*   Updated: 2023/10/10 17:31:15 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open(char *file_name, int flags)
{
	int	fd;

	fd = open(file_name, flags);
	if (fd == -1)
		print_err("file could not be opened: ", file_name);
	return (fd);
}

int	ft_mopen(char *file_name, int flags, int permissions)
{
	int	fd;

	fd = open(file_name, flags, permissions);
	if (fd == -1)
		print_err("file could not be opened: ", file_name);
	return (fd);
}
