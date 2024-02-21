CLIENTNAME	:= client

SERVERNAME	:= server

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= minitalk.h

LIB := ./libft/libftprintf.a

CLIENTDIR := ./

SERVERDIR := ./

CLIENTSRCS	:=  $(CLIENTDIR)client.c

SERVERSRCS	:=  $(SERVERDIR)server.c

CLIENTOBJS	:= ${CLIENTSRCS:.c=.o}

SERVEROBJS	:= ${SERVERSRCS:.c=.o}

CC		:= cc

all: $(CLIENTNAME) $(SERVERNAME)

$(LIB):
	make -C ./libft

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(CLIENTNAME): $(LIB) $(CLIENTOBJS)
	$(CC) $^ -o $@

$(SERVERNAME): $(LIB) $(SERVEROBJS)
	$(CC) $^ -o $@

clean:
	make -C ./libft clean
	rm -rf $(CLIENTOBJS) $(SERVEROBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(CLIENTNAME) $(SERVERNAME)

re: fclean all

.PHONY: all, clean, fclean, re