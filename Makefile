# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 16:19:00 by potero            #+#    #+#              #
#    Updated: 2022/03/01 12:22:24 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c utils.c ph_data.c ph_thread.c ph_time.c ph_routine.c

OBJS = $(SRCS:.c=.o)

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
