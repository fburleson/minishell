/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joel <joel@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 22:24:57 by joel          #+#    #+#                 */
/*   Updated: 2023/07/10 19:18:07 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_cmd(char *arg, char *cmd)
{
	return (!ft_strncmp(arg, cmd, ft_max(ft_strlen(arg), ft_strlen(cmd))));
}

void	signalhandler(int signum)
{
	if (signum == SIGINT)
		printf(SHELL_PROMPT);
	if (signum == SIGQUIT)
	{
		printf("exit");
		exit(SUCCESS);
	}
}

int	main(int argc, char **argv, char **temp_env)
{
	char			*line;
	char			**args;
	char			**env;
	unsigned int	status;

	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	printf("%i%s\n", argc, argv[0]);
	env = copy_str_arr(temp_env);
	while (TRUE)
	{
		line = readline(SHELL_PROMPT);
		if (line == NULL)
		{
			printf("exit");
			exit(SUCCESS);
		}
		if (ft_isempty(line))
			continue ;
		add_history(line);
		args = parse_line(line);
		args = expand_args(args, env);
		if (is_cmd(args[0], CMD_EXIT))
			return (cmd_exit());
		else if (is_cmd(args[0], CMD_ENV))
			status = cmd_env(env);
		else if (is_cmd(args[0], CMD_ECHO))
			status = cmd_echo(args);
		else if (is_cmd(args[0], CMD_PWD))
			status = cmd_pwd(env);
		else if (is_cmd(args[0], CMD_STATUS))
			printf("%u\n", status);
		else
			printf("command not found:	%s\n", args[0]);
	}
	return (SUCCESS);
}
//test kaay