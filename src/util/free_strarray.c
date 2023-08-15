/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:32:43 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 14:35:12 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strarray(char **array)
{
	unsigned int	cidx;

	cidx = 0;
	while (array[cidx])
	{
		free(array[cidx]);
		cidx++;
	}
	free(array);
}
