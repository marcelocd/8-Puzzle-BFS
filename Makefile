# Makefile: Trabalho 1

CC = gcc
SRCS = main.c search.c 8puzzle.c vector.c linked_queue.c hash.c
OBJS = main.o search.o 8puzzle.o vector.o linked_queue.o hash.o
HEADERS = search.h 8puzzle.h vector.h linked_queue.h hash.h
APP_NAME = main

all:	$(APP_NAME)
$(APP_NAME):	$(OBJS)	$(HEADERS)
		$(CC) -o $(APP_NAME) $(OBJS)

objects:
		$(CC) -c $(SRCS)

clean:
		rm -f *.o $(APP_NAME)