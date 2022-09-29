# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:35:14 by lperrin           #+#    #+#              #
#    Updated: 2022/09/29 13:05:51 by lperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	= srcs/lib/MLX42
LIBFT	= srcs/lib/libft

HEADERS	= -I $(LIBMLX)/include
GLFW	= /System/Volumes/Data/sgoinfre/goinfre/Perso/lperrin/homebrew/Cellar/glfw/3.3.8/lib
LIBS	= -ldl -lglfw -L $(GLFW) -pthread -lm $(LIBMLX)/libmlx42.a 
SRCS	= 	srcs/fractal/main.c \
#			srcs/fractal/test.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
