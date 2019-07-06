/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:52:30 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/06 01:39:05 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_cd(char **input, char **env)
{
	char actual_pwd[PATH_MAX + 1];

	getcwd(actual_pwd, sizeof(actual_pwd));
	if (input[1] == NULL)
		ft_putendl("msh: expected argument to \"cd\"");
	else if (chdir(input[1]) != 0)
	{
		ft_putstr("Msh error: cd: no such file or directory ");
		ft_putstr("or permission denied: ");
		ft_putendl(input[1]);
		return (1);
	}
	set_env_var("OLDPWD", actual_pwd);
	getcwd(actual_pwd, sizeof(actual_pwd));
	set_env_var("PWD", actual_pwd);
	(void)env;
	return (1);
}
