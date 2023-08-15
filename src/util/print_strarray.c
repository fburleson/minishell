/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:22:27 by joel              #+#    #+#             */
/*   Updated: 2023/08/10 21:26:52 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_strarray(char **array)
{
	unsigned int	cidx;

	cidx = 0;
	printf("[");
	while (array[cidx + 1])
	{
		printf("\"%s\", ", array[cidx]);
		cidx++;
	}
	printf("\"%s\"]\n", array[cidx]);
}
