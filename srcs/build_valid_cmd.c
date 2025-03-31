/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_valid_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:21:01 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 12:21:28 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_temp_cmd(char *cmd)
{
	char	*temp_cmd;

	if (!cmd)
		return (NULL);
	temp_cmd = ft_strjoin(cmd, "/");
	if (!temp_cmd)
		return (NULL);
	return (temp_cmd);
}

char	*build_valid_cmd(char *path, char *cmd_part)
{
	char	*temp;
	char	*valid_cmd;

	temp = get_temp_cmd(path);
	if (!temp)
		return (NULL);
	valid_cmd = ft_strjoin(temp, cmd_part);
	free(temp);
	if (!valid_cmd)
	{
		free(temp);
		exit(127);
	}
	if (access(valid_cmd, X_OK) == 0)
		return (valid_cmd);
	free(valid_cmd);
	return (NULL);
}
