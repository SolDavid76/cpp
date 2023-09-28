SRCS	=	main.cpp\
			Zombie.cpp\
			zombieHorde.cpp\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	Zombie

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: 	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
