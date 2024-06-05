# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 17:31:33 by lmaume            #+#    #+#              #
#    Updated: 2024/06/05 18:19:25 by lmaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_A = MLX42/libmlx42.a

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= -Iinclude -ldl -lglfw -pthread -lm

SRCS =	so_long.c \
		parsing/init_map.c \
		parsing/parsing_map.c \
		parsing/pathfinding.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

PRINTF = ./printf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) all -C ./printf
	@cp $(PRINTF) $(NAME)
	@cc $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean :
	@$(MAKE) clean -C ./printf
	@$(RM) $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ./printf
	@$(RM) $(NAME)

re : fclean all
