# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 11:29:48 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/31 13:59:51 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME1	= gnl
NAME2	= printf
NAME3	= union
NAME4	= inter
NAME	= $(NAME1) $(NAME2) $(NAME3) $(NAME4)

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

FILE1	= gnl.c
FILE2	= printf.c
FILE3	= union.c
FILE4	= inter.c

OBJ1	= $(FILE1:.c=.o)
OBJ2	= $(FILE2:.c=.o)
OBJ3	= $(FILE3:.c=.o)
OBJ4	= $(FILE4:.c=.o)

all: $(NAME) 

$(NAME): $(FILE1) $(FILE2) $(FILE3) $(FILE4)
	$(CC) $(CFLAG) $(FILE1) -o $(NAME1)
	$(CC) $(CFLAG) $(FILE2) -o $(NAME2)
	$(CC) $(CFLAG) $(FILE3) -o $(NAME3)	
	$(CC) $(CFLAG) $(FILE4) -o $(NAME4)	

fclean: 
	rm -rf $(NAME)

re: fclean all
