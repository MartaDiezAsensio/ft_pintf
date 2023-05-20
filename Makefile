# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 12:56:14 by mdiez-as          #+#    #+#              #
#    Updated: 2023/05/20 13:07:11 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAG	= -Wall -Wextra 

RM		= rm -f

AR		= ar

ARFLAGS	= crs

INCLUDES	= printf.h 

SRCS	=  ft_strlen.c			\
		  ft_putchar.c			\
		  ft_putstr.c			\
		  ft_putnbr.c			\
		  ft_print_pointer.c	\
		  ft_int_to_hex.c		\
		  ft_int_to_hexM.c		\
		  ft_printf.c			\
		  ft_putnbr_u.c			\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re