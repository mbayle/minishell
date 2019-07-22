/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:29:17 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/22 06:45:23 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		start_with(char *chr_search, char *str)
{
	int i;

	i = 0;
	while (chr_search[i] && str[i] && (chr_search[i] == str[i]))
		i++;
	return (chr_search[i] == '\0' ? 1 : 0);
}

char	*get_env(char *env_var)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(env_var, "=");
	while (g_msh_env[i])
	{
		if (start_with(tmp, g_msh_env[i]))
		{
			free(tmp);
			return (ft_strchr(g_msh_env[i], '=') + 1);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

int		already_exist_index(char *key)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(key, "=");
	while (g_msh_env[i])
	{
		if (start_with(tmp, g_msh_env[i]))
		{
			free(tmp);
			return (i);
		}
		i++;
	}
	free(tmp);
	return (-1);
}
