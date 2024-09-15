# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharraqi <nharraqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 15:59:26 by nharraqi          #+#    #+#              #
#    Updated: 2024/09/13 22:30:33 by nharraqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c map.c draw.c bresenham.c ft_scale.c pixel_and_color.c define.c
OBJS    = $(SRCS:.c=.o)
NAME    = fdf
CC      = gcc -g
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -fPIC
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

LDFLAGS = -Llibft -L./minilibx-linux -lft -lmlx -lXext -lX11 -lGL -lm

INCLUDES = -Ilibft -I./minilibx-linux

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}
	@make -C libft
	@make -C minilibx-linux
	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

valgrind: ${NAME}
	valgrind $(VALGRIND_FLAGS) ./${NAME}

.PHONY: all clean fclean re valgrind libft minilibx-linux