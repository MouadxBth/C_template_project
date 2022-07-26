/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:01:21 by mbouthai          #+#    #+#             */
/*   Updated: 2022/07/24 13:19:04 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef STD_FD
#  define STD_FD 1
# endif

typedef struct s_format {
	va_list	args;
	size_t	left_justify;
	size_t	minimum_width;
	size_t	zero_padding;
	size_t	precision;
	int		precision_flag;
	int		sign_precedence;
	int		sign_replacement;
	int		alt_form;
	char	specifier;
}	t_format;

t_format	*ft_new_format(void);
t_format	*ft_bzero_format(t_format *format);
t_format	*ft_correct_format(t_format *format);

int			ft_digit(int c);
int			ft_is_conversion(int c);

size_t		ft_len(const char *str);
size_t		ft_unsigned_nbrlen(unsigned long n, int base);
size_t		ft_signed_nbrlen(long long n, int base);
size_t		ft_repeat_print(int fd, int c, int n);

int			ft_handle_padding(int fd, t_format *format, size_t nbr_len);
int			ft_putnbr(int fd, long long n, int is_signed, char *base);

int			ft_handle_char(int fd, t_format *format);

int			ft_print_str(int fd, t_format *format, char *str);
int			ft_handle_str(int fd, t_format *format);

int			ft_handle_ptr(int fd, t_format *format);
int			ft_handle_hex(int fd, t_format *format);
int			ft_handle_signed(int fd, t_format *format);
int			ft_handle_unsigned(int fd, t_format *format);

int			ft_printf(const char *format, ...);

#endif
