/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:36:47 by mabayle           #+#    #+#             */
/*   Updated: 2019/07/20 22:58:25 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h> 	// Include for malloc, free, exit
#include <unistd.h>		// Include for access, read, getcwd, chdir, fork, execve
#include <fcntl.h>		// Include for open, close
#include <sys/uio.h>	// Include for read
#include <sys/types.h>	// Include for read
#include <dirent.h>		// Include for open, readdir, closedir
#include <sys/stat.h>	// Include for stat, fstat, lstat
#include <sys/wait.h>	// Include for wait, wait3, wait4, waitpid
#include <signal.h>		// Include for signal, kill
#include "../libft/includes/libft.h"

#include <stdio.h>      // A SUPPRIMER

#define BUILTIN_NUM (8)
#define MINI_PATH "/usr/bin:/bin:/usr/sbin"

char		**msh_env;

// MAIN
int			main(void);

// MINISHELL.c
int 		msh_read(void);
int			print_prompt(void);
void		init_env(char **environ);

// MSH_EXPAND.C
int			is_special(char c);
void		msh_expand(char **input);
char		*replace(char *input, char *cmd, int i);
char		*value_env(char *input, int i);

// GESTION.C
int         execute_input(char **input, char **env);
char		*msh_find_bin(char **input);
int			msh_is_exec(char **input, char *path, struct stat stats);
int			is_not_builtin(char **input);
int			msh_fork(char *path, char **input);

// MSH_ENV.C
int			msh_env_print(char **input, char **env);

// MSH_ENV_UTILS.C
int			start_with(char *chr_search, char *str);
char		*get_env(char *env_var);
int			already_exist_index(char *key);

//MSH_BUILTINS_ENV.C
char		*builtin_list(int i);
int         (*builtinf(int i))(char **input, char **env);

// MSH_SETENV.C
void		create_env_var(char *key, char *value);
int			set_env_var(char *key, char *value);
int			msh_setenv(char **input, char **env);

// MSH_UNSETENV.C
int			unset_env_var(char *key);
int			msh_unsetenv(char **input, char **env);

// MSH_ECHO.C
int			quote_check(char **input);
int			echo_check(char **input);
void		print_part(char *input);
int			msh_echo(char **input, char **env);

// MSH_CD.C
int			msh_cd(char **input, char **env);

// MSH_HELP.C
int			msh_help(char **input, char **env);

// MSH_EXIT.C
int			msh_exit(char **input, char **env);

// MSH_PWD.C
int			msh_pwd(char **input, char **env);

#endif
