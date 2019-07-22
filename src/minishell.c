/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 04:26:55 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/22 09:07:46 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **environ)
{
	int		len;
	int		i;

	len = ft_tablen(environ);
	i = 0;
	if (environ && len > 1)
	{
		g_msh_env = (char **)malloc(sizeof(char *) * (len + 1));
		g_msh_env[len--] = NULL;
		while (i <= len)
		{
			g_msh_env[i] = ft_strdup(environ[i]);
			i++;
		}
	}
	else
	{
		g_msh_env = ft_memalloc(sizeof(char **));
		g_msh_env[0] = NULL;
	}
}

char	*print_prompt(char *line)
{
	char	actual_dir[256];
	int		len;

	ft_putstr("\033[0;36mMinishell - \033[0;37m");
	if (getcwd(actual_dir, sizeof(actual_dir)) != NULL)
	{
		len = ft_strlen(actual_dir);
		if (len == 1)
			ft_putstr("\033[1;30m/");
		if ((ft_strcmp(actual_dir, "/")) || len != 1)
		{
			while (actual_dir[len] != '/')
				len--;
		}
		ft_putstr("\033[1;30m");
		while (actual_dir[++len] != '\0')
			ft_putchar(actual_dir[len]);
		ft_putstr("\033[0;37m > ");
	}
	get_next_line(0, &line);
	return (line);
}

int		msh_read(void)
{
	char		*line;
	char		**input;
	extern char	**environ;
	int			status;

	line = NULL;
	input = NULL;
	status = 1;
	init_env(environ);
	while (status)
	{
		line = print_prompt(line);
		if (line)
		{
			input = ft_split_whitespaces(line);
			msh_expand(input);
			status = execute_input(input, g_msh_env);
			ft_free_array(input);
		}
		else
			ft_putchar('\n');
		free(line);
	}
	ft_free_array(g_msh_env);
	return (status);
}
