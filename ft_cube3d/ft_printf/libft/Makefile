# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 09:48:13 by mbari             #+#    #+#              #
#    Updated: 2020/11/17 12:27:13 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_intsize.c ft_isalnum.c ft_isalpha.c \
	  	ft_isdigit.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putendl.c \
		ft_putnbr.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_putstr.c ft_memcmp.c ft_putunsignednbr.c ft_strrev.c \
		ft_strcat.c

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(SRC_BONUS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus:  $(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean: 
	@/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
