# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 13:19:00 by tchoquet          #+#    #+#              #
#    Updated: 2023/03/02 15:30:52 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAMES 		=	ft_putchar.c	\
					ft_putstr.c		\
					ft_strcmp.c		\
					ft_strlen.c		\
					ft_swap.c

SRCS_DIR 		= srcs
INCLUDES_DIR 	= includes

SRCS			= ${foreach file, ${SRCS_NAMES}, ${SRCS_DIR}/${file}}
OBJS			= ${SRCS:.c=.o}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

.PHONY: all clean fclean re 

all: ${NAME}

${NAME}: ${OBJS}
	ar rc $@ $^
	ranlib $@

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<  -I ${INCLUDES_DIR}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all