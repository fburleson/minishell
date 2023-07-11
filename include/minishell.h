/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:47 by joel              #+#    #+#             */
/*   Updated: 2023/07/11 12:25:46 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <signal.h>
# include <termios.h> 

# define SUCCESS	0
# define ERROR		1

# define ERR_CMD_NOT_FOUND	127

# define FALSE		0
# define TRUE		1

# define SHELL_PROMPT	"\e[1m\x1b[32mminishell$ \x1b[0m"

# define CMD_EXIT	"exit"
# define CMD_ECHO	"echo"
# define CMD_ENV	"env"
# define CMD_PWD	"pwd"
# define CMD_STATUS	"$?"

typedef unsigned int	t_bool;

//	parse.c

char			**parse_line(char *line);

//	expander.c

char			**expand_args(char **arg, char **env);

//	builtin_exec.c

unsigned int	exec_builtin(char **args, char **env);


//	BUILTINS

unsigned int	cmd_env(char **env);
unsigned int	cmd_echo(char **args);
unsigned int	cmd_pwd(char **env);
unsigned int	cmd_exit(void);

//	UTILS

char			*env_var(char *var_name, char **env);
char			**copy_str_arr(char **str_arr);
#endif