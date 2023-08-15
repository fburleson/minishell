/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:52:42 by joel              #+#    #+#             */
/*   Updated: 2023/08/12 15:16:14 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	g_exit_status = 0;

void	signalhandler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = STATUS_NEW_PROMPT;
	}
	if (signum == SIGQUIT)
		exit(SUCCESS);
}

int	main(int argc, char **argv, char **temp_env)
{
	char	*line;
	char	**args;
	char	**env;
	t_cmd	**cmds;

	printf("%i%s\n", argc, argv[0]);
	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	env = copy_strarray(temp_env);
	if (!env)
		return (ERROR);
	while (TRUE)
	{
		line = readline(SHELL_PROMPT);
		if (!line)
			return (ERROR);
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		args = parse(line, env);
		cmds = init_cmds(args);
		exec_cmd(cmds[0], env);
		if (g_exit_status == STATUS_CMD_NOT_FOUND)
			printf("minishell:	command not found:	%s\n", cmds[0]->args[0]);
		free(line);
		free_strarray(args);
		free_cmds(cmds);
	}
	free_strarray(env);
	return (SUCCESS);
}
