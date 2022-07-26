/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:28:59 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/24 13:19:52 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_print_nbr(int fd, unsigned long n, char *base, size_t radix)
{
	unsigned long	nbr;
	size_t			result;

	nbr = n;
	result = 0;
	if ((size_t) nbr < radix)
		result += write(fd, &base[nbr], 1);
	else
	{
		result += ft_print_nbr(fd, nbr / radix, base, radix);
		result += ft_print_nbr(fd, nbr % radix, base, radix);
	}
	return (result);
}

size_t	ft_unsigned_nbrlen(unsigned long n, int base)
{
	size_t	length;

	length = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base;
		length++;
	}
	return (length);
}

size_t	ft_signed_nbrlen(long long n, int base)
{
	size_t	length;

	length = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n)
	{
		n /= base;
		length++;
	}
	return (length);
}

int	ft_handle_padding(int fd, t_format *format, size_t nbr_len)
{
	if (format->precision)
		return (ft_repeat_print(fd, '0', format->precision - nbr_len));
	else if (format->zero_padding)
		return (ft_repeat_print(fd, '0', format->zero_padding - nbr_len));
	return (0);
}

int	ft_putnbr(int fd, long long n, int is_signed, char *base)
{
	size_t	radix;
	int		result;

	if (fd < 0)
		return (0);
	radix = ft_len(base);
	if (radix <= 0)
		return (0);
	result = 0;
	if (is_signed && n < 0)
		n *= -1;
	result += ft_print_nbr(fd, n, base, radix);
	return (result);
}
