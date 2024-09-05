NAME    = fdf
CC      = gcc -g
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -fPIE -Ilibft
LDFLAGS = -Llibft -L./minilibx-linux -lmlx -lXext -lX11 -lGL -lm -lft

SRCS    = test.c map.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -I./minilibx-linux -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all



