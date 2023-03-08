# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 21:03:58 by rleslie-          #+#    #+#              #
#    Updated: 2023/03/08 13:02:08 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = check_error.c create_list.c move_stack.c move_stack_2.c order_stack.c push_swap.c radix.c
INCLUDES = libft/libft.a 
CC = cc

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(SRC) $(INCLUDES) -o $(NAME)

clean:
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all