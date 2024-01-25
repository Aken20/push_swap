# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 15:13:44 by ahibrahi          #+#    #+#              #
#    Updated: 2024/01/25 17:01:11 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES =  push_swap \

GNL = get_next_line/GNL.a
PRINTF = ft_printf/printf.a
LIBFT = libft/libft.a

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(GNL):
	make -C get_next_line
$(PRINTF):
	make -C ft_printf
$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS) $(PRINTF) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

clean:
	make clean -C get_next_line
	make clean -C ft_printf
	make clean -C libft
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus $(PRINTF) $(GNL) $(LIBFT)

re: clean all

.PHONY: bonus all clean fclean re