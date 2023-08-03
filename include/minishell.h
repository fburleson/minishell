/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:47 by joel              #+#    #+#             */
/*   Updated: 2023/08/03 20:51:25 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
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

# define FALSE		0
# define TRUE		1

# define EXEC_FAILED_STATUS		126
# define CMD_NOT_FOUND_STATUS	127
# define NEW_PROMPT_STATUS		130

# define SHELL_PROMPT	"\e[1m\x1b[32mminishell$ \x1b[0m"

# define CMD_EXIT	"exit"
# define CMD_ECHO	"echo"
# define CMD_ENV	"env"
# define CMD_PWD	"pwd"
# define CMD_STATUS	"$?"

# define INRED_SYM	'<'
# define OUTRED_SYM	'>'

# define OUTPUT_MODE	0
# define INPUT_MODE		1
# define APPEND_MODE 	2
# define HEREDOC_MDOE	3
# define INVALID_MODE	4

typedef DIR				t_dir;
typedef struct stat		t_fstats;
typedef struct dirent	t_dirent;
typedef unsigned int	t_bool;
typedef unsigned int	t_status;
typedef pid_t			t_pid;

typedef struct redir_file
{
	char			*file_path;
	unsigned int	mode;
}						t_redir_file;

typedef struct s_cmd
{
	char			*line;
	char			*program;
	char			**raw_args;
	char			**args;
	t_redir_file	**output_files;
	t_redir_file	**input_files;
	int				fd_stdout;
	int				fd_redout;
	int				fd_stdin;
	int				fd_redin;
	char			*delimiter;
}						t_cmd;

//	parse.c

char			**parse_line(char *line);

//	EXPANDER (expander.c, expander_str.c)

char			**expand_args(char **arg, char **env, t_status status);
char			*expand_str(char *str, char **env);

//	parse_redirection.c

t_redir_file	**parse_redirection(char *line, char symbol);

//	setup_redirection.c

void			setup_redirect_out(t_cmd *cmd);
void			setup_redirect_in(t_cmd *cmd);
void			reset_redirection(t_cmd *cmd);

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
char			**copy_str_arr(char **str_arr);
t_bool			is_builtin(char *cmd);
#endif