/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:06:41 by joel              #+#    #+#             */
/*   Updated: 2023/12/02 17:51:59 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_arg(char *start_arg)
{
	char			*arg;
	unsigned int	carg;
	unsigned int	len;
	unsigned int	cidx;

	len = arglen(start_arg);
	arg = (char *)malloc((len + 1) * sizeof(char));
	if (!arg)
		return (NULL);
	cidx = 0;
	carg = 0;
	while (start_arg[cidx] && carg < len)
	{
		if (ft_strrchr("\'\"", start_arg[cidx]))
		{
			cidx++;
			continue ;
		}
		arg[carg] = start_arg[cidx];
		carg++;
		cidx++;
	}
	arg[carg] = '\0';
	return (arg);
}
