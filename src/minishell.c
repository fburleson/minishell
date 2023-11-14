/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:52:42 by joel              #+#    #+#             */
/*   Updated: 2023/11/14 15:45:06 by joel             ###   ########.fr       */
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
	else if (signum == SIGQUIT)
		exit(SUCCESS);
}

static void	init_shell(t_shell *shell, char **env)
{
	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, SIG_IGN);
	shell->env = copy_strarray(env);
}

static void	process_line(t_shell *shell)
{
	add_history(shell->line);
	shell->args = parse(shell->line, shell->env);
	shell->cmds = init_cmds(shell->args);
	init_redirection(shell->cmds);
}

static void	loop_helper(t_shell *shell)
{
	if (g_exit_status != STATUS_NEW_PROMPT)
	{
		shell->line = readline(SHELL_PROMPT);
		if (!shell->line)
			exit(ERROR);
		if (*shell->line == '\0' || ft_isempty(shell->line))
		{
			free(shell->line);
			return ;
		}
	}
	else
	{
		g_exit_status = 0;
	}
	process_line(shell);
	exec_pipe(shell->cmds, &(shell->env));
	free_shell(shell);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (argc > 1)
		printf("%s doesn't require any arguments\n", argv[0]);
	init_shell(&shell, env);
	if (!shell.env)
		return (ERROR);
	while (TRUE)
		loop_helper(&shell);
	free_strarray(shell.env);
	return (SUCCESS);
}
