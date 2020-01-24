# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 20:10:01 by tbeguin           #+#    #+#              #
#    Updated: 2020/01/23 05:39:30 by tbeguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = lib/ft_atoi.c		\
	 lib/ft_bzero.c		\
	 lib/ft_isdigit.c	\
	 lib/ft_memalloc.c	\
	 lib/ft_putchar.c	\
	 lib/ft_putstr.c	\
	 lib/ft_strdup.c	\
	 lib/ft_strlen.c	\
	 lib/ft_strnew.c	\
	 lib/ft_strsub.c	\
	 lib/pf_itoa_base.c	\
	 lib/pf_ftoa.c		\
	 lib/ft_strcat.c	\
	 ft_printf.c		\
	 pf_print.c			\
	 pf_catch.c			\
	 pf_check.c			\
	 pf_set.c			\
	 pf_handeler_b.c	\
	 pf_handeler_c.c	\
	 pf_handeler_f.c	\
	 pf_handeler_s.c	\
	 pf_handeler_p.c	\
	 pf_handeler_d.c	\
	 pf_handeler_o.c	\
	 pf_handeler_u.c	\
	 pf_handeler_x.c	\
	 pf_handeler_xup.c	\
	 pf_handeler_unknow.c	

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/lib 

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) is ready\033[0m"

clean : 
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mRemoved obj files\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved $(NAME)\033[0m"

re : fclean 
	@make all

.PHONY : all clean fclean re

