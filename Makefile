# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 15:13:44 by ahibrahi          #+#    #+#              #
#    Updated: 2024/02/01 12:29:06 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
AR = ar -rcs
RM = rm -f

FILES =  push_swap ft_atoi rotate reverse_rotate swap push utilles sort_stack\

PRINTF = ft_printf/printf.a
LIBFT = libft/libft.a

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(PRINTF):
	make -C ft_printf
$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make clean -C ft_printf
	make clean -C libft
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus $(PRINTF) $(LIBFT)

re: clean all

.PHONY: bonus all clean fclean re