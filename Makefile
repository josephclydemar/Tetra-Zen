CC=gcc
CC_CONFIG=-g -std=c99
CC_INCLUDE=-I include/. -I include/raylib/.
CC_LIB=-L lib/.
CC_FILTER_FLAG=-Wall -Werror

MAIN_SRC=src/main.c
MAIN_OUT=build/main.exe
MAIN_LIBS=-lllist -lqueue -lstack -lblock -lraylib


BLOCK_SRC=src/block.c
BLOCK_OUT=lib/libblock.dll
BLOCK_LIBS=-lllist -lqueue -lstack -lraylib


QUEUE_SRC=src\queue.c
QUEUE_OUT=lib\libqueue.dll

STACK_SRC=src\stack.c
STACK_OUT=lib\libstack.dll

LLIST_SRC=src\llist.c
LLIST_OUT=lib\libllist.dll


all: $(MAIN_SRC) libllist.dll libqueue.dll libstack.dll libblock.dll
	$(CC) $(CC_CONFIG) $(CC_FILTER_FLAG) $(MAIN_SRC) $(CC_INCLUDE) $(MAIN_LIBS) $(CC_LIB) -o $(MAIN_OUT)
	cp lib/* build/.
	$(MAIN_OUT)

libblock.dll: include/block.h $(BLOCK_SRC) libllist.dll libqueue.dll libstack.dll
	$(CC) $(CC_CONFIG) $(CC_FILTER_FLAG) -shared $(BLOCK_SRC) $(CC_INCLUDE) $(BLOCK_LIBS) $(CC_LIB) -o $(BLOCK_OUT)

libqueue.dll: include\queue.h $(QUEUE_SRC)
	$(CC) $(CC_CONFIG) $(CC_FILTER_FLAG) -shared $(QUEUE_SRC) $(CC_INCLUDE) -o $(QUEUE_OUT)

libstack.dll: include\stack.h $(STACK_SRC)
	$(CC) $(CC_CONFIG) $(CC_FILTER_FLAG) -shared $(STACK_SRC) $(CC_INCLUDE) -o $(STACK_OUT)

libllist.dll: include\llist.h $(LLIST_SRC)
	$(CC) $(CC_CONFIG) $(CC_FILTER_FLAG) -shared $(LLIST_SRC) $(CC_INCLUDE) -o $(LLIST_OUT)

clean:
	rm build/* || del build/*
	clear || cls
	tree /f
