# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 17:31:33 by lmaume            #+#    #+#              #
#    Updated: 2024/04/12 18:19:58 by lmaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c

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
