/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:53:09 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/09 18:45:36 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env_var(char *key)
{
	int		i;
	int		j;
	int		len;
	char	*tmp_key;
	char	**new_env;

	i = 0;
	j = 0;
	len = ft_tablen(msh_env) - 1;
	tmp_key = ft_strjoin(key, "=");
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env[len] = 0;
	while (i < len && msh_env[j])
	{
		if (!start_with(tmp_key, msh_env[j]))
		{
			new_env[i] = ft_strdup(msh_env[j]);
			i++;
		}
		j++;
	}
	free(tmp_key);
	ft_free_array(msh_env);
	msh_env = new_env;
	return (1);
}

int	msh_unsetenv(char **input, char **env)
{
	(void)env;
	if (!input[1])
		ft_putendl("unsetenv: too few arguments\n");
	else if (input[1] && input[2])
		ft_putendl("unsetenv: too many arguments\n");
	else if (get_env(input[1]) == NULL)
		ft_putendl("unsetenv: variable not found");
	else
		return (unset_env_var(input[1]));
	return (1);
}
