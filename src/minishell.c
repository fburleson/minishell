/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:52:42 by joel              #+#    #+#             */
/*   Updated: 2023/11/29 22:00:19 by joel             ###   ########.fr       */
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
	char	**temp_env;
	char	*prev_shlvl;
	char	*shlvl;
	char	*shlvl_value;

	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, SIG_IGN);
	prev_shlvl = envvar("SHLVL", env);
	temp_env = cp_remove(env, "SHLVL");
	shlvl_value = ft_itoa(ft_atoi(prev_shlvl) + 1);
	shlvl = ft_strjoin("SHLVL=", shlvl_value);
	shell->env = cp_append(temp_env, shlvl);
	free(shlvl);
	free(prev_shlvl);
	free(shlvl_value);
	free_strarray(temp_env);
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
			cmd_exit(NULL);
		if (shell->line[0] == '\0' || ft_isempty(shell->line))
		{
			free(shell->line);
			return ;
		}
	}
	else
		g_exit_status = 0;
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
