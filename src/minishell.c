/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsarkoh <fsarkoh@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:52:42 by joel          #+#    #+#                 */
/*   Updated: 2023/08/24 15:15:22 by kaltevog      ########   odam.nl         */
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
	t_envs	*env_list;

	printf("%i%s\n", argc, argv[0]);
	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	env = copy_strarray(temp_env);
	env_list = list_init(env);
	if (!env)
		return (ERROR);
	while (TRUE)
	{
		line = readline(SHELL_PROMPT);
		if (line == NULL)
			printf("exit"); //deze 2 zijn voor CTRL D
		if (line == NULL) // deze 2 zijn voor CTRL D
			exit(SUCCESS);
		if (*line == '\0' || ft_isempty(line))
		{
			free(line);
			continue ;
		}
		else if (!line)
			return (ERROR);
		add_history(line);
		args = parse(line, env);
		cmds = init_cmds(args);
		exec_cmd(cmds[0], env, env_list);
		if (g_exit_status == STATUS_CMD_NOT_FOUND)
			printf("minishell:	command not found:	%s\n", cmds[0]->args[0]);
		free(line);
		free_strarray(args);
		free_cmds(cmds);
	}
	free_strarray(env);
	free_env_list(env_list);
	return (SUCCESS);
}
