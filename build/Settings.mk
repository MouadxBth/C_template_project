# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Settings.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:21:18 by mbouthai          #+#    #+#              #
#    Updated: 2022/03/20 18:21:34 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef SETTINGS_MK
	SETTINGS_MK = 1

INC_DIR	= inc/

SRC_DIR	= src/

OBJ_DIR	= obj/

DEP_DIR	= dep/

INCLUDES= main.h

SOURCES	= main.c

INCS	= $(addprefix $(INC_DIR), $(INCLUDES))

SRCS	= $(addprefix $(SRC_DIR), $(SOURCES))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

endif
