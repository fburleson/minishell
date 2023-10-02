/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:10:29 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/12 17:17:28 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strnchr(char *str, char c)
{
	unsigned int	offset;
	unsigned int	n;

	offset = 0;
	n = 0;
	while (*(str + offset))
	{
		if (*(str + offset) == c)
			n++;
		offset++;
	}
	return (n);
}
