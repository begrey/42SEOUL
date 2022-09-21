MMS = libmlx.dylib
NAME = cub3D

SRCS		= ./srcs/init.c \
			  ./srcs/parse_check.c \
			  ./srcs/parse_color.c \
			  ./srcs/parse_element.c \
			  ./srcs/parse_map.c \
			  ./srcs/parse.c \
			  ./srcs/ray.c \
			  ./srcs/sprite.c \
			  ./srcs/sprite_2.c \
			  ./srcs/utils.c \
			  ./srcs/utils_2.c \
			  ./srcs/wall.c \
			  ./srcs/bit_map.c \
			  ./srcs/get_next_line.c \
			  ./srcs/get_next_line_utils.c \
			  ./srcs/key_handle.c \
			  ./srcs/main.c \
			
OBJS		= $(SRCS:.c=.o)			
OPTION		= -L ../mlx -lmlx -framework OpenGL -framework AppKit
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

${NAME} : $(OBJS)
	make all -C ../mlx
	make all -C ../mlx_mms
	cp ../mlx_mms/${MMS} ./
	$(CC) $(CFLAGS) ${OPTION} ${SRCS} ${MMS} -o ${NAME}

all: ${NAME}

clean	:
	rm -f $(OBJS)
	make clean -C  ../mlx_mms
	make clean -C  ../mlx

fclean	: clean
	rm -f $(NAME) $(MMS)

re		: fclean all 

.PHONY: all clean fclean re bonus .c.o
