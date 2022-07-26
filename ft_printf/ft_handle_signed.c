/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:56:23 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/18 22:06:43 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_sign(int fd, t_format *format, int nbr)
{
	if (format->sign_precedence && nbr >= 0)
		return (write(fd, "+", 1));
	else if (format->sign_replacement && nbr >= 0)
		return (write(fd, " ", 1));
	else if (nbr < 0)
		return (write(fd, "-", 1));
	return (0);
}

static int	ft_print_signed(int fd, t_format *format, int nbr)
{
	int	nbr_len;

	if (!format || fd < 0)
		return (0);
	nbr_len = ft_signed_nbrlen(nbr, 10);
	if ((format->sign_precedence || format->sign_replacement) && nbr >= 0)
		nbr_len++;
	if (format->left_justify)
		return (ft_handle_sign(fd, format, nbr)
			+ ft_putnbr(fd, nbr, 1, "0123456789")
			+ ft_repeat_print(fd, ' ', format->left_justify - nbr_len));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - nbr_len)
			+ ft_handle_sign(fd, format, nbr)
			+ ft_putnbr(fd, nbr, 1, "0123456789"));
	if (nbr < 0 && format->precision_flag)
		nbr_len--;
	return (ft_handle_sign(fd, format, nbr)
		+ ft_handle_padding(fd, format, nbr_len)
		+ ft_putnbr(fd, nbr, 1, "0123456789"));
}

int	ft_handle_signed(int fd, t_format *format)
{
	return (ft_print_signed(fd, format, va_arg(format->args, int)));
}
