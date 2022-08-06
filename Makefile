# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/08/06 21:36:02 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= main

BOLD	:=\033[1m

RESET	:=\033[0m

RED	:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

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
	@echo "\n$(CYAN)BUILDING LIBFT$(RESET)\n"
	@make -C libft

$(PRINTF):
	@echo "\n$(CYAN)BUILDING FT_PRINTF$(RESET)\n"
	@make -C ft_printf

$(NAME): $(OBJS)
	@echo "\n$(GREEN)BUILDING PROJECT$(RESET)\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@echo "\n$(BOLD)CREATING OBJ DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(DEP_DIR):
	@echo "\n$(BOLD)CREATING DEP DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\n$(RED)CLEANING OBJECT FILES$(RESET)\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\n$(RED)CLEANING DEPENDENCIES$(RESET)\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir
	@echo "\n$(RED)CLEANING LIBFT$(RESET)\n"
	@make clean -C libft
	@echo "\n$(RED)CLEANING FT_PRINTF$(RESET)\n"
	@make clean -C ft_printf

fclean: clean
	@echo "\n$(RED)FCLEANING LIBFT$(RESET)\n"
	@make fclean -C libft
	@echo "\n$(RED)FCLEANING FT_PRINTF$(RESET)\n"
	@make fclean -C ft_printf
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
