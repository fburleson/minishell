/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:29:03 by joel              #+#    #+#             */
/*   Updated: 2023/05/22 22:32:33 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char *str)
{
	unsigned int	cidx;

	cidx = 0;
	while (*(str + cidx))
	{
		if (!ft_isspace(*(str + cidx)))
			return (0);
		cidx++;
	}
	return (1);
}
