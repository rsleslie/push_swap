# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 21:03:58 by rleslie-          #+#    #+#              #
#    Updated: 2023/03/08 18:29:41 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = position.c check_error.c create_list.c move_stack.c move_stack_2.c order_stack.c push_swap.c radix.c
INCLUDES = libft/libft.a 
CC = cc

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) -g $(SRC) $(INCLUDES) -o $(NAME)

clean:
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all