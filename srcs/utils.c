/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnhat <minhnhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:39:08 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/04/02 00:31:52 by minhnhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipex_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("Pipe error\n");
		exit(1);
	}
}

static void handle_execve_error(int error_code)
{
	perror("execve failed");
	if (error_code == EACCES)
		exit(126);
	exit(127);
}

static void check_path_variable(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return;
		}
		i++;
	}
	write(2, "pipex: PATH variable not found\n", 31);
	exit(127);
}

static void handle_command_not_found(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, args[i], ft_strlen(args[i]));
		write(2, "\n", 1);
		i++;
	}
	exit(127);
}

void pipex_execute(char **envp, char *cmd)
{
	char **args;
	char *cmd_path;

	args = ft_split(cmd, ' ');
	if (args == NULL || args[0] == NULL)
	{
		write(2, "pipex: command not found\n", 25);
		exit(127);
	}
	if (ft_strchr(args[0], '/') != NULL)
	{
		execve(args[0], args, envp);
		handle_execve_error(errno);
	}
	check_path_variable(envp);
	cmd_path = get_valid_cmd(args[0], envp);
	if (cmd_path == NULL)
		handle_command_not_found(args);
	execve(cmd_path, args, envp);
	handle_execve_error(errno);
	free(cmd_path);
	ft_free_arr_2d(args);
}
