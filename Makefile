# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 16:20:40 by ialvarez          #+#    #+#              #
#    Updated: 2022/05/05 20:27:47 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
NAME = philo

SRCS = philo.c init.c aux_dead.c dead_time.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:
			clean
			fclean
			all
			re

