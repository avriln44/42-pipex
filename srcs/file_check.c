/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnhat <minhnhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:27:25 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/04/01 23:01:34 by minhnhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	open_file(char *file, int is_input)
// {
// 	if (access(file, F_OK) < 0)
// 	{
// 		write(2, "pipex: no such file or directory: ", 34);
// 		write(2, file, ft_strlen(file));
// 		write(2, "\n", 1);
// 		return (0);
// 	}
// 	if (is_input && access(file, R_OK) < 0)
// 	{
// 		write(2, "pipex: Permission denied: ", 26);
// 		write(2, file, ft_strlen(file));
// 		write(2, "\n", 2);
// 		return (0);
// 	}
// 	if (!is_input && access(file, W_OK) < 0)
// 	{
// 		write(2, "pipex: Permission denied: ", 26);
// 		write(2, file, ft_strlen(file));
// 		write(2, "\n", 2);
// 		return (0);
// 	}
// 	return (1);
// }

int open_file(char *file, int is_input)
{
	if (access(file, F_OK) < 0)
	{
		write(2, "pipex: no such file or directory: ", 34);
		write(2, file, ft_strlen(file));
		write(2, "\n", 1);
		exit(1); // 🔥 Fix: Exit immediately with error code 1
	}
	if (is_input && access(file, R_OK) < 0)
	{
		write(2, "pipex: Permission denied: ", 26);
		write(2, file, ft_strlen(file));
		write(2, "\n", 1);
		exit(1); // 🔥 Fix: Exit immediately with error code 1
	}
	if (!is_input && access(file, W_OK) < 0)
	{
		write(2, "pipex: Permission denied: ", 26);
		write(2, file, ft_strlen(file));
		write(2, "\n", 1);
		exit(1); // 🔥 Fix: Exit immediately with error code 1
	}
	return (1);
}
