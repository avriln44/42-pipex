/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:39:08 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 17:06:48 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("Pipe error\n");
		exit(1);
	}
}

void	pipex_execute(char **envp, char *cmd)
{
	char	*cmd_path;
	char	**args;

	if (!cmd || cmd[0] == '\0' || !envp || !*envp)
	{
		write(2, "Invalid command\n", 16);
		exit(127);
	}
	args = ft_split(cmd, ' ');
	if (!args)
	{
		write(2, "pipex: Command not found\n", 26);
		write(2, cmd, ft_strlen(cmd));
		exit(127);
	}
	// if (ft_strchr(cmd, '/' || ft_strchr(cmd, '.')))
	// {
	// 	cmd_path = handle_absolute_path(args);
	// 	ft_printf("cmd_path: %s\n", cmd_path);
	// 	if (!cmd_path)
	// 	{
	// 		write(2, "No such file or directory\n", 27);
	// 		write(2, cmd, ft_strlen(cmd));
	// 		ft_free_arr_2d(args);
	// 		exit(126);
	// 	}
	// }
	else
	{
		cmd_path = get_valid_cmd(cmd, envp);
		if (!cmd_path)
		{
			ft_free_arr_2d(args);
			write(2, "pipex: Command not found\n", 26);
			write(2, cmd, ft_strlen(cmd));
			exit(127);
		}
	}
	execve(cmd_path, args, envp);
	perror("execve failed");
	free(cmd_path);
	ft_free_arr_2d(args);
	exit(127);
}
