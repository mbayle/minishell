/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 04:26:55 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/20 22:58:01 by mabayle          ###   ########.fr       */
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
		msh_env = (char **)malloc(sizeof(char *) * (len + 1));
		msh_env[len--] = NULL;
		while (i <= len)
		{
			msh_env[i] = ft_strdup(environ[i]);
			i++;
		}
	}
	else
	{
		msh_env = ft_memalloc(sizeof(char **));
		msh_env[0] = NULL;
	}
}

int		print_prompt(void)
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
	return (1);
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
		print_prompt();
		get_next_line(0, &line);
		if (line)
		{
			input = ft_split_whitespaces(line);
			msh_expand(input);
			status = execute_input(input, msh_env);
			ft_free_array(input);
		}
		else
			ft_putchar('\n');
		free(line);
	}
	ft_free_array(msh_env);
	return (status);
}
