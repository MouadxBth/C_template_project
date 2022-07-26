/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:21:14 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/17 11:11:06 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_new_format(void)
{
	t_format	*result;

	result = (t_format *)malloc(sizeof(t_format));
	if (!result)
		return (NULL);
	return (result);
}

t_format	*ft_bzero_format(t_format *format)
{
	if (!format)
		return (NULL);
	format->left_justify = 0;
	format->minimum_width = 0;
	format->zero_padding = 0;
	format->precision = 0;
	format->precision_flag = 0;
	format->sign_precedence = 0;
	format->sign_replacement = 0;
	format->alt_form = 0;
	return (format);
}

t_format	*ft_correct_format(t_format *format)
{
	if (format->zero_padding && format->left_justify)
		format->zero_padding = 0;
	if (format->sign_replacement && format->sign_precedence)
		format->sign_replacement = 0;
	if (format->precision_flag && format->zero_padding)
		format->zero_padding = 0;
	return (format);
}
