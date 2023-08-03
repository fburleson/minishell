/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:24:57 by joel              #+#    #+#             */
/*   Updated: 2023/08/03 20:22:20 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	g_exit_status = 0;

static void	free_cmd(t_cmd *cmd)
{
	free(cmd->line);
	free_str_arr(cmd->raw_args);
	free_str_arr(cmd->args);
}

static void	exec_cmd(t_cmd *cmd, char **env)
{	
	setup_redirect_out(cmd);
	setup_redirect_in(cmd);
	if (!is_builtin(cmd->program))
		g_exit_status = exec_program(cmd->program, cmd->args, env);
	else
		g_exit_status = exec_builtin(cmd->args, env);
	reset_redirection(cmd);
}

void	signalhandler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = NEW_PROMPT_STATUS;
	}
	if (signum == SIGQUIT)
		exit(SUCCESS);
}

int	main(int argc, char **argv, char **temp_env)
{
	t_cmd			cmd;
	char			**env;

	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	printf("%i%s\n", argc, argv[0]);
	cmd.fd_redout = -1;
	cmd.fd_stdout = -1;
	cmd.fd_redin = -1;
	cmd.fd_stdin = -1;
	env = copy_str_arr(temp_env);
	while (TRUE)
	{
		cmd.line = readline(SHELL_PROMPT);
		if (cmd.line == NULL)
			return (ERROR);
		if (ft_isempty(cmd.line))
		{	
			free(cmd.line);
			continue ;
		}
		cmd.raw_args = parse_line(cmd.line);
		cmd.args = expand_args(cmd.raw_args, env, g_exit_status);
		cmd.program = cmd.args[0];
		cmd.output_files = parse_redirection(cmd.line, OUTRED_SYM);
		cmd.input_files = parse_redirection(cmd.line, INRED_SYM);
		exec_cmd(&cmd, env);
		if (g_exit_status == CMD_NOT_FOUND_STATUS)
			printf("minishell:	command not found:	%s\n", cmd.program);
		add_history(cmd.line);
		free_cmd(&cmd);
	}
	return (SUCCESS);
}
