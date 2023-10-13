/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:27:14 by joel              #+#    #+#             */
/*   Updated: 2023/10/13 16:25:53 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*readline_limit(char *limit_str)
{
	char	*line;
	char	*tmp_line;
	char	*raw_current_line;
	char	*current_line;

	raw_current_line = ft_strdup("");
	line = ft_strdup("");
	while (raw_current_line && !cmpstr(raw_current_line, limit_str))
	{
		free(raw_current_line);
		raw_current_line = readline("> ");
		current_line = ft_strjoin(raw_current_line, "\n");
		tmp_line = ft_strjoin(line, current_line);
		free(current_line);
		free(line);
		line = tmp_line;
	}
	free(raw_current_line);
	return (line);
}

static t_bool	is_delimiter(char *line, char *delimiter)
{
	t_bool			is_delimiter;
	char			*copy;
	unsigned int	cidx;

	copy = (char *)malloc((lstrlen(line, "\n", 0)) * sizeof(char));
	if (!copy)
		return (TRUE);
	cidx = 0;
	while (line[cidx] && line[cidx] != '\n')
	{
		copy[cidx] = line[cidx];
		cidx++;
	}
	is_delimiter = cmpstr(copy, delimiter);
	free(copy);
	return (is_delimiter);
}

void	write_to_heredoc(t_iofile *infile)
{
	char			*line;
	int				fd_heredoc;
	unsigned int	cidx;

	line = readline_limit(infile->limit_str);
	fd_heredoc = ft_open(infile->path, O_WRONLY | O_TRUNC | O_CREAT);
	cidx = 0;
	while (line[cidx] && !is_delimiter(line + cidx, infile->limit_str))
	{
		write(fd_heredoc, line + cidx, lstrlen(line + cidx, "\n", 0) + 1);
		cidx += lstrlen(line + cidx, "\n", 0) + 1;
	}
	free(line);
	close(fd_heredoc);
}
