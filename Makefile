CC=gcc
CFLAGS=-Wall -Werror -g -std=c99 -O3
LFLAGS=-I include/. -I include/raylib/.
CC_LIB=-L lib/.

# Source files
MAIN_SRC=src/main.c
BRICK_SRC=src/brick.c
BLOCK_SRC=src/block.c
ARENA_SRC=src/arena.c
QUEUE_SRC=src/queue.c
STACK_SRC=src/stack.c
LLIST_SRC=src/llist.c

BRICK_H=include/brick.h
BLOCK_H=include/block.h
ARENA_H=include/arena.h
QUEUE_H=include/queue.h
STACK_H=include/stack.h
LLIST_H=include/llist.h

# Linked libraries
MAIN_LIBS=-lllist -lqueue -lstack -larena -lblock -lbrick -lraylib
BRICK_LIBS=-lllist -lqueue -lstack -larena -lblock -lraylib
BLOCK_LIBS=-lllist -lqueue -lstack -larena -lraylib
ARENA_LIBS=-lllist -lqueue -lstack -lraylib

# Output files
MAIN_TARGET=build/main.exe
BRICK_TARGET=lib/libbrick.dll
BLOCK_TARGET=lib/libblock.dll
ARENA_TARGET=lib/libarena.dll
QUEUE_TARGET=lib/libqueue.dll
STACK_TARGET=lib/libstack.dll
LLIST_TARGET=lib/libllist.dll


all: $(MAIN_SRC) libarena.dll libblock.dll libbrick.dll
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LFLAGS) $(MAIN_LIBS) $(CC_LIB) -o $(MAIN_TARGET)
	cp lib/* build/.

libbrick.dll: $(BRICK_H) $(BRICK_SRC) libllist.dll libqueue.dll libstack.dll libarena.dll libblock.dll
	$(CC) $(CFLAGS) -shared $(BRICK_SRC) $(LFLAGS) $(BRICK_LIBS) $(CC_LIB) -o $(BRICK_TARGET)

libblock.dll: $(BLOCK_H) $(BLOCK_SRC) libllist.dll libqueue.dll libstack.dll libarena.dll
	$(CC) $(CFLAGS) -shared $(BLOCK_SRC) $(LFLAGS) $(BLOCK_LIBS) $(CC_LIB) -o $(BLOCK_TARGET)

libarena.dll: $(ARENA_H) $(ARENA_SRC) libllist.dll libqueue.dll libstack.dll
	$(CC) $(CFLAGS) -shared $(ARENA_SRC) $(LFLAGS) $(ARENA_LIBS) $(CC_LIB) -o $(ARENA_TARGET)

libqueue.dll: $(QUEUE_H) $(QUEUE_SRC)
	$(CC) $(CFLAGS) -shared $(QUEUE_SRC) $(LFLAGS) -o $(QUEUE_TARGET)

libstack.dll: $(STACK_H) $(STACK_SRC)
	$(CC) $(CFLAGS) -shared $(STACK_SRC) $(LFLAGS) -o $(STACK_TARGET)

libllist.dll: $(LLIST_H) $(LLIST_SRC)
	$(CC) $(CFLAGS) -shared $(LLIST_SRC) $(LFLAGS) -o $(LLIST_TARGET)

open: $(MAIN_TARGET)
	$(MAIN_TARGET)

clean:
	rm build/* || del build/*
	rm lib/lib*
	clear || cls
	tree /f

