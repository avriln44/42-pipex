/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnhat <minhnhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:15 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/04/02 00:26:29 by minhnhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static char **check_cmd(char *cmd)
// {
// 	char **check;

// 	if (!cmd)
// 		return (NULL);
// 	check = ft_split(cmd, ' ');
// 	if (!check)
// 	{
// 		write(2, "Error: Memory allocation failed\n", 32);
// 		exit(1);
// 	}
// 	return (check);
// }

static void free_resources(char **cmd_arr, char **check)
{
	ft_free_arr_2d(cmd_arr);
	ft_free_arr_2d(check);
}

char *handle_absolute_path(char **check)
{
	if (access(check[0], F_OK) == -1)
	{
		write(2, "Error: No such file or directory\n", 33);
		free_resources(NULL, check);
		exit(127);
	}
	if (open(check[0], O_DIRECTORY) != -1)
	{
		write(2, "Error: Is a directory\n", 22);
		free_resources(NULL, check);
		exit(126);
	}
	if (access(check[0], X_OK) == -1)
	{
		write(2, "Error: Permission denied\n", 25);
		free_resources(NULL, check);
		exit(126);
	}
	return (ft_strdup(check[0]));
}

// char *get_valid_cmd(char *cmd, char **envp)
// {
// 	int i;
// 	char **cmd_arr;
// 	char **check;
// 	char *valid_cmd;

// 	if (!cmd || !envp || !*envp)
// 		return (NULL);
// 	cmd_arr = get_cmd_arr(envp);
// 	check = check_cmd(cmd);
// 	if (ft_strchr(check[0], '/') != NULL)
// 		return (handle_absolute_path(check));
// 	if (!cmd_arr || !*cmd_arr || !check || !*check)
// 		return (free_resources(cmd_arr, check), NULL);
// 	i = 0;
// 	while (cmd_arr[i])
// 	{
// 		valid_cmd = build_valid_cmd(cmd_arr[i], check[0]);
// 		if (valid_cmd)
// 			return (valid_cmd);
// 		i++;
// 	}
// 	free_resources(cmd_arr, check);
// 	exit(127);
// }

char *get_valid_cmd(char *cmd, char **envp)
{
	int i;
	char **cmd_arr;
	char **check;
	char *valid_cmd;

	if (!cmd)
		return (NULL);

	check = ft_split(cmd, ' ');
	if (!check || !check[0])
	{
		write(2, "pipex: Command not found\n", 26);
		exit(127);
	}

	// ✅ If `cmd` contains '/' (absolute or relative path), handle it directly
	if (ft_strchr(check[0], '/'))
	{
		if (access(check[0], F_OK) == -1)
		{
			write(2, "pipex: No such file or directory\n", 33);
			exit(127);
		}
		if (access(check[0], X_OK) == -1)
		{
			write(2, "pipex: Permission denied\n", 26);
			exit(126);
		}
		return (ft_strdup(check[0]));
	}

	// ✅ If `envp` is empty, return an error
	if (!envp || !*envp)
	{
		write(2, "pipex: PATH not found\n", 22);
		exit(127);
	}

	// ✅ Search in PATH
	cmd_arr = get_cmd_arr(envp);
	if (!cmd_arr)
	{
		free_resources(NULL, check);
		write(2, "pipex: PATH parsing failed\n", 27);
		exit(127);
	}

	i = 0;
	while (cmd_arr[i])
	{
		valid_cmd = build_valid_cmd(cmd_arr[i], check[0]);
		if (valid_cmd)
		{
			free_resources(cmd_arr, check);
			return (valid_cmd);
		}
		i++;
	}

	// ✅ If no valid command is found, exit with `127`
	write(2, "pipex: Command not found\n", 26);
	free_resources(cmd_arr, check);
	exit(127);
}
