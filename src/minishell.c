/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:24:57 by joel              #+#    #+#             */
/*   Updated: 2023/06/20 19:55:17 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_args(char **args, char **env)
{
	char			*temp;
	unsigned int	cidx;

	cidx = 0;
	while (args[cidx])
	{
		if (args[cidx][0] == '$'
			|| (args[cidx][0] == '\"' && args[cidx][1] == '$'))
		{
			temp = expand(args[cidx], env);
			free(args[cidx]);
			args[cidx] = temp;
		}
		cidx++;
	}
}

int	main(int argc, char **argv, char **env)
{
	char			*line;
	char			**args;
	unsigned int	status;

	printf("%i%s%s\n", argc, argv[0], env[0]);
	while (TRUE)
	{
		line = readline(SHELL_PROMPT);
		if (ft_isempty(line))
			continue ;
		add_history(line);
		args = parse_line(line);
		expand_args(args, env);
		if (!ft_strncmp(args[0], "exit", ft_strlen(args[0])))
			return (SUCCESS);
		else if (!ft_strncmp(args[0], "env", ft_strlen(args[0])))
			status = cmd_env(env);
		else if (!ft_strncmp(args[0], "$?", ft_strlen(args[0])))
			printf("%u\n", status);
		else if (!ft_strncmp(args[0], "echo", ft_strlen(args[0])))
			status = cmd_echo(args);
	}
	return (SUCCESS);
}
