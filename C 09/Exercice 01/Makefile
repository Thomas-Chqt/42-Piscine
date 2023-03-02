# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 13:19:00 by tchoquet          #+#    #+#              #
#    Updated: 2023/03/02 14:06:31 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAMES 		=	ft_putchar.c	\
					ft_putstr.c		\
					ft_strcmp.c		\
					ft_strlen.c		\
					ft_swap.c

RACINE 			= .
SRCS_DIR 		= ${RACINE}/srcs
INCLUDES_DIR 	= ${RACINE}/includes
BUILD_DIR		= ${SRCS_DIR}/srcs
PRODUCT_DIR		= ${RACINE}

SRCS			= ${foreach file, ${SRCS_NAMES}, ${SRCS_DIR}/${file}}
OBJS			= ${SRCS:.c=.o}

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

.PHONY: all clean fclean re 

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

${BUILD_DIR}/%.o: ${SRCS_DIR}/%.c
	${CC} -o $@ -c $< ${CFLAGS} -I ${INCLUDES_DIR}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all