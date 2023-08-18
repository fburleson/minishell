/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:34:45 by joel              #+#    #+#             */
/*   Updated: 2023/08/18 16:30:50 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_strarray(char **array)
{
	char			**copy;
	unsigned int	cidx;

	copy = (char **)malloc((strarraylen(array) + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	cidx = 0;
	while (array[cidx])
	{
		copy[cidx] = ft_strdup(array[cidx]);
		cidx++;
	}
	copy[cidx] = NULL;
	return (copy);
}
