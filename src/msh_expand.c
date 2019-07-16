/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:21:42 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/16 05:43:03 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char	*replace_norme(char *input, int i)
{
	char	*new;

	new = NULL;

	return(new);
}*/

int		is_special(char c)
{
	if (c == '$' || c == ':')
		return (1);
	else
		return (0);
}

char	*value_env(char *input, int i)
{
	char	*new;

	new = ft_strdup("");
	while (input[i] && !ft_isspace(input[i]) && input[i] != '$' &&
			input[i] != ':')
		new = ft_strjoin_onef(new, input[i++]);
	return (new);
}

char	*replace(char *input, char *cmd, int i)
{
	char	*var;
	char	*new;

	new = ft_strdup("");
	while (input[i])
	{
		if (input[i] == '$' && ft_strlen(input) > 1)
		{
			//replace_norme(input, i);
			var = value_env(input, i++ + 1);
			new = ft_strjoin_free(new, ((get_env(var)) ? get_env(var) : "\0"));
			free(var);
			while (input[i] && !ft_isspace(input[i]) && !is_special(input[i]))
				i++;
		}
		else if ((i == 0 || (i != 0 && ft_isspace(input[i - 1])))
			&& input[i] == '~' && input[i + 1] != '$')
		{
			if (input[i] == '~')
				new = ft_strjoin_free(new, get_env("HOME"));
			i++;
		}
		else if (input[i] == '-' && ft_strcmp(cmd, "cd") == 0)
		{
			new = ft_strjoin_free(new, get_env("OLDPWD"));
			i++;
		}
		else
			new = ft_strjoin_onef(new, input[i++]);
	}
	free(input);
	return (new);
}

void	msh_expand(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_strchr(input[i], '$') != NULL || ft_strchr(input[i], '~') != NULL
				|| ft_strchr(input[i], '-') != NULL)
			input[i] = replace(input[i], input[0], 0);
		i++;
	}
}
