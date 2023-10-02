/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:04:44 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/23 16:44:52 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_buff(int fd);
char	*get_line_buff(int fd, char *buff);
char	*get_line_from_buff(char *buff);
char	*rm_line_from_buff(char *buff);

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp_buff;
	static char	*buff[4096];

	if (fd < 3 && fd != 0)
		return (NULL);
	if (!buff[fd])
		buff[fd] = malloc_buff();
	if (!buff[fd])
		return (NULL);
	tmp_buff = get_line_buff(fd, buff[fd]);
	if (!tmp_buff)
		return (free_and_return(&buff[fd], NULL));
	line = get_line_from_buff(tmp_buff);
	if (!line)
		return (free_and_return(&buff[fd], &tmp_buff));
	free(buff[fd]);
	buff[fd] = rm_line_from_buff(tmp_buff);
	free(tmp_buff);
	if (*line == '\0')
		return (free_and_return(&buff[fd], &line));
	return (line);
}

char	*rm_line_from_buff(char *buff)
{
	char			*new_buff;
	unsigned int	offset;
	unsigned int	buff_offset;

	buff_offset = 0;
	offset = gnl_strlen(buff, '\n');
	if (*(buff + offset) == '\n')
		offset++;
	new_buff = malloc(gnl_strlen(buff, '\0') - gnl_strlen(buff, '\n') + 1);
	if (!new_buff)
		return (NULL);
	while (*(buff + offset))
	{
		*(new_buff + buff_offset) = *(buff + offset);
		buff_offset++;
		offset++;
	}
	*(new_buff + buff_offset) = '\0';
	return (new_buff);
}

char	*get_line_from_buff(char *buff)
{
	char			*line;
	unsigned int	offset;

	offset = 0;
	line = malloc(gnl_strlen(buff, '\n') + 2 - !gnl_strchr(buff, '\n'));
	if (!line)
		return (NULL);
	while (*(buff + offset) && *(buff + offset) != '\n')
	{
		*(line + offset) = *(buff + offset);
		offset++;
	}
	if (*(buff + offset) == '\n')
	{
		*(line + offset) = '\n';
		offset++;
	}
	*(line + offset) = '\0';
	return (line);
}

char	*get_line_buff(int fd, char *buff)
{
	char	*line_buff;
	char	*tmp_line_buff;
	char	*next_buff;

	line_buff = gnl_strjoin(buff, "");
	if (!line_buff)
		return (NULL);
	while (!gnl_strchr(line_buff, '\n'))
	{
		next_buff = get_next_buff(fd);
		if (!next_buff)
			return (free_and_return(&line_buff, NULL));
		tmp_line_buff = gnl_strjoin(line_buff, next_buff);
		free(line_buff);
		if (!tmp_line_buff)
			return (free_and_return(&next_buff, NULL));
		line_buff = tmp_line_buff;
		if (*next_buff == '\0')
		{
			free(next_buff);
			return (line_buff);
		}
		free(next_buff);
	}
	return (line_buff);
}

char	*get_next_buff(int fd)
{
	int		rd_bytes;
	char	*next_buff;

	next_buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!next_buff)
		return (NULL);
	rd_bytes = read(fd, next_buff, BUFFER_SIZE * sizeof(char));
	if (rd_bytes == -1)
	{
		free(next_buff);
		return (NULL);
	}
	*(next_buff + rd_bytes) = '\0';
	return (next_buff);
}
