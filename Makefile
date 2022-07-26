# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/07/26 15:41:36 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= main

INC_DIR	:= inc/ 

EXTERN	:= -Ilibft/ -Ift_printf/ -Iget_next_line/

SRC_DIR	:= src/

OBJ_DIR	:= obj/

DEP_DIR	:= dep/

RM	:= rm -f

RMDIR	:= rmdir

CC	:= gcc

CFLAGS	:= -Wall -Werror -Wextra -I$(INC_DIR) $(EXTERN)

LFLAGS	:= -L./libft -L./ft_printf -lft -lftprintf

INC_FS	:= main.h

SRC_FS	:= main.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

LIBFT	:= libft.a

PRINTF	:= libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)

bonus: $(NAME)

$(LIBFT):
	@echo "\nBUILDING LIBFT\n"
	@make bonus -C libft

$(PRINTF):
	@echo "\nBUILDING FT_PRINTF\n"
	@make -C ft_printf

$(NAME): $(OBJS)
	@echo "\nBUILDING PROJECT\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@mkdir -p $@

$(DEP_DIR):
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\nCLEANING OBJECT FILES\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\nCLEANING DEPENDENCIES\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir
	@echo "\nCLEANING LIBFT\n"
	@make clean -C libft
	@echo "\nCLEANING FT_PRINTF\n"
	@make clean -C ft_printf

fclean: clean
	@echo "\nFCLEANING LIBFT\n"
	@make fclean -C libft
	@echo "\nFCLEANING FT_PRINTF\n"
	@make fclean -C ft_printf
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
