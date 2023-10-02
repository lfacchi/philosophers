
.PHONY	= all clean fclean re

NAME	= philo
CC		= clang
CFLAGS	= -g3
FT		= ./42_libft/libft.a
SRCS	= main.c philo.c validation.c time.c actions.c big_brother.c finish.c
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${FT} -o $@ -pthread
	

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${FT}

${OBJSDIR}/%.o: src/%.c src/philo.h
	${CC} ${CFLAGS} -c $< -o $@ -pthread

${FT}: 
	@${MAKE} -C 42_libft

clean:
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all
