/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:24 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/13 04:06:48 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_fork(char *path, char **input)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, input, msh_env);
	else if (pid < 0)
		ft_putendl("MSH Error during fork");
	wait(&pid);
	ft_strdel(&path);
	return (1);
}

int		msh_is_exec(char **input, char *path, struct stat stats)
{
	if (S_ISREG(stats.st_mode))
	{
		if (stats.st_mode & S_IXUSR)
			return (msh_fork(path, input));
		else
		{
			ft_putstr("MSH Error: permission denied: ");
			ft_putendl(path);
		}
		free(path);
		return (1);
	}
	free(path);
	return (1);
}

char	*msh_find_bin(char **input)
{
	int			i;
	char		**bin;
	char		*path;
	struct stat	stats;

	i = 0;
	bin = ft_strsplit(get_env("PATH"), ':');
	while (bin[i])
	{
		if (start_with(bin[i], input[0]))
			path = ft_strdup(input[0]);
		else
			path = ft_strjoin(bin[i], "/");
		path = ft_strjoin_free(path, input[0]);
		if (lstat(path, &stats) == -1)
			free(path);
		else
		{
			ft_free_array(bin);
			return (path);
		}
		i++;
	}
	ft_free_array(bin);
	return (NULL);
}

int		is_not_builtin(char **input, char *path, struct stat stats)
{
	if (path[0])
		return (msh_is_exec(input, path, stats));
	if (lstat(input[0], &stats) != -1)
	{
		if (S_ISREG(stats.st_mode))
			return (msh_is_exec(input, ft_strdup(input[0]), stats));
		else if (S_ISDIR(stats.st_mode))
			return (msh_cd(&input[0], 0));
	}
	return (1);
}

int		execute_input(char **input, char **env)
{
	int			i;
	char		*path;
	struct stat	stats;

	i = 0;
	if (input[0] == NULL)
		return (1);
	while (i < BUILTIN_NUM)
	{
		if (ft_strcmp(input[0], builtin_list(i)) == 0)
			return ((*builtinf(i))(input, env));
		i++;
	}
	if ((path = msh_find_bin(input)))
	{
		lstat(path, &stats);
		is_not_builtin(input, path, stats);
	}
	else
	{
		ft_putstr("MSH Error: this command does not exist: ");
		ft_putendl(input[0]);
	}
	return (1);
}
