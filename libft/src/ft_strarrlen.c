/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:51:09 by joel              #+#    #+#             */
/*   Updated: 2023/05/20 14:52:22 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strarrlen(char	**strarr)
{
	unsigned int	cidx;

	cidx = 0;
	while (*(strarr + cidx))
		cidx++;
	return (cidx);
}
