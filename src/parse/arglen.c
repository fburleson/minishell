/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:35 by joel              #+#    #+#             */
/*   Updated: 2023/12/02 17:48:40 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	arglen_out(char *start_arg)
{
	if (start_arg[1] == '>')
		return (2);
	return (1);
}

static unsigned int	arglen_in(char *start_arg)
{
	if (start_arg[1] == '<')
		return (2);
	return (1);
}

static unsigned int	count_quoted(char *start_quotes, char quote_type)
{
	int				count;
	char			str[2];

	str[0] = quote_type;
	str[1] = '\0';
	count = lstrlen(start_quotes, str, 1);
	return (count);
}

unsigned int	arglen(char *start_arg)
{
	unsigned int	len;
	unsigned int	cidx;

	cidx = 0;
	len = 0;
	if (start_arg[cidx] == '|')
		return (1);
	else if (start_arg[cidx] == '>')
		return (arglen_out(start_arg));
	else if (start_arg[cidx] == '<')
		return (arglen_in(start_arg));
	while (start_arg[cidx] && !ft_isspace(start_arg[cidx])
		&& !ft_strrchr("|<>", start_arg[cidx]))
	{
		if (start_arg[cidx] == '\'' || start_arg[cidx] == '\"')
		{
			cidx = count_quoted(start_arg + cidx, start_arg[cidx]);
			len = count_quoted(start_arg + cidx, start_arg[cidx]) - 1;
		}
		else
			len++;
		cidx++;
	}
	return (len);
}
