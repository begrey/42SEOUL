NAME		= Brain

SRCS		= ./main.cpp \
			  ./Animal.cpp \
			  ./Cat.cpp \
			  ./Dog.cpp \
			  ./Brain.cpp

OBJS		= $(SRCS:.c=.o)
RM			= rm -f
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) ${SRCS} -o ${NAME}

fclean : clean
	$(RM) $(NAME) $(bonus)

clean :
	$(RM) $(NAME)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o