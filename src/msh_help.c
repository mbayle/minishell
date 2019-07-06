/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:57:55 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/04 05:03:24 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_help(char **input, char **env)
{
	ft_putstr(" _   _                   _                              __   ");
	ft_putendl("__   	____  _   _ ");
	ft_putstr("| | | | _____      __   | |_ ___      _   _ ___  ___    |  ");
	ft_putendl("\\/  	/ ___|| | | |");
	ft_putstr("| |_| |/ _ \\ \\ /\\ / /   | __/ _ \\    | | | / __|/ _ \\");
	ft_putendl(")   |   	|\\/| \\___ \\| |_| |");
	ft_putstr("|  _  | (_) \\ V  V /    | || (_) |   | |_| \\__ \\  __/   ");
	ft_putendl("| |  	| |___) |  _  |");
	ft_putstr("|_| |_|\\___/ \\_/\\_/      \\__\\___/     \\__,_|___/\\___");
	ft_putendl("| 	|_|  |_|____/|_| |_|");
	ft_putendl("\nAvailable in MSH");
	ft_putendl("- echo");
	ft_putendl("- cd");
	ft_putendl("- env | setenv | unsetenv");
	ft_putendl("- pwd");
	ft_putendl("- exit");
	ft_putchar('\n');
	(void)input;
	(void)env;
	return (1);
}
