INC = common.h

CSRCS = common.c
P1SRCS = client.c
P2SRCS = server.c

COBJS = $(CSRCS:.c=.o)
P1OBJS = $(P1SRCS:.c=.o)
P2OBJS = $(P2SRCS:.c=.o)

P1NAME = client
P2NAME = server

LIBFTALL = libftall/libftall.a

LFLAGS = -Llibftall -lftall
CFLAGS = -I./ -I./libftall $(DFLAGS) -Wall -Werror -Wextra
CC = cc

all: $(P1NAME) $(P2NAME)

$(LIBFTALL):
	make -s -C libftall

bonus: all
	echo "bonus included!"

$(P1NAME): $(P1OBJS) $(COBJS)
	$(CC) $(LFLAGS) $(P1OBJS) $(COBJS) $(CFLAGS) -o $(P1NAME)

$(P2NAME): $(P2OBJS) $(COBJS)
	$(CC) $(LFLAGS) $(P2OBJS) $(COBJS) $(CFLAGS) -o $(P2NAME)

%.o: %.c $(INC) $(LIBFTALL)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(COBS)
	make -s -C libftall clean

fclean: clean
	make -s -C libftall fclean
	rm -f client
	rm -f server

.PHONY: clean all re fclean bonus
