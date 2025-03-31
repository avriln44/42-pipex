/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:19:35 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/01/20 14:15:46 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count = ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (specifier == 'u')
		count = ft_putnbr_base((unsigned int)va_arg(ap, int), "0123456789");
	else if (specifier == 'x')
		count = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (specifier == 'p')
		count = ft_putptr((uintptr_t)va_arg(ap, void *), "0123456789abcdef");
	else if (specifier == '%')
		count = ft_putchar('%');
	else
		count = -1;
	return (count);
}
