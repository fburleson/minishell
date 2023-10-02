/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:51:57 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/26 20:30:06 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_htoi(const char *str)
{
	unsigned int	offset;
	int				to;

	offset = 2;
	to = 0;
	while (ft_isspace(*(str + offset)))
		offset++;
	while (ft_ishdigit(*(str + offset)))
	{
		to *= 16;
		if (ft_isdigit(*(str + offset)))
			to += *(str + offset) - 48;
		else if (*(str + offset) >= 'A' && *(str + offset) <= 'F')
			to += *(str + offset) - 'A' + 10;
		else
			to += *(str + offset) - 'a' + 10;
		offset++;
	}
	return (to);
}
