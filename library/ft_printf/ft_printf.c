/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:40 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/01/22 18:16:14 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	int		final_count;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	count = 0;
	final_count = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			count = format_check(s[++i], ap);
		else
			count = ft_putchar(s[i]);
		if (count == -1)
			return (-1);
		final_count += count;
		i++;
	}
	va_end(ap);
	return (final_count);
}
