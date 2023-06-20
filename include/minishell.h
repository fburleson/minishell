/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:47 by joel              #+#    #+#             */
/*   Updated: 2023/06/20 20:14:11 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define SUCCESS	0
# define ERROR		1

# define FALSE		0
# define TRUE		1

# define SHELL_PROMPT	"\e[1m\x1b[32mminishell$ \x1b[0m"

typedef unsigned int	t_bool;

//	parse.c

char			**parse_line(char *line);

//	expander.c

char			*expand(char *arg, char **env);

//	BUILTINS

// env.c

unsigned int	cmd_env(char **env);
unsigned int	cmd_echo(char **args);
#endif