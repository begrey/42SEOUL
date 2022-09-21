NAME		= Account

SRCS		= ./Account.cpp \
			  ./tests.cpp

OBJS		= $(SRCS:.c=.o)
RM			= rm -f
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -lpthread $(CFLAGS) ${OBJS} -o ${NAME}

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) *.o

re : fclean all

.PHONY: all clean fclean re bonus .c.o    