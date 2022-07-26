/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:05:21 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/24 13:19:19 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_conversion(int c)
{
	return (c == 'u' || c == 'd' || c == 'c' || c == 's'
		|| c == 'i' || c == 'p' || c == 'x' || c == 'X'
		|| c == '%');
}

size_t	ft_len(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_repeat_print(int fd, int c, int n)
{
	size_t	length;

	if (fd < 0)
		return (0);
	length = 0;
	while (n-- > 0)
		length += write(fd, &c, 1);
	return (length);
}
