/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:34:58 by joel              #+#    #+#             */
/*   Updated: 2023/08/03 20:00:24 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	n_red(char *line, char symbol)
{
	unsigned int	n;
	unsigned int	cidx;

	n = 0;
	cidx = 0;
	while (line[cidx])
	{
		while (line[cidx] && line[cidx] != symbol)
			cidx++;
		if (line[cidx] == symbol)
			n++;
		while (line[cidx] == symbol)
			cidx++;
		while (line[cidx] == ' ')
			cidx++;
		while (line[cidx] && line[cidx] != ' ')
			cidx++;
	}
	return (n);
}

static unsigned int	file_name_len(char *line)
{
	unsigned int	cidx;

	cidx = 0;
	while (line[cidx] && line[cidx] != ' ')
		cidx++;
	return (cidx);
}

static char	*copy_file_path(char *line)
{
	char			*copy;
	unsigned int	cidx;

	copy = (char *)malloc((file_name_len(line) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	cidx = 0;
	while (line[cidx] && line[cidx] != ' ')
	{
		copy[cidx] = line[cidx];
		cidx++;
	}
	copy[cidx] = '\0';
	return (copy);
}

static unsigned int	get_mode(char *line, char symbol)
{
	unsigned int	mode;

	if (symbol == OUTRED_SYM)
	{
		mode = OUTPUT_MODE;
		if (line[1] == symbol && line[2] != symbol)
			mode = APPEND_MODE;
	}
	else if (symbol == INRED_SYM)
		mode = INPUT_MODE;
	return (mode);
}

t_redir_file	**parse_redirection(char *line, char symbol)
{
	t_redir_file	**files;
	t_redir_file	*current_file;
	unsigned int	cidx;
	unsigned int	file_idx;

	files = (t_redir_file **)malloc((n_red(line, symbol) + 1) * sizeof(t_redir_file));
	if (!files)
		return (NULL);
	cidx = 0;
	file_idx = 0;
	while (line[cidx])
	{
		while (line[cidx] && line[cidx] != symbol)
			cidx++;
		if (!line[cidx])
			break ;
		current_file = (t_redir_file *)malloc(sizeof(t_redir_file));
		if (!current_file)
			return (NULL);
		current_file->mode = get_mode(line + cidx, symbol);
		while (line[cidx] == symbol)
			cidx++;
		while (line[cidx] == ' ')
			cidx++;
		current_file->file_path = copy_file_path(line + cidx);
		while (line[cidx] && line[cidx] != ' ')
			cidx++;
		files[file_idx] = current_file;
		file_idx++;
	}
	files[file_idx] = NULL;
	return (files);
}
