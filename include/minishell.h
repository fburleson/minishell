/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:47 by joel              #+#    #+#             */
/*   Updated: 2023/07/14 11:40:47 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>
# include "libft.h"

# define SUCCESS	0
# define ERROR		1

# define EXEC_FAILED_STATUS		126
# define CMD_NOT_FOUND_STATUS	127
# define NEW_PROMPT_STATUS		130

# define FALSE		0
# define TRUE		1

# define SHELL_PROMPT	"\e[1m\x1b[32mminishell$ \x1b[0m"

# define CMD_EXIT	"exit"
# define CMD_ECHO	"echo"
# define CMD_ENV	"env"
# define CMD_PWD	"pwd"
# define CMD_STATUS	"$?"

typedef DIR				t_dir;
typedef struct dirent	t_dirent;
typedef unsigned int	t_bool;
typedef unsigned int	t_status;
typedef pid_t			t_pid;

typedef struct s_cmd
{
	char	*line;
	char	*program;
	char	**raw_args;
	char	**args;
	char	*out;
}						t_cmd;

//	parse.c

char			**parse_line(char *line);

//	expander.c

char			**expand_args(char **arg, char **env, t_status status);

//	exec.c

t_status		exec_program(char *path, char **args, char **env);

//	builtin_exec.c

unsigned int	exec_builtin(char **args, char **env);

//	BUILTINS

t_status		cmd_env(char **env);
t_status		cmd_echo(char **args);
t_status		cmd_pwd(char **env);
t_status		cmd_exit(void);

//	UTILS

char			*env_var(char *var_name, char **env);
unsigned int	str_arr_len(char **str_arr);
void			free_str_arr(char **str_arr);
char			*get_abs_path(char *path, char **env);
t_bool			does_file_exist(char *file_name);
char			**copy_str_arr(char **str_arr);
t_bool			is_builtin(char *cmd);
#endif