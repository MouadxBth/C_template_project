# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 12:39:59 by mbouthai          #+#    #+#              #
#    Updated: 2022/07/23 15:23:24 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= gcc

ARCHIVE	= ar -rcs

DEPS	= ft_printf.h

CFLAGS	= -Wall -Wextra

SRCS	= ft_printf_utils.c  ft_printf_nbr_utils.c \
	  ft_handle_char.c ft_handle_str.c \
	  ft_handle_hex.c ft_handle_ptr.c \
	  ft_handle_signed.c ft_handle_unsigned.c \
	  ft_printf_format.c ft_printf.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME) 

bonus: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
