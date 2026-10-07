CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -pedantic -O2
TARGET=pble2.exe
SRC=src/main.c src/input.c src/dijkstra.c src/display.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del /Q $(TARGET) 2>NUL || exit 0
