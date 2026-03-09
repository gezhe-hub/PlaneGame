CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
TARGET = bin/plane_game

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

obj/%.o: src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/*bin/*

