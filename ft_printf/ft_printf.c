/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:02:53 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/24 13:20:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	ft_get_int(const char *str, int *chars_to_skip)
{
	int	result;
	int	length;

	result = 0;
	length = -1;
	while (ft_digit(str[++length]))
		result = (result * 10) + (str[length] - '0');
	*chars_to_skip += length;
	return (result);
}

static int	ft_process_flags(const char *str, t_format *format)
{
	int	index;

	index = 0;
	while (!ft_is_conversion(str[index]))
	{
		if (str[index] == '-')
			format->left_justify = ft_get_int(str + ++index, &index);
		else if (str[index] == '0')
			format->zero_padding = ft_get_int(str + ++index, &index);
		else if (str[index] == '#')
			format->alt_form = ++index;
		else if (str[index] == ' ')
			format->sign_replacement = ++index;
		else if (str[index] == '+')
			format->sign_precedence = ++index;
		else if (ft_digit(str[index]))
			format->minimum_width = ft_get_int(str + index, &index);
		else if (str[index] == '.')
		{
			format->precision = ft_get_int(str + ++index, &index);
			format->precision_flag = 1;
		}
	}
	return (index);
}

static int	ft_process_specifiers(const char *str, t_format *format)
{
	if (*str == 'c')
		return (ft_handle_char(STD_FD, format));
	else if (*str == 's')
		return (ft_handle_str(STD_FD, format));
	else if (*str == 'd' || *str == 'i')
		return (ft_handle_signed(STD_FD, format));
	else if (*str == 'u')
		return (ft_handle_unsigned(STD_FD, format));
	else if (*str == 'p')
		return (ft_handle_ptr(STD_FD, format));
	else if (*str == '%')
		return (write(1, "%", 1));
	else if (*str == 'x')
	{
		format->specifier = 'x';
		return (ft_handle_hex(STD_FD, format));
	}
	else if (*str == 'X')
	{
		format->specifier = 'X';
		return (ft_handle_hex(STD_FD, format));
	}
	return (0);
}

static int	ft_loop(t_format *format, const char *str, ...)
{
	int		index;
	int		bytes_written;

	index = 0;
	bytes_written = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			ft_bzero_format(format);
			index++;
			index += ft_process_flags(str + index, format);
			format = ft_correct_format(format);
			bytes_written += ft_process_specifiers(str + index, format);
		}
		else
			bytes_written += write(STD_FD, &str[index], 1);
		index++;
	}
	return (bytes_written);
}

int	ft_printf(const char *str, ...)
{
	t_format	*format;
	int			bytes_written;

	if (!str)
		return (0);
	format = ft_bzero_format(ft_new_format());
	if (!format)
		return (0);
	va_start(format->args, str);
	bytes_written = ft_loop(format, str);
	va_end(format->args);
	free(format);
	return (bytes_written);
}
