/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:24:57 by joel              #+#    #+#             */
/*   Updated: 2023/07/11 12:31:05 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		args = parse_line(line);
		args = expand_args(args, env);
		exec_builtin(args, env);
	}
	return (SUCCESS);
}
