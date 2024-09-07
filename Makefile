CC = gcc
CFLAGS = -Wall -Werror -std=c99
LFLAGS = -fPIC -I include/. -I include/raylib/. -L lib/.
BUILD_MODE = 
TARGET_PLATFORM =
RUN =
SANITIZE_COMMAND =

# Source files
MAIN_SRC   = src/main.c
BRICK_SRC  = src/brick.c
BLOCK_SRC  = src/block.c
ARENA_SRC  = src/arena.c
COMMON_SRC = src/common.c
QUEUE_SRC  = src/queue.c
STACK_SRC  = src/stack.c
LLIST_SRC  = src/llist.c

BRICK_H  = include/brick.h
BLOCK_H  = include/block.h
ARENA_H  = include/arena.h
COMMON_H = include/common.h
QUEUE_H  = include/queue.h
STACK_H  = include/stack.h
LLIST_H  = include/llist.h

# Linked libraries
MAIN_DEPS   = -lllist -lqueue -lstack -lcommon -larena -lblock -lbrick -lraylib
BRICK_DEPS  = -lllist -lqueue -lstack -lblock -lraylib
BLOCK_DEPS  = -lllist -lqueue -lstack -lraylib
ARENA_DEPS  = -lllist -lqueue -lstack -lraylib
COMMON_DEPS = -lraylib

# Output files
SHARED_TARGET_EXT = 
MAIN_TARGET_EXT = 

MAIN_TARGET   = build/tetra-zen
BRICK_TARGET  = lib/libbrick
BLOCK_TARGET  = lib/libblock
ARENA_TARGET  = lib/libarena
COMMON_TARGET = lib/libcommon
QUEUE_TARGET  = lib/libqueue
STACK_TARGET  = lib/libstack
LLIST_TARGET  = lib/libllist


ifeq ($(OS),Windows_NT)
	TARGET_PLATFORM = windows
	SHARED_TARGET_EXT = dll
	MAIN_TARGET_EXT = exe
	RUN = $(MAIN_TARGET).$(MAIN_TARGET_EXT)
else
	TARGET_PLATFORM = linux
	SHARED_TARGET_EXT = so
	MAIN_TARGET_EXT = out
	SANITIZE_COMMAND = mv build/libraylib.so build/libraylib.so.500
	RUN = LD_LIBRARY_PATH=build/. $(MAIN_TARGET).$(MAIN_TARGET_EXT)
endif


ifeq ($(BUILD_MODE),RELEASE)
	CFLAGS += -O3 -s
	ifeq ($(OS),Windows_NT)
		SANITIZE_COMMAND += strip $(MAIN_TARGET).$(MAIN_TARGET_EXT)
	else
		SANITIZE_COMMAND += && strip $(MAIN_TARGET).$(MAIN_TARGET_EXT)
	endif
else
	CFLAGS += -ggdb
endif


LFLAGS += -L lib/$(TARGET_PLATFORM)/.


all: $(MAIN_SRC) libarena.$(SHARED_TARGET_EXT) libcommon.$(SHARED_TARGET_EXT) libblock.$(SHARED_TARGET_EXT) libbrick.$(SHARED_TARGET_EXT)
	-@mkdir build
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LFLAGS) $(MAIN_DEPS) -o $(MAIN_TARGET).$(MAIN_TARGET_EXT)
	@cp lib/*.$(SHARED_TARGET_EXT) lib/$(TARGET_PLATFORM)/*.$(SHARED_TARGET_EXT)  build/.
	@$(SANITIZE_COMMAND)

libbrick.$(SHARED_TARGET_EXT): $(BRICK_H) $(BRICK_SRC) libllist.$(SHARED_TARGET_EXT) libqueue.$(SHARED_TARGET_EXT) libstack.$(SHARED_TARGET_EXT) libarena.$(SHARED_TARGET_EXT) libblock.$(SHARED_TARGET_EXT)
	$(CC) $(CFLAGS) -shared $(BRICK_SRC) $(LFLAGS) $(BRICK_DEPS) -o $(BRICK_TARGET).$(SHARED_TARGET_EXT)

libblock.$(SHARED_TARGET_EXT): $(BLOCK_H) $(BLOCK_SRC) libllist.$(SHARED_TARGET_EXT) libqueue.$(SHARED_TARGET_EXT) libstack.$(SHARED_TARGET_EXT) libarena.$(SHARED_TARGET_EXT)
	$(CC) $(CFLAGS) -shared $(BLOCK_SRC) $(LFLAGS) $(BLOCK_DEPS) -o $(BLOCK_TARGET).$(SHARED_TARGET_EXT)

libarena.$(SHARED_TARGET_EXT): $(ARENA_H) $(ARENA_SRC) libllist.$(SHARED_TARGET_EXT) libqueue.$(SHARED_TARGET_EXT) libstack.$(SHARED_TARGET_EXT)
	$(CC) $(CFLAGS) -shared $(ARENA_SRC) $(LFLAGS) $(ARENA_DEPS) -o $(ARENA_TARGET).$(SHARED_TARGET_EXT)

libcommon.$(SHARED_TARGET_EXT): $(COMMON_H) $(COMMON_SRC)
	$(CC) $(CFLAGS) -shared $(COMMON_SRC) $(LFLAGS) $(COMMON_DEPS) -o $(COMMON_TARGET).$(SHARED_TARGET_EXT)

libqueue.$(SHARED_TARGET_EXT): $(QUEUE_H) $(QUEUE_SRC)
	$(CC) $(CFLAGS) -shared $(QUEUE_SRC) $(LFLAGS) -o $(QUEUE_TARGET).$(SHARED_TARGET_EXT)

libstack.$(SHARED_TARGET_EXT): $(STACK_H) $(STACK_SRC)
	$(CC) $(CFLAGS) -shared $(STACK_SRC) $(LFLAGS) -o $(STACK_TARGET).$(SHARED_TARGET_EXT)

libllist.$(SHARED_TARGET_EXT): $(LLIST_H) $(LLIST_SRC)
	$(CC) $(CFLAGS) -shared $(LLIST_SRC) $(LFLAGS) -o $(LLIST_TARGET).$(SHARED_TARGET_EXT)

run: $(MAIN_TARGET).$(MAIN_TARGET_EXT)
	$(RUN)

clean:
	-rm -rf build || rmdir build
	-rm lib/lib*
	clear || cls


