/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:12:16 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/06 01:22:34 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		quote_check(char **input)
{
	int i;
	int j;
	int quote;

	i = 1;
	j = 0;
	quote = 0;
	while (input[i])
	{
		while (input[i][j])
			if (input[i][j++] == '"')
				quote++;
		j = 0;
		i++;
	}
	if (quote % 2 == 0)
		return (1);
	else
		return (-1);
}

int		echo_check(char **input)
{
	int i;
	int valid;
	int opt;

	i = 1;
	opt = 0;
	if (input[1][0] == '-' && input[1][1] == 'n' && input[2])
	{
		i++;
		opt = 2;
	}
	while (input[i])
	{
		valid = quote_check(input);
		if (valid == -1)
			return (-1);
		i++;
	}
	if (valid >= 1)
	{
		opt++;
		return (opt);
	}
	return (opt);
}

void	print_part(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
			i++;
		else
		{
			ft_putchar(input[i]);
			i++;
		}
	}
}

int		msh_echo(char **input, char **env)
{
	int check;
	int i;

	check = echo_check(input);
	i = 1;
	if (check == -1)
	{
		ft_putendl("MSH Error: echo: invalid input: missing quote");
		return (1);
	}
	if (check == 2 || check == 3)
		i++;
	while (input[i])
	{
		print_part(input[i]);
		i++;
		input[i] ? ft_putchar(' ') : ft_putchar('\n');
	}
	(void)env;
	return (1);
}
