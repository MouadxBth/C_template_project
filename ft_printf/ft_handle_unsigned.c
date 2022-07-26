/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:30:25 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/18 20:01:40 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unsigned(int fd, t_format *format, unsigned int nbr)
{
	size_t	nbr_len;

	if (!format || fd < 0)
		return (0);
	nbr_len = ft_unsigned_nbrlen(nbr, 10);
	if (format->sign_precedence || format->sign_replacement)
		nbr_len++;
	if (format->left_justify)
		return (ft_putnbr(fd, nbr, 0, "0123456789")
			+ ft_repeat_print(fd, ' ', format->left_justify - nbr_len));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - nbr_len)
			+ ft_putnbr(fd, nbr, 0, "0123456789"));
	return (ft_handle_padding(fd, format, nbr_len)
		+ ft_putnbr(fd, nbr, 0, "0123456789"));
}

int	ft_handle_unsigned(int fd, t_format *format)
{
	return (ft_print_unsigned(fd, format, va_arg(format->args, unsigned int)));
}
