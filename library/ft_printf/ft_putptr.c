/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:28:18 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/01/19 19:11:47 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr, char *base)
{
	int	count;
	int	ptr_count;

	if (ptr == 0)
		ptr_count = write(1, "(nil)", 5);
	else
	{
		count = write(1, "0x", 2);
		ptr_count = ft_putnbr_base(ptr, base);
		ptr_count += count;
	}
	if (ptr_count < 2)
		return (-1);
	return (ptr_count);
}
