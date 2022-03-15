NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar -rcs
RM = rm -f

INCLUDE = ft_printf.h

SOURCES = ft_printf.c ft_printf_hex.c
OBJECTS = $(SOURCES.c=.o)

all: $(NAME)

clean:
	$(RM)	$(OBJECTS)

flcean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: all clean fclean re