/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:02:46 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/23 16:44:52 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*malloc_buff(void);
char	*gnl_strjoin(const char *line_buff, const char *next_buff);
size_t	gnl_strlen(const char *s, int term);
char	*gnl_strchr(const char *s, int c);
char	*free_and_return(char **buff, char **buff2);
#endif