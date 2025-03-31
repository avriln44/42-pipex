/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:39:22 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 16:20:53 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"

int		open_file(char *file, int is_input);
char	*build_valid_cmd(char *path, char *cmd_part);
char	*get_valid_cmd(char *cmd, char **envp);
char	*handle_absolute_path(char **check);
void	pipex_execute(char **envp, char *cmd);
void	first_cmd(char **argv, char **envp, int *fd);
void	second_cmd(char **argv, char **envp, int *fd);
void	execute(char **argv, char **envp, int *fd);
void	pipex_pipe(int *fd);
char	**get_cmd_arr(char **envp);

#endif