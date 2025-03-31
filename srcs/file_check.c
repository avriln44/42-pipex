/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:27:25 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/31 17:23:26 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int is_input)
{
	if (access(file, F_OK) < 0)
	{
		write(2, "pipex: no such file or directory: ", 34);
		write(2, file, ft_strlen(file));
		write(2, "\n", 1);
		return (0);
	}
	if (is_input && access(file, R_OK) < 0)
	{
		write(2, "pipex: Permission denied: ", 26);
		write(2, file, ft_strlen(file));
		write(2, "\n", 2);
		return (0);
	}
	if (!is_input && access(file, W_OK) < 0)
	{
		write(2, "pipex: Permission denied: ", 26);
		write(2, file, ft_strlen(file));
		write(2, "\n", 2);
		return (0);
	}
	return (1);
}
