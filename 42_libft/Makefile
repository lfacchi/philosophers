# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 15:39:45 by lucdos-s          #+#    #+#              #
#    Updated: 2022/05/03 21:58:14 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = libft.a

FILES = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
ft_isdigit.o ft_isprint.o ft_memset.o ft_strlen.o ft_tolower.o\
ft_toupper.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o\
ft_strchr.o ft_strrchr.o ft_memchr.o ft_memcmp.o ft_strnstr.o\
ft_strdup.o ft_calloc.o ft_strncmp.o ft_substr.o ft_strjoin.o\
ft_strtrim.o ft_strmapi.o ft_itoa.o ft_striteri.o ft_putchar_fd.o\
ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_split.o


all: $(NAME)
	
$(NAME) : $(FILES)
	@ar -rc libft.a $^

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $^
	
clean:
	@rm -f $(FILES)

fclean: clean
	@rm -f $(NAME)
re: fclean all
