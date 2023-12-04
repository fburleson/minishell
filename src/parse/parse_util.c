/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:09:47 by joel              #+#    #+#             */
/*   Updated: 2023/12/04 17:54:22 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*envvar_name(char *start_var)
{
	char			*name;
	unsigned int	size;

	size = lstrlen(start_var + 1, " |<>\'\"$", 0) + 1;
	name = (char *)malloc(size);
	if (!name)
		return (NULL);
	ft_strlcpy(name, start_var + 1, size);
	return (name);
}
