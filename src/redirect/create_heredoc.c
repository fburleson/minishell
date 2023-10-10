/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:36:38 by joel              #+#    #+#             */
/*   Updated: 2023/10/10 17:09:51 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	linelen(char *line)
{
	unsigned int	cidx;

	cidx = 0;
	while (line[cidx] && line[cidx] != '\n')
		cidx++;
	return (cidx);
}

static t_bool	is_line_limit(char *line, char *limit_str)
{
	unsigned int	cidx;
	unsigned int	len;

	cidx = 0;
	len = ft_max(linelen(line), ft_strlen(limit_str));
	while (cidx < len)
	{
		if (line[cidx] != limit_str[cidx])
			return (FALSE);
		cidx++;
	}
	return (TRUE);
}

static void	copy_to_heredoc(t_iofile *file, int heredoc)
{
	int		src;
	char	*line;

	src = open(file->path, O_RDONLY);
	if (src == -1)
	{
		print_err("file could not be opened: ", file->path);
		return ;
	}
	line = get_next_line(src);
	while (line && !is_line_limit(line, file->limit_str))
	{
		write(heredoc, line, ft_strlen(line));
		free(line);
		line = get_next_line(src);
	}
	close(src);
}

int	create_heredoc(t_iofile *file)
{
	int		heredoc;
	char	*tmpfile_path;

	tmpfile_path = "/tmp/.minishell_heredoc";
	heredoc = open(tmpfile_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (heredoc == -1)
	{
		print_err("file could not be opened: ", tmpfile_path);
		return (-1);
	}
	copy_to_heredoc(file, heredoc);
	close(heredoc);
	heredoc = open(tmpfile_path, O_RDONLY);
	if (heredoc == -1)
		print_err("file could not be opened: ", tmpfile_path);
	return (heredoc);
}
