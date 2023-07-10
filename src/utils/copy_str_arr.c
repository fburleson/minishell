/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:49:02 by joel              #+#    #+#             */
/*   Updated: 2023/06/27 21:58:19 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	str_arr_len(char **str_arr)
{
	unsigned int	cidx;

	cidx = 0;
	while (str_arr[cidx])
		cidx++;
	return (cidx);
}

char	**copy_str_arr(char **str_arr)
{
	char			**copy;
	unsigned int	cidx;

	copy = (char **)malloc((str_arr_len(str_arr) + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	cidx = 0;
	while (str_arr[cidx])
	{
		copy[cidx] = ft_strdup(str_arr[cidx]);
		cidx++;
	}
	copy[cidx] = NULL;
	return (copy);
}
