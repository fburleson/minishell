/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:43:16 by joel              #+#    #+#             */
/*   Updated: 2023/07/13 10:43:33 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_arr_len(char **str_arr)
{
	unsigned int	cidx;

	cidx = 0;
	while (str_arr[cidx])
		cidx++;
	return (cidx);
}
