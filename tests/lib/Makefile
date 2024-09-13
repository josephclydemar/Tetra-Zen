CC = gcc
CFLAGS = -Wall -Werror -std=c99 -s -O3
LFLAGS = -I include/. -fPIC

TARGET_EXT =


ifeq ($(OS),Windows_NT)
	TARGET_EXT = dll
else
	TARGET_EXT = so
endif

SRC = src/testing.c
TARGET = ../bin/libtesting.$(TARGET_EXT)

all:
	$(CC) $(CFLAGS) $(LFLAGS) -shared $(SRC) -o $(TARGET)


clean:
	-rm ../bin/*.$(TARGET_EXT)
