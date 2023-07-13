/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:40:45 by joel              #+#    #+#             */
/*   Updated: 2023/07/13 10:48:09 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_arr(char **str_arr)
{
	unsigned int	cidx;

	cidx = 0;
	while (str_arr[cidx])
	{
		free(str_arr[cidx]);
		cidx++;
	}
	free(str_arr);
}
