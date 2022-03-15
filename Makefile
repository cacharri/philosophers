# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 16:20:40 by ialvarez          #+#    #+#              #
#    Updated: 2022/03/15 20:14:43 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = philo

SRCS = philo.c

INCLUDES = -I
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -lft -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:
			clean
			fclean
			all
			re

