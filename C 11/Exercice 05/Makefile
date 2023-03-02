# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 20:11:18 by tchoquet          #+#    #+#              #
#    Updated: 2023/03/02 22:23:13 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAMES = 	main.c		\
				ft_atoi.c	\
				ft_do_op.c	\
				ft_op.c		\
				ft_putnbr.c	\


OBJS			=  ${SRCS_NAMES:.c=.o}

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

NAME			= do-op

.PHONY: all clean fclean re 

${NAME}: ${OBJS}
	${CC} -o $@ $^

%.o: %.c 
	${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME}

re: clean fclean all