SRCS	=	main.cpp\
			BitcoinExchange.cpp\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	btc

CC		=	c++

CCFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: 	${NAME}

.cpp.o:
	${CC} ${CCFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
