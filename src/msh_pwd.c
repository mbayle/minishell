/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 01:13:46 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/04 01:15:45 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_pwd(char **input, char **env)
{
	char actual_dir[PATH_MAX + 1];

	if (getcwd(actual_dir, sizeof(actual_dir)) != NULL)
		ft_putendl(actual_dir);
	else
		ft_putendl("Msh error: pwd: error");
	(void)input;
	(void)env;
	return (1);
}
