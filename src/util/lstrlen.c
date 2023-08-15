/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:11:16 by joel              #+#    #+#             */
/*   Updated: 2023/08/09 17:20:06 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	lstrlen(char *str, char	*delimiters, unsigned int threshold)
{
	unsigned int	cidx;
	unsigned int	n;

	cidx = 0;
	n = 0;
	while (str[cidx] && n <= threshold)
	{
		if (ft_strnchr(delimiters, str[cidx]))
			n++;
		if (n <= threshold)
			cidx++;
	}
	return (cidx);
}
