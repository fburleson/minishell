/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:01:59 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:23:53 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	unsigned int	offset;
	char			temp;
	size_t			str_len;

	str_len = ft_strlen(str);
	offset = 0;
	while (offset < str_len / 2)
	{
		temp = *(str + offset);
		*(str + offset) = *(str + str_len - offset - 1);
		*(str + str_len - offset - 1) = temp;
		offset++;
	}
}
