/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnhat <minhnhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:12:11 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/04/01 22:43:14 by minhnhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *get_path(char **envp)
{
	int i;
	char *default_path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";

	if (!envp || !*envp)
	{
		write(2, "Error: Environment PATH missing!\n", 33);
		exit(1);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_strnstr(envp[i], "PATH=", 5) + 5);
		i++;
	}
	return (default_path);
}

char **get_cmd_arr(char **envp)
{
	char **cmd_arr;
	char *path;

	path = get_path(envp);
	if (!path)
	{
		write(2, "Error: PATH not found\n", 22);
		exit(127);
	}
	cmd_arr = ft_split(path, ':');
	if (!cmd_arr)
	{
		write(2, "Error: Memory allocation failed\n", 32);
		exit(1);
	}
	return (cmd_arr);
}
