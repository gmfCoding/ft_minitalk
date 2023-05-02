INC = common.h

CSRCS = common.c
P1SRCS = client.c
P2SRCS = server.c

COBJS = $(CSRCS:.c=.o)
P1OBJS = $(P1SRCS:.c=.o)
P2OBJS = $(P2SRCS:.c=.o)

P1NAME = client
P2NAME = server

CFLAGS = -g
#-Wall -Werror -Wextra
CC = cc

all: $(P1NAME) $(P2NAME)


$(P1NAME): $(P1OBJS) $(COBJS)
	$(CC) $(P1OBJS) $(COBJS) $(CFLAGS) -o $(P1NAME)

$(P2NAME): $(P2OBJS) $(COBJS)
	$(CC) $(P2OBJS) $(COBJS) $(CFLAGS) -o $(P2NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<  
