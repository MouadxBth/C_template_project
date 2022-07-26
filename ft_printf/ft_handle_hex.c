/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:59:33 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/18 20:14:39 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_handle_base(t_format *format)
{
	if (format->specifier == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static int	ft_handle_alt_form(int fd, t_format *format)
{
	if (format->alt_form)
	{
		if (format->specifier == 'X')
			return (write(fd, "0X", 2));
		else
			return (write(fd, "0x", 2));
	}
	return (0);
}

static int	ft_print_hex(int fd, t_format *format, unsigned int nbr)
{
	int		result;
	size_t	nbr_len;
	char	*base;

	if (!format || fd < 0)
		return (0);
	nbr_len = ft_unsigned_nbrlen(nbr, 16);
	base = ft_handle_base(format);
	if (format->alt_form)
		nbr_len += 2;
	if (format->left_justify)
		return (ft_handle_alt_form(fd, format)
			+ ft_putnbr(fd, nbr, 0, base)
			+ ft_repeat_print(fd, ' ', format->left_justify - nbr_len));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - nbr_len)
			+ ft_handle_alt_form(fd, format)
			+ ft_putnbr(fd, nbr, 0, base));
	result = 0;
	if (nbr)
		result += ft_handle_alt_form(fd, format);
	result += ft_handle_padding(fd, format, nbr_len)
		+ ft_putnbr(fd, nbr, 0, base);
	return (result);
}

int	ft_handle_hex(int fd, t_format *format)
{
	return (ft_print_hex(fd, format, va_arg(format->args, unsigned int)));
}
