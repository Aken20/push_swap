# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 15:13:44 by ahibrahi          #+#    #+#              #
#    Updated: 2024/02/06 07:04:40 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES =  push_swap ft_atoi ft_split rotate reverse_rotate swap push utilles sort_stack radix\

PRINTF = ft_printf/printf.a

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C ft_printf

clean:
	make clean -C ft_printf
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(PRINTF)

re: clean all

.PHONY: all clean fclean re