/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:11:01 by joel              #+#    #+#             */
/*   Updated: 2023/07/19 16:19:25 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	file_name_len(char *start_name)
{
	unsigned int	cidx;

	cidx = 0;
	while (start_name[cidx] && ft_isalnum(start_name[cidx]))
		cidx++;
	return (cidx);
}

static char	*copy_file_name(char *start_name)
{
	char			*copy;
	unsigned int	cidx;

	copy = (char *)malloc((file_name_len(start_name) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	copy[0] = '\0';
	cidx = 0;
	while (ft_isalnum(start_name[cidx]))
	{
		copy[cidx] = start_name[cidx];
		cidx++;
	}
	copy[cidx] = '\0';
	return (copy);
}

char	*parse_redirection(char	*line)
{
	char			*file_name;
	unsigned int	cidx;

	cidx = 0;
	file_name = ft_strdup("");
	while (line[cidx])
	{
		while (line[cidx] && (line[cidx] == ' ' || ft_isalnum(line[cidx])))
			cidx++;
		if (line[cidx] == '>')
		{
			free(file_name);
			while (line[cidx] && line[cidx] == '>')
				cidx++;
			while (line[cidx] && line[cidx] == ' ')
				cidx++;
			file_name = copy_file_name(line + cidx);
			if (!file_name)
				return (NULL);
		}
		while (line[cidx] && ft_isalnum(line[cidx]))
			cidx++;
	}
	return (file_name);
}

t_bool	is_append_mode(char *line)
{
	t_bool			append_mode;
	unsigned int	cidx;

	append_mode = FALSE;
	cidx = 0;
	while (line[cidx])
	{
		while (line[cidx] && line[cidx] != '>')
			cidx++;
		if (line[cidx] == '>')
			append_mode = (line[cidx + 1] == '>');
		while (line[cidx] && line[cidx] == '>')
			cidx++;
	}
	return (append_mode);
}
