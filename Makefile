CLIENTNAME	:= client

SERVERNAME	:= server

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -I ./

LIB := ./libft/libftprintf.a

CLIENTDIR := ./

SERVERDIR := ./

CLIENTSRCS	:=  $(CLIENTDIR)client.c

SERVERSRCS	:=  $(SERVERDIR)server.c

CLIENTOBJS	:= ${CLIENTSRCS:.c=.o}

SERVEROBJS	:= ${SERVERSRCS:.c=.o}

CC		:= cc

all: lib $(CLIENTNAME) $(SERVERNAME)

lib:
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

$(CLIENTNAME): $(CLIENTOBJS)
	$(CC) $(CLIENTOBJS) $(LIB) $(HEADERS) -o $@

$(SERVERNAME): $(SERVEROBJS)
	$(CC) $(SERVEROBJS) $(LIB) $(HEADERS) -o $@

clean:
	make -C ./libft clean
	rm -rf $(CLIENTOBJS) $(SERVEROBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(CLIENTNAME) $(SERVERNAME)

re: fclean all

.PHONY: all, clean, fclean, re, lib