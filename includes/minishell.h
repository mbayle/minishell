/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:36:47 by mabayle           #+#    #+#             */
/*   Updated: 2019/03/22 17:29:28 by mabayle          ###   ########.fr       */
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

#endif
