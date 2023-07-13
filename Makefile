# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 04:24:56 by wwatik            #+#    #+#              #
#    Updated: 2023/07/12 18:55:37 by wwatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC =  main.c push_swap.c functions.c swap.c push.c rotate.c r_rotate.c sort.c sort_3_5.c utils_1.c utils_2.c utils_3.c libft_utils_1.c libft_utils.c get_next_line_utils.c
SRC_BONUS = checker.c get_next_line.c get_next_line_utils.c swap.c push.c rotate.c r_rotate.c sort.c sort_3_5.c push_swap.c functions.c utils_1.c utils_2.c utils_3.c libft_utils_1.c  libft_utils.c

CC = cc -Wall -Wextra -Werror

OBJS = ${SRC:%.c=%.o}
OBJS_BONUS = ${SRC_BONUS:%.c=%.o}

all :  $(NAME)

%.o : %.c push_swap.h
	$(CC) -c $< -o $@

$(NAME) : $(OBJS) 
	$(CC)  $(OBJS) -o $(NAME)
	
bonus :  $(NAME_BONUS) 
$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	
re : fclean all 

.PHONY :  all clean fclean re bonus