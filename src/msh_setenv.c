/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:35:06 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/22 06:45:23 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_env_var(char *key, char *value)
{
	int		i;
	int		len;
	char	*tmp_key;
	char	*new_var;
	char	**new_env;

	i = 0;
	len = ft_tablen(g_msh_env) + 1;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env[len--] = 0;
	while (g_msh_env[i])
	{
		new_env[i] = ft_strdup(g_msh_env[i]);
		free(g_msh_env[i]);
		i++;
	}
	free(g_msh_env);
	tmp_key = ft_strjoin(key, "=");
	new_var = ft_strjoin(tmp_key, value);
	new_env[i] = ft_strdup(new_var);
	free(tmp_key);
	free(new_var);
	g_msh_env = new_env;
}

int		set_env_var(char *key, char *value)
{
	int		exist_index;
	char	*tmp_key;
	char	*str_add;

	exist_index = already_exist_index(key);
	if (exist_index != -1)
	{
		tmp_key = ft_strjoin(key, "=");
		str_add = ft_strjoin(tmp_key, value);
		free(tmp_key);
		free(g_msh_env[exist_index]);
		g_msh_env[exist_index] = ft_strdup(str_add);
		free(str_add);
		return (1);
	}
	if (exist_index == -1)
		create_env_var(key, value);
	return (1);
}

int		msh_setenv(char **input, char **env)
{
	if (!input[1])
	{
		ft_putendl("MSH error: setenv/unsetenv: too few arguments");
		return (1);
	}
	if (input[1] && input[2] && input[3])
	{
		ft_putendl("MSH error: setenv/unsetenv: too much arguments");
		return (1);
	}
	if (!input[2])
		return (set_env_var(input[1], ""));
	if (input[2])
		return (set_env_var(input[1], input[2]));
	(void)env;
	return (1);
}
