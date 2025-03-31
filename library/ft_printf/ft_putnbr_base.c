/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:42:24 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/01/10 20:22:56 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_puthexa(unsigned long long num, char *base)
{
	int					len;
	int					count;
	unsigned long long	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (num >= base_len)
		len += ft_puthexa(num / base_len, base);
	count = ft_putchar(base[num % base_len]);
	if (count == -1)
		return (-1);
	len++;
	return (len);
}

static int	ft_putnbr(long long num, char *base)
{
	int			len;
	int			count;
	long long	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		len++;
	}
	if (num >= base_len)
		len += ft_putnbr(num / base_len, base);
	count = ft_putchar(base[num % base_len]);
	if (count == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putnbr_base(long long num, char *base)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len == 16)
		count = ft_puthexa((unsigned long long)num, base);
	else
		count = ft_putnbr(num, base);
	if (count == -1)
		return (-1);
	return (count);
}
