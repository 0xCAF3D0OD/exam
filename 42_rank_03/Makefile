# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:17:05 by kdi-noce          #+#    #+#              #
#    Updated: 2022/08/20 16:38:12 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= exam
C		= gcc
CFLAG	= -Wall -Wextra -Werror
CFILE	= micro_paint.c
DEL		= rm -rf

all:	$(NAME)

$(NAME):
		$(C) $(CFLAG) $(CFILE) -o $(NAME)

ds:		
		$(DEL) .DS_Store
fclean:
		$(DEL) $(NAME)

re:		fclean all