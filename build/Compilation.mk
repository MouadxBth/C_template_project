# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Compilation.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:18:04 by mbouthai          #+#    #+#              #
#    Updated: 2022/03/20 18:21:13 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef COMPILATION_MK
	COMPILATION_MK = 1

NAME	= main

CC	= gcc

CFLAGS	+= -Wall -Werror -Wextra

LDFLAGS += 

endif
