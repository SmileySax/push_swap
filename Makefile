# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 02:45:00 by keaton            #+#    #+#              #
#    Updated: 2022/07/22 22:35:36 by keaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

FLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h

SRCS 	= 	main.c		checks.c\
 			swap.c		sort.c\
			lib_part.c	processing.c\
			lib_part2.c	processing_extra.c\
			rotate.c	rrotate.c	push.c

BONUS	=	main_bonus.c		checks_bonus.c\
 			swap_bonus.c		lib_part_bonus.c\
			rotate_bonus.c		rrotate_bonus.c\
			push_bonus.c		lib_part2_bonus.c\
			sort_bonus.c		get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

.PHONY: all re clean fclean

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	${RM} $(OBJS) $(BONUS_OBJS)

fclean: clean
	${RM} $(NAME) ${BONUS_NAME}

re: fclean all

