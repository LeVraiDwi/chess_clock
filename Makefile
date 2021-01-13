SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_PATH = ./src

SRC_NAME =	 style.c button.c game.c\
		 main.c menu.c timer.c\
		 remove.c event.c util.c\

CFLAGS = -Wall -Wextra -Werror

GTK = `pkg-config --cflags --libs gtk+-3.0`

PTHREAD = `-lpthread -D_REENTRANT`

OBJS = ${SRCS:.c=.o}

NAME = chestclock.a

HEADER = -I "./include"

CC = clang

RM = rm -f

.c.o: 
			${CC} ${HEADER} -c $< -o $@ ${GTK}

${NAME}:	${OBJS}
		gcc -o ${NAME} ${HEADER} ${OBJS} ${GTK}

all:		${NAME}

clean:
			${RM} ${OBJS} ${LIBFT}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY =	all clean fclean re
