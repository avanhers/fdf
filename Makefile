# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 09:15:22 by avanhers          #+#    #+#              #
#    Updated: 2019/05/08 14:03:14 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRCS=main.c			\
     bresenham.c	\
	 fdf.c			\
	 parsing.c		\
	 isometric.c	\
	 key.c			\
	 free.c

OBJS= $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC= gcc

all : $(NAME)

$(NAME) : $(OBJS)
	make -sC libft
	$(CC)  -o $(NAME) $(SRCS) libft/libft.a \
	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(OBJS) : $(SRCS)
	$(CC) -c $(FLAGS) $(SRCS) -I /usr/local/include/ 

clean :
	make -sC libft clean
	rm -f $(OBJS)

fclean : clean
	make -sC libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
