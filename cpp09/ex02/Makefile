SRCS	=	main.cpp\
			PmergeMe.cpp\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	PmergeMe

CC		=	c++

CCFLAGS	=	-Wall -Wextra -Werror -O3 -std=c++98

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
