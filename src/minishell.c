/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:24:57 by joel              #+#    #+#             */
/*   Updated: 2023/07/13 10:48:48 by joel             ###   ########.fr       */
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
		g_exit_status = NEW_PROMPT_STATUS;
	}
	if (signum == SIGQUIT)
		exit(SUCCESS);
}

int	main(int argc, char **argv, char **temp_env)
{
	char			*line;
	char			**raw_args;
	char			**args;
	char			**env;

	signal(SIGINT, &signalhandler);
	signal(SIGQUIT, &signalhandler);
	printf("%i%s\n", argc, argv[0]);
	env = copy_str_arr(temp_env);
	while (TRUE)
	{
		line = readline(SHELL_PROMPT);
		if (line == NULL)
			return (SUCCESS);
		if (ft_isempty(line))
			continue ;
		add_history(line);
		raw_args = parse_line(line);
		args = expand_args(raw_args, env, g_exit_status);
		if (!is_builtin(args[0]))
			g_exit_status = exec_program(args[0], args, env);
		else
			g_exit_status = exec_builtin(args, env);
		if (g_exit_status == CMD_NOT_FOUND_STATUS)
			printf("minishell:	command not found:	%s\n", args[0]);
		free_str_arr(raw_args);
		free_str_arr(args);
		free(line);
	}
	return (SUCCESS);
}
