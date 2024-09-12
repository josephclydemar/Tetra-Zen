CC = gcc
CFLAGS = -Wall -Werror -std=c99 -s -O3
LFLAGS = -I include/. -fPIC

SHARED_TARGET_EXT =
MAIN_TARGET_EXT =

SRC = src/testing.c
TARGET = ../bin/libtesting

ifeq ($(OS),Windows_NT)
	SHARED_TARGET_EXT = dll
	MAIN_TARGET_EXT = exe
else
	SHARED_TARGET_EXT = so
	MAIN_TARGET_EXT = out
endif


all:
	$(CC) $(CFLAGS) $(LFLAGS) -shared $(SRC) -o $(TARGET).$(SHARED_TARGET_EXT)


clean:
	-rm ../bin/*.$(SHARED_TARGET_EXT) ../bin/*.$(MAIN_TARGET_EXT)
