NAME	= libftprintf.a

SOURCES	= ft_printf.c \
adress.c \
characters.c \
hexa.c \
numbers.c \
string.c \
gnl/get_next_line.c \
gnl/get_next_line_utils.c \
error.c


OBJECTS	= ${SOURCES:.c=.o}

INCLUDES	= ./

CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= ./libft

LIBFT		= $(LIBFT_DIR)/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: ${OBJECTS} $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ ${OBJECTS}

$(LIBFT):
	make -C $(LIBFT_DIR)

all: ${NAME}

clean:
	rm -f ${OBJECTS}
	make clean -C $(LIBFT_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re