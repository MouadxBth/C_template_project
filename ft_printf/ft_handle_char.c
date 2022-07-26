/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:53:15 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/18 20:02:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(int fd, t_format *format, int c)
{
	if (!format || fd < 0)
		return (0);
	if (format->left_justify)
		return (write(fd, &c, 1)
			+ ft_repeat_print(fd, ' ', format->left_justify - 1));
	else if (format->minimum_width)
		return (ft_repeat_print(fd, ' ', format->minimum_width - 1)
			+ write(fd, &c, 1));
	return (write(fd, &c, 1));
}

int	ft_handle_char(int fd, t_format *format)
{
	return (ft_print_char(fd, format, va_arg(format->args, int)));
}
