NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = main.c \
	   srcs/exit.c \
	   srcs/imgs.c \
	   srcs/init.c \
	   srcs/parsing/parser.c \
	   srcs/parsing/build_map.c \
	   srcs/parsing/check_map.c \
	   srcs/parsing/check_path.c
OBJS = ${SRCS:.c=.o}
LIB_DIR = libft/
LIB = $(LIB_DIR)/libft.a
MLX_DIR = mlx_linux/

all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(OBJS) -L$(LIB_DIR) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Building done!"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I/usr/include -Imlx_linux -c $< -o $@
	@echo "Compiling $< into object."

clean:
	@echo "Cleannig objects from $(NAME) folder..."
	@rm -rf $(OBJS)
	@make -C $(LIB_DIR) clean
	@echo "Cleanning done!"

fclean: clean
	@echo "Cleanning $(NAME)"
	@rm -rf $(NAME)
	@rm -rf $(LIB)
	@make -C $(MLX_DIR) clean
	@echo "Cleanning done"


re: fclean all

.PHONY: all clean fclean re
