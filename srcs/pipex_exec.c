/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:49:49 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 16:02:33 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **argv, char **envp, int *fd)
{
	int		fd_in;

	if (!open_file(argv[1], 1))
	{
		exit(1);
	}
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		write(2, "pipex: Permission denied\n", 26);
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	pipex_execute(envp, argv[2]);
	exit(0);
}

void	second_cmd(char **argv, char **envp, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1 || !open_file(argv[4], 0))
	{
		write(2, "pipex: Permission denied\n", 26);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	pipex_execute(envp, argv[3]);
	perror("execve failed");
	exit(0);
}

static	int	wait_for_children(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	if (waitpid(pid1, &status1, 0) == -1)
	{
		perror("Error waiting for first child");
		exit(1);
	}
	if (waitpid(pid2, &status2, 0) == -1)
	{
		perror("Error waiting for second child");
		exit(1);
	}
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

static void	handle_fork_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	execute(char **argv, char **envp, int *fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pipex_pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		handle_fork_error("error fork: first command\n");
	if (pid1 == 0)
	{
		first_cmd(argv, envp, fd);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == -1)
		handle_fork_error("error fork: first command\n");
	if (pid2 == 0)
		second_cmd(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	exit(wait_for_children(pid1, pid2));
}
