# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psimarro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 17:23:35 by psimarro          #+#    #+#              #
#    Updated: 2022/03/08 17:23:43 by psimarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #
INC_DIR				=	inc/
HEADER				= 	inc/libftprintf.h
NAME = libftprintf.a

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 		= gcc
CFLAGS	= -Wall #-Wextra -Werror -g #quitar g3 despues
RM		= rm -f

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_DIR				=	src/
SRC =	ft_printf.c					ft_is_pnt_or_h.c		\
		ft_num_utils.c				ft_print_char.c		\
		ft_print_str.c				ft_print_num.c 	\
		ft_utils_1.c				ft_utils_2.c
	
TMAIN				=	CHECKS.c

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all:		$(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):			Libft/libft.a $(OBJ) 
	ar rcs $(NAME) $(OBJ) Libft/obj/*.o 

test:				re
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ -o $@ $(TMAIN) $(NAME)

Libft/libft.a:
	$(MAKE) -C Libft

.PHONY:		all clean fclean re			

clean:
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) -C Libft clean

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean
	$(RM) test

re:			fclean all

bonus: