/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:15 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 17:17:59 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**check_cmd(char *cmd)
{
	char	**check;

	if (!cmd)
		return (NULL);
	check = ft_split(cmd, ' ');
	if (!check)
		return (NULL);
	return (check);
}

static void	free_resources(char **cmd_arr, char **check)
{
	ft_free_arr_2d(cmd_arr);
	ft_free_arr_2d(check);
}

char	*handle_absolute_path(char **check)
{
	if (access(check[0], F_OK) == -1)
	{
		write(2, "No such file or directory\n", 26);
		free_resources(NULL, check);
		exit(127);
	}
	if (access(check[0], X_OK) == -1)
	{
		write(2, "Permission denied\n", 18);
		free_resources(NULL, check);
		exit(127);
	}
	return (ft_strdup(check[0]));
}

char	*get_valid_cmd(char *cmd, char **envp)
{
	int		i;
	char	**cmd_arr;
	char	**check;
	char	*valid_cmd;

	if (!cmd || !envp || !*envp)
		return (NULL);
	cmd_arr = get_cmd_arr(envp);
	check = check_cmd(cmd);
	if (ft_strchr(check[0], '/') != NULL)
		return (handle_absolute_path(check));
	if (!cmd_arr || !*cmd_arr || !check || !*check)
		return (free_resources(cmd_arr, check), NULL);
	i = 0;
	while (cmd_arr[i])
	{
		valid_cmd = build_valid_cmd(cmd_arr[i], check[0]);
		if (valid_cmd)
			return (valid_cmd);
		i++;
	}
	free_resources(cmd_arr, check);
	return (NULL);
}
