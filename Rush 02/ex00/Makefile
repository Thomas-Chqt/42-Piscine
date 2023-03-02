# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 19:57:41 by tchoquet          #+#    #+#              #
#    Updated: 2023/02/26 23:00:25 by mayyamad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAMES = 	main.c				\
				ft_commande_line.c	\
				ft_file_infos.c		\
				ft_files_edit.c		\
				ft_get_entry.c		\
				ft_mem.c			\
				ft_open_close.c		\
				ft_parse.c			\
				ft_read_file.c		\
				ft_string_create.c	\
				ft_string_edit.c	\
				ft_string_infos.c	\
				convert_num2.c		\
				convert_num.c

RACINE 			= .
SRCS_DIR 		= ${RACINE}
INCLUDES_DIR 	= ${RACINE}
BUILD_DIR		= ${RACINE}/build
PRODUCT_DIR		= ${RACINE}

SRCS			= ${foreach file, ${SRCS_NAMES}, ${SRCS_DIR}/${file}}
OBJS			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRCS:.c=.o}}

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

NAME			= rush-02

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
	

