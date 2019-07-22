/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:00:28 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/22 06:58:57 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*builtin_list(int i)
{
	char	*builtin[BUILTIN_NUM + 1];

	builtin[0] = "cd";
	builtin[1] = "help";
	builtin[2] = "exit";
	builtin[3] = "env";
	builtin[4] = "setenv";
	builtin[5] = "unsetenv";
	builtin[6] = "pwd";
	builtin[7] = "echo";
	builtin[8] = NULL;
	return (builtin[i]);
}

int		(*g_builtinf(int i))(char **input, char **env)
{
	int (*g_builtinf[BUILTIN_NUM])(char **input, char **env);

	g_builtinf[0] = &msh_cd;
	g_builtinf[1] = &msh_help;
	g_builtinf[2] = &msh_exit;
	g_builtinf[3] = &msh_env_print;
	g_builtinf[4] = &msh_setenv;
	g_builtinf[5] = &msh_unsetenv;
	g_builtinf[6] = &msh_pwd;
	g_builtinf[7] = &msh_echo;
	return (g_builtinf[i]);
}
