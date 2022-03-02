# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 16:19:00 by potero            #+#    #+#              #
#    Updated: 2022/03/02 09:53:06 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/utils.c src/ph_data.c src/ph_thread.c\
	   src/ph_time.c src/ph_routine.c

INCS = inc/

OBJS = $(SRCS:.c=.o)

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o) -I$(INCS)

RM = rm -f

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -I$(INCS) -o $(NAME) -lpthread

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
