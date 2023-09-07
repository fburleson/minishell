/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:52:42 by joel              #+#    #+#             */
/*   Updated: 2023/09/07 10:32:25 by joel             ###   ########.fr       */
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

static void	init_shell(t_shell *shell, char **env)
{
	shell->env = copy_strarray(env);
	shell->env_list = list_init(shell->env);
}

static void	clean_shell(t_shell *shell)
{
	free(shell->line);
	free_strarray(shell->args);
	free_cmds(shell->cmds);
}

static void	process_line(t_shell *shell)
{
	add_history(shell->line);
	shell->args = parse(shell->line, shell->env);
	shell->cmds = init_cmds(shell->args);
	init_redirection(shell->cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	printf("%i%s\n", argc, argv[0]);
	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	init_shell(&shell, env);
	if (!shell.env)
		return (ERROR);
	while (TRUE)
	{
		shell.line = readline(SHELL_PROMPT);
		if (!shell.line)
			cmd_exit();
		if (*shell.line == '\0' || ft_isempty(shell.line))
		{
			free(shell.line);
			continue ;
		}
		process_line(&shell);
		exec_pipe(shell.cmds, shell.env, shell.env_list);
		clean_shell(&shell);
	}
	free_strarray(shell.env);
	free_env_list(shell.env_list);
	return (SUCCESS);
}
