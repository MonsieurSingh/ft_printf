# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 03:56:02 by tesingh           #+#    #+#              #
#    Updated: 2024/04/02 09:41:27 by tesingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror

HDR_DIR		=	./includes/
HDR_FILE	=	ft_printf.h
BHDR_FILE	=	ft_printf_bonus.h

HEADERS		=	$(addprefix $(HDR_DIR), $(HDR_FILE))
BHEADERS	=	$(addprefix $(HDR_DIR), $(BHDR_FILE))

SRC_DIR		=	./src/
BSRC_DIR	=	./_bonus/
SRC_FILE	=	ft_printf.c
BSRC_FILE	=	ft_printf_bonus.c utils_bonus.c buffer_bonus.c parser_bonus.c unpack_bonus.c render_bonus.c

SOURCES		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
BSOURCES	=	$(addprefix $(BSRC_DIR), $(BSRC_FILE))

OBJ_DIR		=	./obj/
BOBJ_DIR	=	./obj/
OBJ_FILE	=	$(patsubst %.c, %.o, $(SRC_FILE))
BOBJ_FILE	=	$(patsubst %.c, %.o, $(BSRC_FILE))
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))
BOBJECTS	=	$(addprefix $(BOBJ_DIR), $(BOBJ_FILE))


all			:	$(NAME)

bonus		:	fclean libft $(BOBJ_DIR) $(BOBJECTS)
		@ar -rcs libftprintf.a ./obj/*.o
		@echo "\033[0;92m* $(NAME) library file was created *\033[0m"

$(NAME)		:	libft $(OBJ_DIR) $(OBJECTS)
		@ar -rcs $(NAME) ./obj/*.o
		@echo "\033[0;92m* $(NAME) library file was created *\033[0m"

$(BOBJ_DIR)%.o : $(BSRC_DIR)%.c
		@$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@$(CC) $(CCFLAGS) -c $< -o $@

libft		:
		@make -C libft
		@mkdir -p obj
		@mv libft/*.o obj 

clean		:
		@rm -rf $(OBJECTS) $(BOBJECTS)
		@echo "\033[0;91m* $(NAME) object files were deleted *\033[0m"

fclean		:	clean
		@rm -rf $(NAME)
		@rm -rf libft/libft.a
		@rm -rf libftprintf.a
		@rm -rf ./obj
		@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re libft bonus
