/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:52:53 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/24 13:20:21 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(int fd, const char *str, size_t length)
{
	if (!str)
		return (write(fd, "(null)", length));
	return (write(fd, str, length));
}

static int	ft_precision(int fd, size_t precision, char *str, size_t str_len)
{
	size_t	bytes;

	if (!str && precision >= str_len)
		return (ft_putstr(fd, str, str_len));
	if (precision <= str_len)
		bytes = precision;
	else
		bytes = str_len;
	return (write(fd, str, bytes));
}

int	ft_print_str(int fd, t_format *format, char *str)
{
	size_t	str_len;

	if (!format || fd < 0)
		return (0);
	if (!str)
		str_len = 6;
	else
		str_len = ft_len(str);
	if (format->left_justify)
		return (ft_putstr(fd, str, str_len)
			+ ft_repeat_print(fd, ' ', format->left_justify - str_len));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - str_len)
			+ ft_putstr(fd, str, str_len));
	else if (format->precision_flag)
		return (ft_precision(fd, format->precision, str, str_len));
	return (ft_putstr(fd, str, str_len));
}

int	ft_handle_str(int fd, t_format *format)
{
	return (ft_print_str(fd, format, va_arg(format->args, char *)));
}
