# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vronveau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 16:35:06 by vronveau          #+#    #+#              #
#    Updated: 2015/12/12 15:56:54 by vronveau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Werror -Wextra

SOURCES = `ls | grep "\.c"`
OBJECTS = `ls | grep "\.o"`

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -c $(SOURCES)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
