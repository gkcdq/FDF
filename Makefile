SRCS    = main.c ft_scale.c draw.c bresenham.c define.c map.c pixel_and_color.c color.c hook.c
OBJS    = $(SRCS:.c=.o)
NAME    = fdf
CC      = gcc -g
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -fPIC
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

LDFLAGS = -Llibft -L./minilibx-linux -lft -lmlx -lXext -lX11 -lGL -lm

INCLUDES = -Ilibft -I./minilibx-linux

all: minilibx-linux ${NAME} 

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

minilibx-linux:
	git clone https://github.com/42Paris/minilibx-linux.git $@

re: fclean all

valgrind: ${NAME}
	valgrind $(VALGRIND_FLAGS) ./${NAME}

.PHONY: all clean fclean re valgrind libft minilibx-linux
