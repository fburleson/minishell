/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:49 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:27:18 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	offset;
	int				to;
	int				sign;

	offset = 0;
	to = 0;
	sign = 1;
	while (ft_isspace(*(str + offset)))
		offset++;
	if (*(str + offset) == '-')
	{
		sign = -1;
		offset++;
	}
	else if (*(str + offset) == '+')
		offset++;
	while (ft_isdigit(*(str + offset)))
	{
		to *= 10;
		to += *(str + offset) - 48;
		offset++;
	}
	return (to * sign);
}
