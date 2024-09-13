CC = gcc
CFLAGS = -Wall -Werror -std=c99
LFLAGS = -I include/. -I include/raylib/. -fPIC -L build/.
BUILD_MODE = 
TARGET_PLATFORM =

MAIN_RUN =
TEST_LIST_RUN =
TEST_STACK_RUN = 
TEST_QUEUE_RUN =

SANITIZE_COMMAND =

# Output File Extensions
SHARED_TARGET_EXT = 
MAIN_TARGET_EXT = 

# Source Files
MAIN_SRC   = src/main.c
GAME_SRC  = src/game.c
BRICK_SRC  = src/brick.c
BLOCK_SRC  = src/block.c
COMMON_SRC = src/common.c
QUEUE_SRC  = src/queue.c
STACK_SRC  = src/stack.c
LIST_SRC  = src/list.c

GAME_H  = include/game.h
BRICK_H  = include/brick.h
BLOCK_H  = include/block.h
COMMON_H = include/common.h
QUEUE_H  = include/queue.h
STACK_H  = include/stack.h
LIST_H  = include/list.h

# Test source
TEST_LIST_SRC = tests/test_list.c
TEST_STACK_SRC = tests/test_stack.c
TEST_QUEUE_SRC = tests/test_queue.c


# Linked libraries
MAIN_DEPS   = -llist -lqueue -lstack -lcommon -lgame -lblock -lbrick -lraylib
GAME_DEPS  = -llist -lqueue -lstack -lblock -lbrick -lraylib
BRICK_DEPS  = -llist -lqueue -lstack -lblock -lraylib
BLOCK_DEPS  = -llist -lqueue -lstack -lraylib
COMMON_DEPS = -lraylib



ifeq ($(OS),Windows_NT)
	TARGET_PLATFORM = windows
	SHARED_TARGET_EXT = dll
	MAIN_TARGET_EXT = exe
else
	TARGET_PLATFORM = linux
	SHARED_TARGET_EXT = so
	MAIN_TARGET_EXT = out
endif

ifeq ($(BUILD_MODE),DEBUG)
	CFLAGS += -ggdb
else
	CFLAGS += -O3 -s
endif

LFLAGS += -L lib/$(TARGET_PLATFORM)/.


MAIN_TARGET   = build/tetra-zen.$(MAIN_TARGET_EXT)
GAME_TARGET  = build/libgame.$(SHARED_TARGET_EXT)
BRICK_TARGET  = build/libbrick.$(SHARED_TARGET_EXT)
BLOCK_TARGET  = build/libblock.$(SHARED_TARGET_EXT)
COMMON_TARGET = build/libcommon.$(SHARED_TARGET_EXT)
QUEUE_TARGET  = build/libqueue.$(SHARED_TARGET_EXT)
STACK_TARGET  = build/libstack.$(SHARED_TARGET_EXT)
LIST_TARGET  = build/liblist.$(SHARED_TARGET_EXT)

TEST_LIST_TARGET = tests/bin/test_list.$(MAIN_TARGET_EXT)
TEST_STACK_TARGET = tests/bin/test_stack.$(MAIN_TARGET_EXT)
TEST_QUEUE_TARGET = tests/bin/test_queue.$(MAIN_TARGET_EXT)


ifeq ($(OS), Windows_NT)
	MAIN_RUN = $(MAIN_TARGET)
	TEST_LIST_RUN = $(TEST_LIST_TARGET)
	TEST_STACK_RUN = $(TEST_STACK_TARGET)
	TEST_QUEUE_RUN = $(TEST_QUEUE_TARGET)
else
	MAIN_RUN = LD_LIBRARY_PATH=build/. $(MAIN_TARGET)
	TEST_LIST_RUN = LD_LIBRARY_PATH=tests/bin/. $(TEST_LIST_TARGET)
	TEST_STACK_RUN = LD_LIBRARY_PATH=tests/bin/. $(TEST_STACK_TARGET)
	TEST_QUEUE_RUN = LD_LIBRARY_PATH=tests/bin/. $(TEST_QUEUE_TARGET)
endif



all: $(MAIN_TARGET)


$(MAIN_TARGET): $(MAIN_SRC) $(GAME_TARGET)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LFLAGS) $(MAIN_DEPS) -o $@
	@cp lib/$(TARGET_PLATFORM)/*.$(SHARED_TARGET_EXT)  build/.


$(GAME_TARGET): $(GAME_H) $(GAME_SRC) $(BRICK_TARGET)
	$(CC) $(CFLAGS) -shared $(GAME_SRC) $(LFLAGS) $(GAME_DEPS) -o $@


$(BRICK_TARGET): $(BRICK_H) $(BRICK_SRC) $(BLOCK_TARGET)
	$(CC) $(CFLAGS) -shared $(BRICK_SRC) $(LFLAGS) $(BRICK_DEPS) -o $@


$(BLOCK_TARGET): $(BLOCK_H) $(BLOCK_SRC) $(LIST_TARGET) $(QUEUE_TARGET) $(STACK_TARGET) $(COMMON_TARGET)
	$(CC) $(CFLAGS) -shared $(BLOCK_SRC) $(LFLAGS) $(BLOCK_DEPS) -o $@


$(COMMON_TARGET): $(COMMON_H) $(COMMON_SRC)
	$(CC) $(CFLAGS) -shared $(COMMON_SRC) $(LFLAGS) $(COMMON_DEPS) -o $@


$(QUEUE_TARGET): $(QUEUE_H) $(QUEUE_SRC)
	$(CC) $(CFLAGS) -shared $(QUEUE_SRC) $(LFLAGS) -o $@


$(STACK_TARGET): $(STACK_H) $(STACK_SRC)
	$(CC) $(CFLAGS) -shared $(STACK_SRC) $(LFLAGS) -o $@


$(LIST_TARGET): $(LIST_H) $(LIST_SRC)
	$(CC) $(CFLAGS) -shared $(LIST_SRC) $(LFLAGS) -o $@



run: $(MAIN_TARGET)
	$(MAIN_RUN)



test_list:
	@$(CC) $(CFLAGS) -I tests/lib/include/. $(LFLAGS) -L tests/bin/. $(TEST_LIST_SRC) $(LIST_SRC) -ltesting -o $(TEST_LIST_TARGET)
	@$(TEST_LIST_RUN)
	@rm $(TEST_LIST_TARGET)

test_stack:
	@$(CC) $(CFLAGS) -I tests/lib/include/. $(LFLAGS) -L tests/bin/. $(TEST_STACK_SRC) $(STACK_SRC) -ltesting -o $(TEST_STACK_TARGET)
	@$(TEST_STACK_RUN)
	@rm $(TEST_STACK_TARGET)

test_queue:
	@$(CC) $(CFLAGS) -I tests/lib/include/. $(LFLAGS) -L tests/bin/. $(TEST_QUEUE_SRC) $(QUEUE_SRC) -ltesting -o $(TEST_QUEUE_TARGET)
	@$(TEST_QUEUE_RUN)
	@rm $(TEST_QUEUE_TARGET)


test: test_list test_stack test_queue



clean:
	-rm build/*.$(SHARED_TARGET_EXT) build/*.$(MAIN_TARGET_EXT)
	clear || cls


