/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:56:18 by joel              #+#    #+#             */
/*   Updated: 2023/07/16 11:23:06 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	get_var_name_len(char *str)
{
	unsigned int	cidx;

	cidx = 1;
	while (str[cidx] && ft_isalnum(str[cidx]))
		cidx++;
	return (cidx - 1);
}

static char	*get_var_name(char *str)
{
	char			*name;
	unsigned int	str_idx;
	unsigned int	name_idx;

	name = (char *)malloc((get_var_name_len(str) + 1) * sizeof(char));
	if (!name)
		return (NULL);
	str_idx = 1;
	name_idx = 0;
	while (str[str_idx] && ft_isalnum(str[str_idx]))
	{
		name[name_idx] = str[str_idx];
		name_idx++;
		str_idx++;
	}
	name[name_idx] = '\0';
	return (name);
}

static unsigned int	expanded_str_len(char *str, char **env)
{
	unsigned int	len;
	char			*var_name;
	char			*var_value;
	unsigned int	cidx;

	len = 0;
	cidx = 0;
	while (str[cidx])
	{
		if (str[cidx] == '$')
		{
			var_name = get_var_name(str + cidx);
			var_value = env_var(var_name, env);
			len += ft_strlen(var_value);
			free(var_name);
			free(var_value);
			cidx++;
			while (str[cidx] && ft_isalnum(str[cidx]))
				cidx++;
			continue ;
		}
		len++;
		cidx++;
	}
	return (len);
}

static unsigned int	insert_env_var(char	*dest, char *start_var, char **env)
{
	char			*var_name;
	char			*var_value;
	unsigned int	len;

	var_name = get_var_name(start_var);
	var_value = env_var(var_name, env);
	len = ft_strlen(var_value);
	ft_strlcpy(dest, var_value, len + 1);
	free(var_name);
	free(var_value);
	return (len);
}

char	*expand_str(char *str, char **env)
{
	char			*expanded;
	unsigned int	exp_idx;
	unsigned int	str_idx;

	expanded = (char *)malloc((expanded_str_len(str, env) + 1) * sizeof(char));
	if (!expanded)
		return (NULL);
	exp_idx = 0;
	str_idx = 0;
	while (str[str_idx])
	{
		if (str[str_idx] == '$')
		{
			exp_idx += insert_env_var(expanded + exp_idx, str + str_idx, env);
			str_idx++;
			while (str[str_idx] && ft_isalnum(str[str_idx]))
				str_idx++;
			continue ;
		}
		expanded[exp_idx] = str[str_idx];
		str_idx++;
		exp_idx++;
	}
	expanded[exp_idx] = '\0';
	return (expanded);
}
