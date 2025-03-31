/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-mngu <thi-mngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:41:00 by thi-mngu          #+#    #+#             */
/*   Updated: 2025/03/05 16:26:44 by thi-mngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *str);
int		format_check(char specifier, va_list ap);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr_base(long long num, char *base);
int		ft_putptr(unsigned long long ptr, char *base);
#endif