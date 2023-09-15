
.PHONY	= all clean fclean re

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FT		= ./42_libft/libft.a
SRCS	= main.c 
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}
	@clear
	

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${FT} -o $@
	

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${FT}

${OBJSDIR}/%.o: src/%.c src/philo.h
	${CC} ${CFLAGS} -c $< -o $@

${FT}: 
	@${MAKE} -C 42_libft

clean:
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf ${NAME} philo

re: fclean all
