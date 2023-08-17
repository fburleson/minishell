/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:50:19 by joel          #+#    #+#                 */
/*   Updated: 2023/08/17 16:04:04 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define SHELL_PROMPT	"\e[1m\x1b[32mminishell$ \x1b[0m"

# define CMD_EXIT	"exit"
# define CMD_ECHO	"echo"
# define CMD_ENV	"env"
# define CMD_PWD	"pwd"
# define CMD_CD		"cd"
# define CMD_EXPORT	"export"
# define CMD_UNSET	"unset"

# define SUCCESS	0
# define ERROR		1

# define FALSE		0
# define TRUE		1

# define STATUS_CMD_NOT_FOUND	127
# define STATUS_NEW_PROMPT		130

# define OUTPUT_MODE	0
# define INPUT_MODE		1
# define APPEND_MODE 	2
# define HEREDOC_MODE	3

typedef DIR				t_dir;
typedef struct stat		t_fstats;
typedef struct dirent	t_dirent;
typedef unsigned int	t_bool;
typedef unsigned int	t_status;
typedef pid_t			t_pid;
typedef unsigned int	t_iomode;

typedef struct iofile
{
	char		*path;
	t_iomode	mode;
	char		*limit_str;
}						t_iofile;

typedef struct cmd
{
	char		**args;
	t_iofile	**outfiles;
	t_iofile	*infile;
	int			fstdout;
	int			fredirectout;
	int			fstdin;
	int			fredirectin;
}						t_cmd;

typedef struct s_envs
{
	char			*start;
	char			*end;
	char			*fullstr;
	struct s_envs	*next;
}	t_envs;

//	PARSE

char			**parse(char *line, char **env);
char			*parse_arg(char *line, char *delimiters, char **env);
char			*expand_copy_arg(char *line, char *delimiters, char **env);

//	PARSE UTILS

char			*get_delimiters(char c);
char			*envvar_name(char *line);

//	INIT CMD

char			**cmd_args(char **args);
t_cmd			**init_cmds(char **args);
t_cmd			*init_cmd(char **args);

//	CMD UTILS

void			free_cmd(t_cmd *cmd);
void			free_cmds(t_cmd **cmds);

// INIT REDIRECTION

t_iofile		**init_outfiles(char **args);
t_iofile		*init_infile(char **args);
t_iofile		*init_iofile(char **args);

//	REDIRECTION UTILS

void			free_iofile(t_iofile *iofile);

//	REDIRECTION

void			setup_redirect_out(t_cmd *cmd);
void			setup_redirect_in(t_cmd *cmd);
void			reset_redirection(t_cmd *cmd);
int				create_heredoc(t_iofile *file);

//	BUILTINS

t_status		cmd_env(char **env);
t_status		cmd_echo(char **args);
t_status		cmd_pwd(char **env);
t_status		cmd_cd(char **argv, char **env);
t_status		cmd_export(char **args, char **env, t_envs *env_list);
t_envs			*list_init(char **env);
void			free_env_list(t_envs *list);
t_status		cmd_unset(char **args, t_envs *env_list);
t_status		cmd_exit(void);
// EXECUTION

void			exec_cmd(t_cmd *cmd, char **env, t_envs *env_list);

t_status		exec_program(char **args, char **env);
t_status		exec_builtin(char **args, char **env, t_envs *env_list);
// EXECUTION UTILS

char			*get_abs_path(char *path, char **env);
t_bool			is_builtin(char *cmd);

//	UTILS

unsigned int	lstrlen(char *str, char *delimiters, unsigned int threshold);
char			**copy_strarray(char **array);
unsigned int	strarraylen(char **array);
void			free_strarray(char **array);
void			print_strarray(char **array);
char			*envvar(char *name, char **env);
t_bool			cmpstr(char *str0, char *str1);
char			*excludechars(char *exclude);
#endif