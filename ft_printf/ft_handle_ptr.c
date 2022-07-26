/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:54:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/18 20:23:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(int fd, t_format *format, unsigned long nbr)
{
	size_t	nbr_len;

	if (!format || fd < 0)
		return (0);
	if (!nbr)
		return (ft_print_str(fd, format, "(nil)"));
	nbr_len = ft_unsigned_nbrlen(nbr, 16) + 2;
	if (format->left_justify)
		return (write(fd, "0x", 2) + ft_putnbr(fd, nbr, 0, "0123456789abcdef")
			+ ft_repeat_print(fd, ' ', format->left_justify - nbr_len));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - nbr_len)
			+ write(fd, "0x", 2) + ft_putnbr(fd, nbr, 0, "0123456789abcdef"));
	return (write(fd, "0x", 2) + ft_putnbr(fd, nbr, 0, "0123456789abcdef"));
}

int	ft_handle_ptr(int fd, t_format *format)
{
	return (ft_print_ptr(fd, format, va_arg(format->args, unsigned long)));
}
