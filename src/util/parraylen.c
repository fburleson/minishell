/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parraylen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:35 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/09/06 18:12:04 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	parraylen(char **array)
{
	unsigned int	cidx;

	cidx = 0;
	while (array[cidx])
		cidx++;
	return (cidx);
}
