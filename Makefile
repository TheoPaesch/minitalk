CLIENTNAME	:= client

SERVERNAME	:= server

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -I ./minitalk.h

LIB := ./libft/libftprintf.a

CLIENTDIR := ./

SERVERDIR := ./

CLIENTSRCS	:=  $(CLIENTDIR)client.c

SERVERSRCS	:=  $(SERVERDIR)server.c

CLIENTOBJS	:= ${CLIENTSRCS:.c=.o}

SERVEROBJS	:= ${SERVERSRCS:.c=.o}

CC		:= cc

all: $(CLIENTNAME) $(SERVERNAME)

lib:
	make -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(CLIENTNAME): $(CLIENTOBJS) lib
	@$(CC) $(CLIENTOBJS) $(LIB) $(HEADERS) -o $(CLIENTNAME)

$(SERVERNAME): $(SERVEROBJS) lib
	@$(CC) $(SERVEROBJS) $(LIB) $(HEADERS) -o $(SERVERNAME)

clean:
	make -C ./libft clean
	rm -rf $(CLIENTOBJS) $(SERVEROBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(CLIENTNAME) $(SERVERNAME)

re: clean all

.PHONY: all, clean, fclean, re, lib