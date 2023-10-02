cmake_minimum_required(VERSION 3.22)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(42_libft)
include_directories(src)

add_executable(philosophers
        42_libft/ft_atoi.c
        42_libft/ft_bzero.c
        42_libft/ft_calloc.c
        42_libft/ft_isalnum.c
        42_libft/ft_isalpha.c
        42_libft/ft_isascii.c
        42_libft/ft_isdigit.c
        42_libft/ft_isprint.c
        42_libft/ft_itoa.c
        42_libft/ft_lstaddback.c
        42_libft/ft_memchr.c
        42_libft/ft_memcmp.c
        42_libft/ft_memcpy.c
        42_libft/ft_memmove.c
        42_libft/ft_memset.c
        42_libft/ft_putchar_fd.c
        42_libft/ft_putendl_fd.c
        42_libft/ft_putnbr_fd.c
        42_libft/ft_putstr_fd.c
        42_libft/ft_split.c
        42_libft/ft_strchr.c
        42_libft/ft_strdup.c
        42_libft/ft_striteri.c
        42_libft/ft_strjoin.c
        42_libft/ft_strlcat.c
        42_libft/ft_strlcpy.c
        42_libft/ft_strlen.c
        42_libft/ft_strmapi.c
        42_libft/ft_strncmp.c
        42_libft/ft_strnstr.c
        42_libft/ft_strrchr.c
        42_libft/ft_strtrim.c
        42_libft/ft_substr.c
        42_libft/ft_tolower.c
        42_libft/ft_toupper.c
        42_libft/libft.h
        src/main.c
        src/philo.h
        src/validation.c
        src/philo.c
        src/actions.c
        src/time.c
        src/big_brother.c
)
