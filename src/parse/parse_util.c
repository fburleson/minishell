/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:21:32 by joel              #+#    #+#             */
/*   Updated: 2023/08/11 13:52:16 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_delimiters(char c)
{
	if (c == '\'')
		return (ft_strdup("\'"));
	else if (c == '\"')
		return (ft_strdup("\""));
	else if (c == '>')
		return (excludechars(">"));
	else if (c == '<')
		return (excludechars("<"));
	else if (c == '|')
		return (excludechars("|"));
	return (ft_strdup("\'\"><| "));
}

static unsigned int	envvar_namelen(char *line)
{
	unsigned int	cidx;

	cidx = 1;
	if (cmpstr(line + cidx, "?"))
		return (1);
	while (ft_isalnum(line[cidx]))
		cidx++;
	return (cidx - 1);
}

char	*envvar_name(char *line)
{
	char			*name;
	unsigned int	len;
	unsigned int	cidx;

	len = envvar_namelen(line);
	name = (char *)malloc((len + 1) * sizeof(char));
	if (!name)
		return (NULL);
	cidx = 0;
	while (cidx < len)
	{
		name[cidx] = line[cidx + 1];
		cidx++;
	}
	name[cidx] = '\0';
	return (name);
}
