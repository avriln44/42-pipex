/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:42:55 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/01/22 17:56:45 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = write(1, s, ft_strlen(s));
	if (count == -1)
		return (-1);
	return (count);
}
