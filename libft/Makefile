# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 09:08:23 by avanhers          #+#    #+#              #
#    Updated: 2019/05/08 13:55:31 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES = ft_memset.c     \
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c    \
		ft_memmove.c    \
		ft_memchr.c     \
		ft_memcmp.c     \
		ft_strlen.c     \
		ft_strdup.c     \
		ft_strcpy.c     \
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c    \
		ft_strlcat.c    \
		ft_strchr.c     \
		ft_strrchr.c    \
		ft_strstr.c     \
		ft_strnstr.c    \
		ft_strcmp.c     \
		ft_strncmp.c    \
		ft_atoi.c       \
		ft_isalpha.c    \
		ft_isdigit.c    \
		ft_isalnum.c    \
		ft_isascii.c    \
		ft_isprint.c    \
		ft_toupper.c    \
		ft_tolower.c    \
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lst_remove_if.c\
		get_next_line.c	\
		ft_slicenew.c	\
		ft_sliceappend.c\
		ft_slicetomatrix.c

OBJET =$(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -c $(FILES) 
	ar rc $(NAME) $(OBJET)
	ranlib $(NAME)
	@echo "\033[32mlibft is ready\033[0m"

clean :
	rm -f $(OBJET)
	@echo "\033[33mall .o files are removed\033[0m"

fclean : clean
	rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re : fclean all
