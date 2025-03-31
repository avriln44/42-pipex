/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:45:25 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/23 15:17:10 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (argc != 5)
	{
		write(2, "Arguments error!\n", 18);
		exit(1);
	}
	execute(argv, envp, fd);
	return (0);
}
