# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 19:57:41 by tchoquet          #+#    #+#              #
#    Updated: 2023/03/01 21:56:56 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAMES = 	ft_file_infos.c			\
				ft_file_open_close.c	\
				ft_file_read.c			\
				ft_map_fill.c			\
				ft_map_infos.c			\
				ft_map_memory.c			\
				ft_map_open_close.c		\
				ft_map_print.c			\
				ft_map_read.c			\
				ft_map_setup.c			\
				ft_map_solution.c		\
				ft_map_write.c			\
				ft_read_stdin.c			\
				ft_string_convert.c		\
				ft_string_create.c		\
				ft_string_infos.c		\
				ft_string_memory.c		\
				main.c					\

RACINE 			= .
SRCS_DIR 		= ${RACINE}
INCLUDES_DIR 	= ${RACINE}
BUILD_DIR		= ${RACINE}/build
PRODUCT_DIR		= ${RACINE}

SRCS			= ${foreach file, ${SRCS_NAMES}, ${SRCS_DIR}/${file}}
OBJS			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRCS:.c=.o}}

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

NAME			= bsq

.PHONY: all clean fclean re 

${NAME}: ${OBJS}
	${CC} -o $@ $^

${BUILD_DIR}/%.o: ${SRCS_DIR}/%.c | ${BUILD_DIR}
	${CC} -o $@ -c $< ${CFLAGS} -I ${INCLUDES_DIR}

${BUILD_DIR}:
	mkdir -p $@

all: ${NAME}

clean:
	rm -rf ${BUILD_DIR}

fclean:
	rm -rf ${NAME}

re: clean fclean all
	

